//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲��������� 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main()     //�ǵݹ�ʵ��
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
	printf("%d\n", c);
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
	printf("%d\n", ret);
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

//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
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
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
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


//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
#include<stdio.h>
#include<stdlib.h>

int my_strlen(const char *str)//�ݹ鷨ʵ��
{
	if (0 == *str)
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