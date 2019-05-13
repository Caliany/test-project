//�ھŴ���ҵ---ɨ����Ϸ
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int Menu(){
	printf("---------------------------------------\n");
	printf("--------     ��ӭ����ɨ����Ϸ   -------\n");
	printf("--------      1.��ʼ��Ϸ        -------\n");
	printf("--------      0.�˳���Ϸ        -------\n");
	printf("---------------------------------------\n");
	printf("����������ѡ��:");
	int choic = 0;
	scanf("%d", &choic);
	return choic;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_ROW]){
	//1.����show_map,��Ҫ����Ϊ*
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			map[row][col] = '*';
		}
	}
	//2.����mine_map����Ҫ�������ɸ����ף�ʹ��0 ��ʾ���ǵ��ף� 1 ��ʾ�ǵ���
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			mine_map[row][col] = '0';//�˴�������0Ҳ����

		}
	}
	int n = MINE_COUNT;
	while (n > 0){
		//����һ���������
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1'){
			//��λ�����ǵ��ף���Ҫ�������ɣ�
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}

void PrintMap(char map[MAX_ROW][MAX_COL]){
	//�ȴ�ӡ��һ��
	printf("   ");
	for (int col = 0; col < MAX_COL;++col){
		printf("%d ", col);
	}
	printf("\n");
	//��ӡһ���ָ���
	for (int col = 0; col < MAX_COL-2; ++col){
		printf("---");
	}
	printf("\n");
	//�ٴ�ӡ������
	
	for (int row = 0; row < MAX_ROW; ++row){
		printf("%d| ", row);
		//��ӡ���е�ÿһ��
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void UpdateShowmap(int row,int col,
		char show_map[MAX_ROW][MAX_COL],
		char mine_map[MAX_ROW][MAX_COL]){
	//���ݵ�ǰλ�����ж����λ����Χ8�������м������ף�
	//����������ָ��µ�show_map��
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0
		&& row - 1 < MAX_ROW && col - 1 < MAX_COL
		&&mine_map[row - 1][col - 1] == '1'){
		++count;
	}
	if (row - 1 >= 0 && col >= 0
		&& row - 1 < MAX_ROW && col < MAX_COL
		&&mine_map[row - 1][col] == '1'){
		++count;
	}
	if (row - 1 >= 0 && col + 1 >= 0
		&& row - 1 < MAX_ROW && col + 1 < MAX_COL
		&&mine_map[row - 1][col + 1] == '1'){
		++count;
	}
	if (row >= 0 && col - 1 >= 0
		&& row < MAX_ROW && col - 1 < MAX_COL
		&&mine_map[row][col - 1] == '1'){
		++count;
	}
	if (row  >= 0 && col + 1 >= 0
		&& row < MAX_ROW && col + 1 < MAX_COL
		&&mine_map[row][col + 1] == '1'){
		++count;
	}
	if (row + 1 >= 0 && col - 1 >= 0
		&& row + 1 < MAX_ROW && col - 1 < MAX_COL
		&&mine_map[row + 1][col - 1] == '1'){
		++count;
	}
	if (row + 1 >= 0 && col >= 0
		&& row + 1 < MAX_ROW && col < MAX_COL
		&&mine_map[row + 1][col] == '1'){
		++count;
	}
	if (row + 1 >= 0 && col + 1 >= 0
		&& row +1 < MAX_ROW && col + 1 < MAX_COL
		&&mine_map[row + 1][col + 1] == '1'){
		++count;
	}
	//�õ�����Χ�İ˸������е��׵ĸ���
	show_map[row][col] = '0' + count;//����countΪ2��ʵ�ʿ����Ľ����2+ascii���ж�Ӧ��50
}
void Game(){
	//�ȴ�����ͼ������ʼ��
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//�Ѿ������Ŀո�ĸ���(�ǵ���)
	int blank_mine_count_already_show = 0;
	Init(show_map, mine_map);
	//2.��ӡ��ͼ
	while (1){
	PrintMap(show_map);
	PrintMap(mine_map);//�����ӡ��Ϊ�˵�����ʱ�ӵġ�Ҫ�ǵ�ɾ����

	//3.���û��������겢���кϷ��Լ��
	printf("������һ������:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//����
		system("cls");//�������֮ǰ��
		//�Ϸ��Լ��
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COL){
			printf("��������Ƿ������������룡\n");
			continue;
	}
	if (show_map[row][col] != '*'){
		printf("�������λ���Ѿ��������ˣ�\n");
	}
	//4.�ж��Ƿ��ǵ���
	if(mine_map[row][col] == '1'){
		printf("��Ϸ����!\n");
		PrintMap(mine_map);
			break;
	}
	//5.�ж���Ϸ�Ƿ�ʤ��
	//�ж����еķǵ���λ�ö��ѱ�������
	++blank_mine_count_already_show;
	if (blank_mine_count_already_show == MAX_ROW * MAX_COL - MINE_COUNT){
		printf("��Ϸʤ����\n");
		PrintMap(mine_map);
		break;
	}
	//6.ͳ�Ƶ�ǰλ���׵ĸ���
	UpdateShowmap(row,col,show_map,mine_map);
 }
}

int main(){
	while (1){
		int choic = Menu();
		if (choic == 1){
			Game();
		}
		else if (choic == 0){
			printf("Goodbye!\n");
			break;
		}
		else{
			printf("������������!\n");
		}
	}
	system("pause");
	return 0;
}