//1.在屏幕上输出以下图案：
*
***
*****
*******
*********
***********
*************
***********
*********
*******
*****
***
*
#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, n;
	n = 13;
	for (a = 1; a <= n; a++)
	{
		for (b = 1; b <= a; b++)
		{
			if (a % 2 == 1)
				printf("*");
		}
		printf("\n");
	}
	int i;
	for (i = 1; i <13; i++)
	{
		int j;
		int n = 2 * i - 1;
		for (j = 1; j <= 12 - i; j++)
		{
			if (i % 2 == 1)
				printf("*");
		}
		printf("\n");

	}
	system("pause");
	return 0;
}
//2.求出0～999之间的所有“水仙花数”并输出。 【153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3。】
#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	int a, b, c;
	for (i = 0; i <= 999; i++)
	{
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;
		if (i == a * a * a + b * b * b + c * c * c)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
//3.求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字。【2 + 22 + 222 + 2222 + 22222】
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int sum = 0;
	int tmp = 0;
	for (i = 1; i <= 5; i++)
	{
		tmp = tmp * 10 + 3;
		sum += tmp;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}