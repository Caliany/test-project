//1. ������A�е����ݺ�����B�е����ݽ��н�����������һ����

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
//2. ����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
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
	printf("�����%lf\n", sum);
	system("pause");
	return 0;
}
//3.����1/1-1/2+1/3-1/4.....+1/99-1/100��ֵ��
#include<stdio.h>
#include<math.h>
int main1()
{
	int i;
	double sum = 0, tmp, flag = 1;//��Ҫ���Ǹ���ֵ
	for (i = 1; i <= 100; i++)
	{
		tmp = 1.0 / i * (i % 2 ? 1 : -1);
		sum += tmp;
		//flag *= -1;
	}
	printf("%lf\n", sum);//%d��%lf���׳���ע��˿ӣ�������
	system("pause");
	return 0;
}

//4. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
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
	printf("1��100����������9���ٴΣ�\n%d\n", count);
	system("pause");
	return 0;
}