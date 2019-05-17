//1.完成猜数字游戏。
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
		printf("请输入你要猜的数字（1 - 100）： > ");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//强制转换一下time(只调用一次就好)
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,重新选择\n");
			break;
		}
	} while (0);
	system("pause");
	return 0;
}

//2.编写代码模拟三次密码输入的场景。最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码：>");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)//string compare 
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("密码错误，请重新输入！\n");
		}
	}
	if (i == 3)
		printf("三次密码都错，退出程序\n");
	system("pause");
	return 0;
}
//3.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
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
//4.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
#include<stdio.h>
#include<stdlib.h>
void mul(int x)
{
	int i = 0, j = 0;
	for (i = 1; i <= x; i++)//控制行x表示行数；
	{
		for (j = 1; j <= i; j++)//控制列
		{
			//printf("%d*%d=%2d\t", i, j, i*j);// %2d至少为2的宽度打印出来，用于右对齐；%02d用0补空位；%-d左对齐；%-6.2lf精度
			printf("%d*%d=%d\t", i, j, i*j);//sprintf打印
		}
		printf("\n");
	}
}
int main()
{
	int a = 0;
	printf("请输入你想要的乘法表数:>\n");
	scanf("%d", &a);//scanf加宽度：最多....
	mul(a);//调用mul的函数
	system("pause");
	return 0;
}
//5.使用函数实现两个数的交换。 （跨栈操作）
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

//6.实现一个函数判断year是不是闰年。
#include<stdio.h>
#include<stdlib.h>
//leap_year 
// LEAP_YEAR

int leap_year(int year)
{
	return(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 1 : 0;//润年须要被4，100，400整除
	//(单判断可以)
}
int main()
{
	int year = 0;
	int ret = 0;
	printf("请输入年份：>");
	scanf("%4d", &year);//只要前四个，避免越界
	ret = leap_year(year);
	if (ret)
	{
		printf("是闰年");
	}
	else
	{
		printf("不是闰年");
	}
	printf("\n");
	system("pause");
	return 0;
}

//7.实现一个函数，判断一个数是不是素数。
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
	printf("请任意输入一个数字:");
	scanf("%d", &num);
	flag = Judge(num);
	if (flag == 0)
	{
		printf("是素数\n");
	}
	if (flag == 1)
	{
		printf("不是素数\n");
	}
	system("pause");
	return 0;
}

//8. 创建一个数组，实现函数init（）初始化数组、实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。要求：自己设计函数的参数，返回值
#include<stdio.h>
#include<stdlib.h>

void init(int arr[], int len)//初始化数组（arr[] == *arr,前者较好表示数组类型）
{
	int i = 0;
	int num = 0;
	printf("初始化数组，请输入5个数:\n");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &num);
		arr[i] = num;
	}
}

void empty(int arr[], int len) //清空数组
{
	int i = 0;
	printf("清空后的数组：\n");
	for (i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}

void reverse(int arr[], int len)
{
	int i = 0;
	int arr2[20];
	printf("逆置后的数组：\n");
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
	int len = sizeof(arr) / sizeof(arr[0]);//计算数组的长度的公式
	init(arr, len);//指针变量，万物皆指针...init也是一指针
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