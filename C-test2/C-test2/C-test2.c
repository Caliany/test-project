#define _CRT_SECURE_NO_WARNINGS
//1. �����������α�����ֵ��������ֵ�����ݽ��н�����

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 2, b = 5, tmp;
	printf("����ǰ��a=%d,b=%d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("������a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}
//2. ����������ʱ���������������������ݣ������⣩
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 2, b = 5;
	printf("����ǰ��a=%d,b=%d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("������a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}
//4.�����������Ӵ�С�����
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

//5.�������������Լ����
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int a, b, max, min;
	printf("�������������֣�>");
	scanf("%d%d", &a, &b);
	min = a < b ? a : b;
	for (i = 2; i <= min; i++)
	{
		if ((a % i == 0) && (b % i == 0))
		{
			max = i;
		}
	}
	printf("���Լ����%d\n", max);
	system("pause");
	return 0;
}