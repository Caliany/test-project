//1.��ɲ�������Ϸ��
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void menu()
{
	printf("*****************************\n");
	printf("******       1.play    ******\n");
	printf("******       2.exit    ******\n");
	printf("*****************************\n");
}
void game()
{
	int ret = 0;
	ret = rand() % 100 + 1;
	int guess = 0;
	while (1)
	{
		printf("��������Ҫ�µ����֣�1 - 100���� > ");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ǿ��ת��һ��time(ֻ����һ�ξͺ�)
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,����ѡ��\n");
			break;
		}
	} while (0);
	system("pause");
	return 0;
}

//2.��д����ģ��������������ĳ���������������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("���������룺>");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)//string compare 
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
	if (i == 3)
		printf("�������붼���˳�����\n");
	system("pause");
	return 0;
}
//3.��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			putchar(ch - 32);
		}
		else if (ch >= 'A' && ch <= 'z')
		{
			putchar(ch + 32);
		}
		else if (ch >= '0' && ch <= '9')
		{
			;
		}
		else
		{
			putchar(ch);
		}
	}
	system("pause");
	return 0;
}
//4.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
#include<stdio.h>
#include<stdlib.h>
void mul(int x)
{
	int i = 0, j = 0;
	for (i = 1; i <= x; i++)//������x��ʾ������
	{
		for (j = 1; j <= i; j++)//������
		{
			//printf("%d*%d=%2d\t", i, j, i*j);// %2d����Ϊ2�Ŀ�ȴ�ӡ�����������Ҷ��룻%02d��0����λ��%-d����룻%-6.2lf����
			printf("%d*%d=%d\t", i, j, i*j);//sprintf��ӡ
		}
		printf("\n");
	}
}
int main()
{
	int a = 0;
	printf("����������Ҫ�ĳ˷�����:>\n");
	scanf("%d", &a);//scanf�ӿ�ȣ����....
	mul(a);//����mul�ĺ���
	system("pause");
	return 0;
}
//5.ʹ�ú���ʵ���������Ľ����� ����ջ������
#include<stdio.h>
#include<stdlib.h>

void Swap1(int x, int y)
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}
void Swap2(int *px, int *py)
{
	int tmp = 0;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
int main()
{
	int a = 2;
	int b = 4;
	Swap1(a, b);
	printf("Swap1:a=%d b=%d\n", a, b);
	Swap2(&a, &b);
	printf("Swap2:a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}

//6.ʵ��һ�������ж�year�ǲ������ꡣ
#include<stdio.h>
#include<stdlib.h>
//leap_year 
// LEAP_YEAR

int leap_year(int year)
{
	return(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 1 : 0;//������Ҫ��4��100��400����
	//(���жϿ���)
}
int main()
{
	int year = 0;
	int ret = 0;
	printf("��������ݣ�>");
	scanf("%4d", &year);//ֻҪǰ�ĸ�������Խ��
	ret = leap_year(year);
	if (ret)
	{
		printf("������");
	}
	else
	{
		printf("��������");
	}
	printf("\n");
	system("pause");
	return 0;
}

//7.ʵ��һ���������ж�һ�����ǲ���������
#include<stdio.h>
#include<stdlib.h>

int  Judge(int num)
{
	int flag = 0;
	int i;
	for (i = 2; i < num; ++i)
	{
		if (num%i == 0)
		{
			return flag;
		}
	}
	return flag;
}
int main()
{
	int num, flag;
	printf("����������һ������:");
	scanf("%d", &num);
	flag = Judge(num);
	if (flag == 0)
	{
		printf("������\n");
	}
	if (flag == 1)
	{
		printf("��������\n");
	}
	system("pause");
	return 0;
}

//8. ����һ�����飬ʵ�ֺ���init������ʼ�����顢ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�Ҫ���Լ���ƺ����Ĳ���������ֵ
#include<stdio.h>
#include<stdlib.h>

void init(int arr[], int len)//��ʼ�����飨arr[] == *arr,ǰ�߽Ϻñ�ʾ�������ͣ�
{
	int i = 0;
	int num = 0;
	printf("��ʼ�����飬������5����:\n");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &num);
		arr[i] = num;
	}
}

void empty(int arr[], int len) //�������
{
	int i = 0;
	printf("��պ�����飺\n");
	for (i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}

void reverse(int arr[], int len)
{
	int i = 0;
	int arr2[20];
	printf("���ú�����飺\n");
	for (i = 0; i < len; i++)
	{
		arr2[i] = arr[i];
	}
	for (i = 0; i < len; i++)
	{
		arr[i] = arr2[len - 1 - i];
	}
}
int main()
{
	int i = 0;
	int arr[5] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);//��������ĳ��ȵĹ�ʽ
	init(arr, len);//ָ������������ָ��...initҲ��һָ��
	reverse(arr, len);
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	empty(arr, len);
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}