//第九次作业---扫雷游戏
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int Menu(){
	printf("---------------------------------------\n");
	printf("--------     欢迎来到扫雷游戏   -------\n");
	printf("--------      1.开始游戏        -------\n");
	printf("--------      0.退出游戏        -------\n");
	printf("---------------------------------------\n");
	printf("请输入您的选择:");
	int choic = 0;
	scanf("%d", &choic);
	return choic;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_ROW]){
	//1.对于show_map,需要都设为*
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			map[row][col] = '*';
		}
	}
	//2.对于mine_map，需要生成若干个地雷，使用0 表示不是地雷， 1 表示是地雷
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			mine_map[row][col] = '0';//此处用数字0也可以

		}
	}
	int n = MINE_COUNT;
	while (n > 0){
		//生成一组随机坐标
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1'){
			//该位置已是地雷，需要重新生成；
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}

void PrintMap(char map[MAX_ROW][MAX_COL]){
	//先打印第一行
	printf("   ");
	for (int col = 0; col < MAX_COL;++col){
		printf("%d ", col);
	}
	printf("\n");
	//打印一个分割线
	for (int col = 0; col < MAX_COL-2; ++col){
		printf("---");
	}
	printf("\n");
	//再打印其它行
	
	for (int row = 0; row < MAX_ROW; ++row){
		printf("%d| ", row);
		//打印本行的每一列
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void UpdateShowmap(int row,int col,
		char show_map[MAX_ROW][MAX_COL],
		char mine_map[MAX_ROW][MAX_COL]){
	//根据当前位置来判定这个位置周围8个格子有几个地雷，
	//并且这个数字更新到show_map中
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
	//得到了周围的八个格子中地雷的个数
	show_map[row][col] = '0' + count;//假设count为2，实际看到的结果是2+ascii表中对应的50
}
void Game(){
	//先创建地图，并初始化
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	//已经翻开的空格的个数(非地雷)
	int blank_mine_count_already_show = 0;
	Init(show_map, mine_map);
	//2.打印地图
	while (1){
	PrintMap(show_map);
	PrintMap(mine_map);//这个打印是为了调试临时加的【要记得删掉】

	//3.让用户输入坐标并进行合法性检测
	printf("请输入一组坐标:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//清屏
		system("cls");//清除坐标之前的
		//合法性检测
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COL){
			printf("您的输入非法！请重新输入！\n");
			continue;
	}
	if (show_map[row][col] != '*'){
		printf("您输入的位置已经被翻开了！\n");
	}
	//4.判定是否是地雷
	if(mine_map[row][col] == '1'){
		printf("游戏结束!\n");
		PrintMap(mine_map);
			break;
	}
	//5.判定游戏是否胜利
	//判定所有的非地雷位置都已被翻开了
	++blank_mine_count_already_show;
	if (blank_mine_count_already_show == MAX_ROW * MAX_COL - MINE_COUNT){
		printf("游戏胜利！\n");
		PrintMap(mine_map);
		break;
	}
	//6.统计当前位置雷的个数
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
			printf("您的输入有误!\n");
		}
	}
	system("pause");
	return 0;
}