//1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。找出这两个数字，编程实现。
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

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水。编程实现。
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
//3.模拟实现strcpy 概念：strcpy(str1, str2)将数组str2的值复制到数组str1
//解题思路：整体比较简单，将数组里的值一个个的拷贝到另一个数组中；打印一个数组里的每一个值。
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

void my_strcpy(char *dest, const char *src){
	assert(dest);//断言，判断此指针是否是空指针；
	assert(src);//断言，空指针不能被解引用；
	while (*dest++ = *src++){   //先把源字符串的首元素付给目标字符串，然后各自++；加到'\0'时,循环退出；
		;
	}
	*dest = '\n';
}
//4.模拟实现strcat
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

void *my_strcat(char *dest, const char *src){
	char *ret = dest; //保存返回值
	assert(dest);//断言，判断此指针是否是空指针；
	assert(src);//断言，空指针不能被解引用；
	while (*dest){   //先把源字符串的首元素付给目标字符串，然后各自++；加到'\0'时,循环退出；
		dest++;
	}  //先把目标字符串访问完，接下来的while循环，把源字符串连接到目标字符串最后一个字符（不是'\n'的后面）。
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

