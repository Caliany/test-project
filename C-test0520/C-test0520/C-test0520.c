#if 0
1.
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ������������
#endif
#include<stdio.h>
#include<windows.h>

int main0()
{
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d < 5; d++)
				{
					for (e = 1; e < 5; e++)
					{
						if (a*b*c*d*e == 120)
						{
							if (((b == 2) + (a == 3) == 1) &&
								((b == 2) + (e == 4) == 1) &&
								((c == 1) + (d == 2) == 1) &&
								((c == 5) + (d == 3) == 1) &&
								((e == 4) + (a == 1) == 1))
							{
								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
#if 0
2.
�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
A˵�������ҡ�
B˵����C��
C˵����D��
D˵��C�ں�˵
��֪3����˵���滰��1����˵���Ǽٻ���
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
#endif
#include<stdio.h>
#include<stdlib.h>

int main1()
{
	int killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("killer=%c\n", killer);
			system("pause");
			return 0;
		}
	}
	return 1;
}
#if 0
3.����Ļ�ϴ�ӡ������ǡ�
1
1 1
1 2 1
1 3 3 1
#endif
#include <stdio.h>
#include<stdlib.h>

#define N 10

int main()
{
	int arr[N][N] = { 0 };
	int i = 0;
	for (i = 0; i<N; i++)
	{
		int m = 0;
		for (m = 0; m<N - i; m++)
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
}