//ת���ַ�
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main(){
	printf("%d\n", strlen("abcdef"));
	//\32��������һ��ת���ַ�
	printf("c:\code\test.c\n");
	printf("%d\n",strlen("c:\test\328\test.c"));
	system("pause");
	return 0;
}

//����
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n1 = 0;
	int n2 = 0;
	int sum = 0;
	printf("�����������֣�");
	scanf("%d %d", &n1, &n2);
	sum = n1 + n2;
	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int Add(int x, int y){
	int z = x + y;
	return z;
}
int main(){
	int x, y;
	int n1 = 0;
	int n2 = 0;
	int sum = 0;
	printf("�����������֣�");
	scanf("%d %d", &x, &y);
	sum = Add(x, y);
	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}