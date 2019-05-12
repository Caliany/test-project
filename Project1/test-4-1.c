#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//第六次作业
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
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
int main0()
{
	int a = 0;
	printf("请输入你想要的乘法表数:>\n");
	scanf("%d", &a);//scanf加宽度：最多....
	mul(a);//调用mul的函数
	system("pause");
	return 0;
}

//2.使用函数实现两个数的交换。 （跨栈操作）
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
int main1()
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

//3.实现一个函数判断year是不是闰年。
#include<stdio.h>
#include<stdlib.h>
//leap_year 
// LEAP_YEAR

int leap_year(int year)
{
	return(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 1: 0;//润年须要被4，100，400整除
	//(单判断可以)
}
int main2()
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

//5.实现一个函数，判断一个数是不是素数。
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
int main3()
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

//4. 创建一个数组，实现函数init（）初始化数组、实现empty（）清空数组、
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
	for (i = 0; i < len ; i++)
	{
		arr2[i] = arr[i];
	}
	for (i = 0; i < len; i++)
	{
		arr[i] = arr2[len - 1 - i];
	}
}
int main4()
{
	int i = 0;
	int arr[5] = {0};
	int len = sizeof(arr) / sizeof(arr[0]);//计算数组的长度的公式
	init(arr, len);//指针变量，万物皆指针...init也是一指针
	reverse(arr, len);
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	empty(arr, len);
	for (i = 0; i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


//第七次作业
//1.递归和非递归分别实现求第n个斐波那契数。 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main0()     //非递归实现
{
	int n = 0;
	int a = 1;
	int b = 1;
	int c = a;
	printf("请输入要求的第n个斐波那契数n=");
	scanf("%d", &n);
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	printf("%d\n",c);
	system("pause");
	return 0;
}
//
//for (i = 2; i <= n; i++)
//{
//	an = an_1 + an_2;
//	an_2 = an_1;
//	an_1 = an;
//}
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int fib(int n)   
	{
		if (n <= 2)
			return 1; //1 1 2 3 5 8 13 21 34 55.... 前两个数为1，所以小于等于2时返回为1
		else
			return fib(n - 1) + fib(n - 2); //递归实现(数1的过程，效率低，写循环吧！)；循环层数不确定时，写递归
	}
int main()
{
		int n = 0;
		printf("请输入要求的第n个斐波那契数n=");
		scanf("%d", &n);
		int ret = fib(n);
		printf("%d\n",ret);
		system("pause");
		return  0;
}

//2.编写一个函数实现n^k，使用递归实现 
#include<stdio.h>
#include<stdlib.h>
int del(int n, int k, int ant)
{
	if (n != 1)
	{
		return del(n - 1, k, ant*k);
	}
	else
		return ant*k;
}

int main()
{
	int num = 0;
	int n = 0;
	int k = 0;
	int tmp = 1;
	printf("n和k的值分别为：");
	scanf_s("%d%d", &n, &k);
	num = del(k, n, tmp);
	printf("%d", num);
	system("pause");
	return 0;
}

3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n)
{
	if (n > 0)
	{
		return (n % 10) + DigitSum(n / 10);
	}
	return 0;
}
int main()
{
	int n = 0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));
	system("pause");
	return 0;
}
4. 编写一个函数 reverse_string(char * string)（递归实现）
   实现：将参数字符串中的字符反向排列。
   要求：不能使用C函数库中的字符串操作函数。
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *reverse_string(char *str)
{
	assert(str != NULL);
	if (*str != 0)
	{
		str++;
		reverse_string(str);
		printf("%c ", *(str - 1));

	}
	return str;
}

int main()
{
	char arr[] = "abcdefd";
	char *ret = reverse_string(arr);
	system("pause");
	return 0;
}


5.递归和非递归分别实现strlen
#include<stdio.h>
#include<stdlib.h>

int my_strlen(const char *str)//递归法实现
{
	if ( 0 == *str)
		return 0;
	else
		return 1 + my_strlen(str + 1);

}
int main()
{
	const char *p = "abcdefd";
	int len = my_strlen(p);
	printf("%d\n", len);
	system("pause");
	return 0;
}

//6.递归和非递归分别实现求n的阶乘 
#include<stdio.h>
#include<stdlib.h>

int fac(int n)//非递归法实现
{
	int i = 0;
	int tmp = 1;
	for (i = 1; i <= n; i++)
	{
		tmp *= i;
	}
	return tmp;
}
int main()
{
	int n = 0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	int fac(n);
	printf("%d\n", fac(n));
	system("pause");
	return 0;
}

int fac(int n)  //递归法实现
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n*fac(n - 1);
	}
}
int main()
{
	int n = 0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	int fac(n);
	printf("%d\n", fac(n));
	system("pause");
	return 0;
}

//7.递归方式实现打印一个整数的每一位
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void print(int n)
{
	if (n >9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int num;
	scanf("%d", &num);
	print(num);
	system("pause");
	return 0;
}
#endif
