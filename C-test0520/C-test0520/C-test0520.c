//1.递归和非递归分别实现求第n个斐波那契数。 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main()     //非递归实现
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
	printf("%d\n", c);
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
	printf("%d\n", ret);
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

//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
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
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
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


//5.递归和非递归分别实现strlen
#include<stdio.h>
#include<stdlib.h>

int my_strlen(const char *str)//递归法实现
{
	if (0 == *str)
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