#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main0()
{
	printf("hello world\n");//说好
	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
int main1()
{
	int num = 0;
	scanf("%d",&num);
	printf("%d\n", num);
	system("pause");
	return 0;

}




#include<stdio.h>
#include<stdlib.h>
int main2()
{
	int i, sum = 1;
	for (i = 1; i <= 10; i++)//10的阶乘
	{
		sum *= i;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
//

#include<stdio.h>
#include<stdlib.h>
int main3()
{
	int i;
	int sum = 1;
	int tmp = 1;//执行1到10的阶乘相加
	for (i = 1; i <= 10; i++)
	{
		tmp *= i;
		sum += tmp;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main4()
{
	int i;
	int tmp, max = 0;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &tmp);//找出三个数中的最大数
		if (tmp >max)
		{
			max = tmp;
		}

	}
	printf("%d\n", max);
	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
int main5()
{
	int i;
	int sum = 0;
	for (i = 0; i <= 100; i++)//执行1到100的加法
	{
		sum +=i;
    }
	printf("%d\n", sum);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main6()
{
	int n  = 1;
	int m = 2;
	switch (n)
	{
		case 1:
			m++;
		case 2:
			n++;
		case 3:
			switch (n)//n=2的情况下继续以下运算
		{
		case 1://因为n=2时，case语句能够执行第二种情况，此时直接跳过
			n++;
		case 2:
			m++;
			n++;
			   break;//返回，直接开始case4的顺序
		}
		case 4:
			m++;
			break;
			default:
				break;	
	}
	printf("m=%d,n=%d\n", m, n);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>


int main7()
{
	int i = 0;
	for (i = 1; i <= 10; i++)//数组循环
	{
		if (i == 5)
			break;//循环中只要遇到break，就停止后期的所有循环，直接终止循环；所以while中的break是用于永久终止循环的。
		printf("%d", i);     //continue是用于终止本次循环的，也就是本次循环中continue后边的循环不会再执行，而是直接
	}						//跳转到while语句的判断部分，进行下一次循环的入口判断。
	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
int main8()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int sum = 0;
	printf("请输入两个操作数：");//三个数相加
	scanf("%d %d %d", &a, &b, &c );
	sum = a + b + c;
	printf("sum=%d\n", sum);
	system("pause");
	return 0;
}


#include<stdio.h>
#include<math.h>
int main9()
{
	double a = 3, b = 4, c = 5;
	double p, s;
	if (a + b > c && a + c > b && b + c > a) //判断是否可以构成三角形
	{
		p = (a + b + c)/2;//计算半周长
		s = sqrt(p*(p - a)*(p - b)*(p - c));//海伦公式，计算面积
		printf("面积为%lf\n", s);//输出
	}
	else printf("无法构成三角形\n");
	system("pause");
	return 0;
}
//1.猜数字游戏升级版
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main10()
{
	srand((unsigned int)time(NULL));//time时间算出来加八小时（东八区）
	int r = rand() % 100;      //0 - n  rand() % (n + 1),a - b  rand() % （b - a + 1）+ a
	int n = -1;               //保证一开始就不相等

	while (n != r)  //while循环进行输入
	{
		while (!scanf("%d", &n))
		//%d挑食，见到字母就会无限循环下去，，%c完全不挑食
		{
			getchar();
		}
		if (n > r)
		{
			printf("猜大了\n");
		}
		else if (n < r)
		{
			printf("猜小了\n");
		}
	}
	printf("猜对了\n");
	system("pause");
	return 0;
}
//2.(折半查找法)分治--递归法--熟悉写函数，方便copy
 //一个函数尽可能完成一件事
#include<stdio.h>
int searchArray(int arr[], int size, int f)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == f);
		{
			return i;
		}
	}
	return -1;
}
int main11()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	printf("%d\n", searchArray(a, 10, 6));
	system("pause");
	return 0;
}
#endif
