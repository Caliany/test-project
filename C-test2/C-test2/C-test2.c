#define _CRT_SECURE_NO_WARNINGS
//1. 给定两个整形变量的值，将两个值的内容进行交换。

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 2, b = 5, tmp;
	printf("交换前：a=%d,b=%d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("交换后：a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}
//2. 不允许创建临时变量，交换两个数的内容（附加题）
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 2, b = 5;
	printf("交换前：a=%d,b=%d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("交换后：a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}
//4.将三个数按从大到小输出。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	int tmp;
	scanf("%d%d%d", &a, &b, &c);
	if (a< b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (c > b)
	{
		if (c > a)
		{
			printf("%d %d %d\n ", c, a, b);
		}
		else
		{
			printf("%d %d %d\n ", a, c, b);
		}
	}
	else
	{
		printf("%d %d %d\n", a, b, c);
	}
	system("pause");
	return 0;
}

//5.求两个数的最大公约数。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int a, b, max, min;
	printf("请输入两个数字：>");
	scanf("%d%d", &a, &b);
	min = a < b ? a : b;
	for (i = 2; i <= min; i++)
	{
		if ((a % i == 0) && (b % i == 0))
		{
			max = i;
		}
	}
	printf("最大公约数是%d\n", max);
	system("pause");
	return 0;
}