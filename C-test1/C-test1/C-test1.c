//1. ��ӡ100~200 ֮�������
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	int i;
	for (num = 100; num <= 200; num++)
	{
		for (i = 2; i < num; i++)
		{
			if (num%i == 0)
				break;
		}
		if (i == num)
			printf("%d\n ", num);
	}
	system("pause");
	return 0;
}

//2. ����˷��ھ���
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
	int a, b, result;
	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= a; b++)
		{
			result = a*b;
			printf("%d*%d=%d  ", a, b, result);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//3. �ж�1000��-- - 2000��֮�������
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; ++year)
	{
		if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 1 : 0);
		{
			printf("%d  ", year);
		}

	}
	printf("\n");
	system("pause");
	return 0;
}