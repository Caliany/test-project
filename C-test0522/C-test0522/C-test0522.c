//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include<stdlib.h>
#include <string.h>
//左旋字符串中的 k 个字符
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
	printf("请输入一串字符:");
	scanf("%s", string);
	int k = 0;
	printf("请输入你要旋转的字符个数:");
	scanf("%d", &k);
	if (k > (int)strlen(string))
	{
		printf("输入有误\n");
	}
	Rotate(string, k);
	printf("%s\n", string);
	system("pause");
	return 0;
}

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0
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
	//旋转前k个字符
		reverse(str, str + k - 1);
	//旋转剩余的字符串
		reverse(str + k, str + len - 1);
	//旋转整体
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
		//每次旋转一次
			left_rotate(src, 1);
		//判断旋转之后的内容是否和目标一致
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
