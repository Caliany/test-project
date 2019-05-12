
#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<stdio.h>
#include<math.h>
int main() 
{
	double a, b, c, d, x1, x2; // 三个系数，德尔塔，两个根
	while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) 
	{
		// 三个系数均为0，退出
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		d = b * b - 4 * a * c; // 计算德尔塔
		if (d == 0)
		{ 
			x1 = -b / (2 * a);
			printf("%lf\n", x1);
		}
		else if (d > 0)
		{ 
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			printf("%lf\n%lf\n", fmax(x1, x2), fmin(x1, x2));
		}
		else
		{ 
			printf("%d\n", -1);//没有解
		}
	}
	return 0;
}
//行列转置
#include<stdio.h>
void main11()
{
	int a[3][4] = { { 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 } }, i, j;
	int b[4][3];
	printf("Array a\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			b[j][i] = a[i][j];
		}
	}
	printf("%d\n", a, b);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main(void)
 {
     int i, j, a[3][4], b[4][3];
     printf("请输入三行四列的数组:\n");
		for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
        scanf("%d", &a[i][j]);
		for (i = 0; i < 4; i++)
		   for (j = 0; j < 3; j++)
			 b[i][j] = a[j][i];
	    for (i = 0; i <4; i++)
	{
		     for (j = 0; j < 3; j++)
			 printf("%d ", b[i][j]);
		     printf("\n");
		
	}
		system("pause");
	    return 0;
}


#include <stdio.h>
#include<stdlib.h>

#define N 10

int main()
{
	int arr[N][N] = { 0 };
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int m = 0;
		for (m = 0; m < N - i; m++)
		{
			printf("  ");
		}
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			if ((0 == j) || (i == j))
			{
				arr[i][j] = 1;

			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];

			}
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;

#endif

#include<stdio.h>
#include<stdlib.h>
	int main(){
		int i = 0;
		int ret = 0;
		int sum = 0;
		int arr[] = { 1, 2, 5, 6, 7, 4, 6, 5, 2, 1 };
		int sz = sizeof(arr) / sizeof(arr[0]);
		int num1 = 0;
		int num2 = 0;
		for (i = 0; i < sz; ++i){
			ret ^= arr[i];
		}
		for (i = 0; i < 32; ++i){
			if (((ret >> 1) & 1) == 1){
				sum = i;
				break;
			}
		}
		for (i = 0; i < sz; ++i){
			if (((arr[i] >> sum) & 1) == 1){
				num1 ^= arr[i];
			}
		}
		num2 = num1^ret;
		printf("num1=%d\nnum2=%d\n", num1, num2);
		system("pause");
		return 0;
	}