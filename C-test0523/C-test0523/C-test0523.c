//1.һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ��ҳ����������֣����ʵ�֡�
#include<stdio.h>
#include<stdlib.h>
int main(){
	int i = 0;
	int ret = 0;
	int sum = 0;
	int arr[] = { 1, 2, 5, 6, 7, 4, 6, 5, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < sz; ++i){
		ret ^= arr[i];
	}
	for (i = 0; i < 32; ++i){
		if (((ret >> 1) & 1) == 1){
			sum = i;
			break;
		}
	}
	for (i = 0; i < sz; ++i){
		if (((arr[i] >> sum) & 1) == 1){
			num1 ^= arr[i];
		}
	}
	num2 = num1^ret;
	printf("num1=%d num2=%d\n", num1, num2);
	system("pause");
	return 0;
}

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֡�
#include<stdio.h>
#include <stdlib.h>

int drink_soda(int money){
	int start = money;
	int num = money;
	while (start>1){
		num = num + start / 2;
		start = start / 2 + start % 2;
	}
	return num;
}
int main(){
	int money = 20;
	int num = 0;
	num = drink_soda(money);
	printf("%d\n", num);
	system("pause");
	return 0;
}
//3.ģ��ʵ��strcpy ���strcpy(str1, str2)������str2��ֵ���Ƶ�����str1
//����˼·������Ƚϼ򵥣����������ֵһ�����Ŀ�������һ�������У���ӡһ���������ÿһ��ֵ��
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

void my_strcpy(char *dest, const char *src){
	assert(dest);//���ԣ��жϴ�ָ���Ƿ��ǿ�ָ�룻
	assert(src);//���ԣ���ָ�벻�ܱ������ã�
	while (*dest++ = *src++){   //�Ȱ�Դ�ַ�������Ԫ�ظ���Ŀ���ַ�����Ȼ�����++���ӵ�'\0'ʱ,ѭ���˳���
		;
	}
	*dest = '\n';
}
//4.ģ��ʵ��strcat
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

void *my_strcat(char *dest, const char *src){
	char *ret = dest; //���淵��ֵ
	assert(dest);//���ԣ��жϴ�ָ���Ƿ��ǿ�ָ�룻
	assert(src);//���ԣ���ָ�벻�ܱ������ã�
	while (*dest){   //�Ȱ�Դ�ַ�������Ԫ�ظ���Ŀ���ַ�����Ȼ�����++���ӵ�'\0'ʱ,ѭ���˳���
		dest++;
	}  //�Ȱ�Ŀ���ַ��������꣬��������whileѭ������Դ�ַ������ӵ�Ŀ���ַ������һ���ַ�������'\n'�ĺ��棩��
	while (*dest++ = *src++){
		;
	}
	return ret;
}
int main(){
	char str1[40] = "abcdef";
	char str2[20] = "hahaha";
	my_strcat(str1, str2);
	printf("%s\n", str1);
	system("pause");
	return 0;
}
int main(){
	char arr[20];
	my_strcpy(arr, "hello bit");
	printf("%s\n", arr);
	system("pause");
	return 0;
}

