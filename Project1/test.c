#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main0()
{
	printf("hello world\n");//˵��
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
	for (i = 1; i <= 10; i++)//10�Ľ׳�
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
	int tmp = 1;//ִ��1��10�Ľ׳����
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
		scanf("%d", &tmp);//�ҳ��������е������
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
	for (i = 0; i <= 100; i++)//ִ��1��100�ļӷ�
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
			switch (n)//n=2������¼�����������
		{
		case 1://��Ϊn=2ʱ��case����ܹ�ִ�еڶ����������ʱֱ������
			n++;
		case 2:
			m++;
			n++;
			   break;//���أ�ֱ�ӿ�ʼcase4��˳��
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
	for (i = 1; i <= 10; i++)//����ѭ��
	{
		if (i == 5)
			break;//ѭ����ֻҪ����break����ֹͣ���ڵ�����ѭ����ֱ����ֹѭ��������while�е�break������������ֹѭ���ġ�
		printf("%d", i);     //continue��������ֹ����ѭ���ģ�Ҳ���Ǳ���ѭ����continue��ߵ�ѭ��������ִ�У�����ֱ��
	}						//��ת��while�����жϲ��֣�������һ��ѭ��������жϡ�
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
	printf("������������������");//���������
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
	if (a + b > c && a + c > b && b + c > a) //�ж��Ƿ���Թ���������
	{
		p = (a + b + c)/2;//������ܳ�
		s = sqrt(p*(p - a)*(p - b)*(p - c));//���׹�ʽ���������
		printf("���Ϊ%lf\n", s);//���
	}
	else printf("�޷�����������\n");
	system("pause");
	return 0;
}
//1.��������Ϸ������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main10()
{
	srand((unsigned int)time(NULL));//timeʱ��������Ӱ�Сʱ����������
	int r = rand() % 100;      //0 - n  rand() % (n + 1),a - b  rand() % ��b - a + 1��+ a
	int n = -1;               //��֤һ��ʼ�Ͳ����

	while (n != r)  //whileѭ����������
	{
		while (!scanf("%d", &n))
		//%d��ʳ��������ĸ�ͻ�����ѭ����ȥ����%c��ȫ����ʳ
		{
			getchar();
		}
		if (n > r)
		{
			printf("�´���\n");
		}
		else if (n < r)
		{
			printf("��С��\n");
		}
	}
	printf("�¶���\n");
	system("pause");
	return 0;
}
//2.(�۰���ҷ�)����--�ݹ鷨--��Ϥд����������copy
 //һ���������������һ����
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
