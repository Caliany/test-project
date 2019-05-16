//1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 7, 8, 9, 10 };
	int i = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (i = 0; i <= sz; i++)
	{
		int tmp = 0;
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	for (i = 0; i<sz; i++)
	{
		printf("%d", arr1[i]);

	}
	printf("\n");
	for (i = 0; i<sz; i++)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	double sum = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
			sum = sum + 1.0 / (double)i;
		else
			sum = sum + (-1.0 / (double)i);
	}
	printf("结果：%lf\n", sum);
	system("pause");
	return 0;
}
//3.计算1/1-1/2+1/3-1/4.....+1/99-1/100的值。
#include<stdio.h>
#include<math.h>
int main1()
{
	int i;
	double sum = 0, tmp, flag = 1;//不要忘记赋初值
	for (i = 1; i <= 100; i++)
	{
		tmp = 1.0 / i * (i % 2 ? 1 : -1);
		sum += tmp;
		//flag *= -1;
	}
	printf("%lf\n", sum);//%d和%lf容易出错，注意此坑！！！！
	system("pause");
	return 0;
}

//4. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i / 10 == 9)
			count++;
		if (i % 10 == 9)
			count++;
	}
	printf("1到100出现了数字9多少次？\n%d\n", count);
	system("pause");
	return 0;
}