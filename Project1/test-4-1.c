#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//��������ҵ
//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
#include<stdio.h>
#include<stdlib.h>
void mul(int x)
{
	int i = 0, j = 0;
	for (i = 1; i <= x; i++)//������x��ʾ������
	{
		for (j = 1; j <= i; j++)//������
		{
			//printf("%d*%d=%2d\t", i, j, i*j);// %2d����Ϊ2�Ŀ�ȴ�ӡ�����������Ҷ��룻%02d��0����λ��%-d����룻%-6.2lf����
			printf("%d*%d=%d\t", i, j, i*j);//sprintf��ӡ
		}
		printf("\n");
	}
}
int main0()
{
	int a = 0;
	printf("����������Ҫ�ĳ˷�����:>\n");
	scanf("%d", &a);//scanf�ӿ�ȣ����....
	mul(a);//����mul�ĺ���
	system("pause");
	return 0;
}

//2.ʹ�ú���ʵ���������Ľ����� ����ջ������
#include<stdio.h>
#include<stdlib.h>

void Swap1(int x, int y)
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}
void Swap2(int *px, int *py)
{
	int tmp = 0;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
int main1()
{
	int a = 2;
	int b = 4;
	Swap1(a, b);
	printf("Swap1:a=%d b=%d\n", a, b);
	Swap2(&a, &b);
	printf("Swap2:a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}

//3.ʵ��һ�������ж�year�ǲ������ꡣ
#include<stdio.h>
#include<stdlib.h>
//leap_year 
// LEAP_YEAR

int leap_year(int year)
{
	return(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 1: 0;//������Ҫ��4��100��400����
	//(���жϿ���)
}
int main2()
{	
	int year = 0;
	int ret = 0;
	printf("��������ݣ�>");
	scanf("%4d", &year);//ֻҪǰ�ĸ�������Խ��
	ret = leap_year(year);
	if (ret)
	{
		printf("������");
	}
	else
	{
		printf("��������");
	}
	printf("\n");
	system("pause");
	return 0;
}

//5.ʵ��һ���������ж�һ�����ǲ���������
#include<stdio.h>
#include<stdlib.h>

int  Judge(int num)
{
	int flag = 0;
	int i;
	for (i = 2; i < num; ++i)
	{
		if (num%i == 0)
		{
	return flag;
		}
	}
	return flag;
}
int main3()
{
	int num, flag;
	printf("����������һ������:");
	scanf("%d", &num);
	flag = Judge(num);
	if (flag == 0)
	{
		printf("������\n");
	}
	if (flag == 1)
	{
		printf("��������\n");
	}
	system("pause");
	return 0;
}

//4. ����һ�����飬ʵ�ֺ���init������ʼ�����顢ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�Ҫ���Լ���ƺ����Ĳ���������ֵ
#include<stdio.h>
#include<stdlib.h>

void init(int arr[], int len)//��ʼ�����飨arr[] == *arr,ǰ�߽Ϻñ�ʾ�������ͣ�
{
	int i = 0;
	int num = 0;
	printf("��ʼ�����飬������5����:\n");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &num);
		arr[i] = num;
	}
}

void empty(int arr[], int len) //�������
{
	int i = 0;
	printf("��պ�����飺\n");
	for (i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}

void reverse(int arr[], int len)
{
	int i = 0;
	int arr2[20];
	printf("���ú�����飺\n");
	for (i = 0; i < len ; i++)
	{
		arr2[i] = arr[i];
	}
	for (i = 0; i < len; i++)
	{
		arr[i] = arr2[len - 1 - i];
	}
}
int main4()
{
	int i = 0;
	int arr[5] = {0};
	int len = sizeof(arr) / sizeof(arr[0]);//��������ĳ��ȵĹ�ʽ
	init(arr, len);//ָ������������ָ��...initҲ��һָ��
	reverse(arr, len);
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	empty(arr, len);
	for (i = 0; i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


//���ߴ���ҵ
//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲��������� 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main0()     //�ǵݹ�ʵ��
{
	int n = 0;
	int a = 1;
	int b = 1;
	int c = a;
	printf("������Ҫ��ĵ�n��쳲�������n=");
	scanf("%d", &n);
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	printf("%d\n",c);
	system("pause");
	return 0;
}
//
//for (i = 2; i <= n; i++)
//{
//	an = an_1 + an_2;
//	an_2 = an_1;
//	an_1 = an;
//}
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int fib(int n)   
	{
		if (n <= 2)
			return 1; //1 1 2 3 5 8 13 21 34 55.... ǰ������Ϊ1������С�ڵ���2ʱ����Ϊ1
		else
			return fib(n - 1) + fib(n - 2); //�ݹ�ʵ��(��1�Ĺ��̣�Ч�ʵͣ�дѭ���ɣ�)��ѭ��������ȷ��ʱ��д�ݹ�
	}
int main()
{
		int n = 0;
		printf("������Ҫ��ĵ�n��쳲�������n=");
		scanf("%d", &n);
		int ret = fib(n);
		printf("%d\n",ret);
		system("pause");
		return  0;
}

//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ�� 
#include<stdio.h>
#include<stdlib.h>
int del(int n, int k, int ant)
{
	if (n != 1)
	{
		return del(n - 1, k, ant*k);
	}
	else
		return ant*k;
}

int main()
{
	int num = 0;
	int n = 0;
	int k = 0;
	int tmp = 1;
	printf("n��k��ֵ�ֱ�Ϊ��");
	scanf_s("%d%d", &n, &k);
	num = del(k, n, tmp);
	printf("%d", num);
	system("pause");
	return 0;
}

3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n)
{
	if (n > 0)
	{
		return (n % 10) + DigitSum(n / 10);
	}
	return 0;
}
int main()
{
	int n = 0;
	printf("������һ�����֣�");
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));
	system("pause");
	return 0;
}
4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
   ʵ�֣��������ַ����е��ַ��������С�
   Ҫ�󣺲���ʹ��C�������е��ַ�������������
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *reverse_string(char *str)
{
	assert(str != NULL);
	if (*str != 0)
	{
		str++;
		reverse_string(str);
		printf("%c ", *(str - 1));

	}
	return str;
}

int main()
{
	char arr[] = "abcdefd";
	char *ret = reverse_string(arr);
	system("pause");
	return 0;
}


5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
#include<stdio.h>
#include<stdlib.h>

int my_strlen(const char *str)//�ݹ鷨ʵ��
{
	if ( 0 == *str)
		return 0;
	else
		return 1 + my_strlen(str + 1);

}
int main()
{
	const char *p = "abcdefd";
	int len = my_strlen(p);
	printf("%d\n", len);
	system("pause");
	return 0;
}

//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳� 
#include<stdio.h>
#include<stdlib.h>

int fac(int n)//�ǵݹ鷨ʵ��
{
	int i = 0;
	int tmp = 1;
	for (i = 1; i <= n; i++)
	{
		tmp *= i;
	}
	return tmp;
}
int main()
{
	int n = 0;
	printf("������һ�����֣�");
	scanf("%d", &n);
	int fac(n);
	printf("%d\n", fac(n));
	system("pause");
	return 0;
}

int fac(int n)  //�ݹ鷨ʵ��
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n*fac(n - 1);
	}
}
int main()
{
	int n = 0;
	printf("������һ�����֣�");
	scanf("%d", &n);
	int fac(n);
	printf("%d\n", fac(n));
	system("pause");
	return 0;
}

//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void print(int n)
{
	if (n >9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int num;
	scanf("%d", &num);
	print(num);
	system("pause");
	return 0;
}
#endif
