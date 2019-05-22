//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include<stdlib.h>
#include <string.h>
//�����ַ����е� k ���ַ�
void Rotate(char* s, int k) {
	int len = strlen(s);
	char* p;
	char* q;
	for (p = s + k - 1; p >= s; --p)
	{
		for (q = p; q < p + len - k; ++q)
		{
			char tmp = *q;
			*q = *(q + 1);
			*(q + 1) = tmp;
		}
	}
}
int main()
{
	char string[30];
	printf("������һ���ַ�:");
	scanf("%s", string);
	int k = 0;
	printf("��������Ҫ��ת���ַ�����:");
	scanf("%d", &k);
	if (k > (int)strlen(string))
	{
		printf("��������\n");
	}
	Rotate(string, k);
	printf("%s\n", string);
	system("pause");
	return 0;
}

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void  reverse(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
void  left_rotate(char * str, int k)
{
	int  len = strlen(str);
	//��תǰk���ַ�
		reverse(str, str + k - 1);
	//��תʣ����ַ���
		reverse(str + k, str + len - 1);
	//��ת����
		reverse(str, str + len - 1);
}
int is_rotate(char* dest, char* src)
{
	if (strlen(dest) != strlen(src))
	{
		return 0;
	}
	if (!strcmp(dest, src)){
		return 1;
	}
	int  k = strlen(dest);
	k--;
	while (k--)
	{
		//ÿ����תһ��
			left_rotate(src, 1);
		//�ж���ת֮��������Ƿ��Ŀ��һ��
		if (!strcmp(dest, src))
		{
			return 1;
		}
	}
	return  0;
}
	int  main()
	{
		char dest[100];
		char src[100];
		scanf("%s", &dest);
		scanf("%s", &src);
		printf("%d\n", is_rotate(dest, src));
		system("pause");
		return 0;
	}
