#if 0
1. unsigned int reverse_bit(unsigned int value);
这个函数的返回值value的二进制位模式从左到右翻转后的值
#endif
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int reverse_bit(unsigned int value){
	int n = 31;
	int count = 0;
	int ret;
	int rat = value;
	while (rat != 0){
		ret = rat % 2;
		count = count + ret*pow(2, n);
		rat = rat / 2;
		n--;
	}
	printf("%u\n", count);
	return 0;
}
int main(){
	reverse_bit(25);
	system("pause");
	return 0;
}

//2.不使用（a + b） / 2这种方式，求两个数的平均值。
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a = 3, b = 7;
	int ret = 0;
	ret = (b - a) / 2 + a;
	printf("a+b=%d\n", ret);
	system("pause");
	return 0;
}
//3.编程实现：一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。请找出这个数字。（使用位运算）
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i = 0;
	int arr[] = { 1, 3, 1, 2, 3, 2, 4 };
	int sum = 0;
	int a = arr[0];
	for (i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i){
		a = (a^arr[i]);
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}
//4.不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_strlen(const char *str){
	assert(str);
	int len = 0;
	while (*str++){
		len++;
	}
	return len;
}
void reverse(char *start, char *end){
	assert(start);
	assert(end);
	while (start < end){
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
void str_reverse(char *str){
	assert(str);
	int len = my_strlen(str);
	reverse(str, str + len - 1);
	while (*str != '\0'){
		char *p = str;
		while ((*str != ' ') && (*str != '\0')){
			str++;
		}
		reverse(p, str - 1);
		if (*str != '\0'){
			str++;
		}
	}
}
int main(){
	char str[] = "student a am i";
	str_reverse(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}