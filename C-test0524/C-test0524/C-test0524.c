//2.实现strcat

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* Strcat(char* dest, const char* src){
	//1.先在dest中找到'\0';
	int i = 0;
	//这个循环结束之后，i对应的就是'\0'
	for (; dest[i] != '\0'; ++i);//空语句
	//2.再把src中的字符一次复制进去
	for (int j = 0; src[j] != '\0'; ++i, ++j){
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return dest;
}
int main(){
	char str1[1024] = "bbb";
	char str2[1024] = "aaa";
	Strcat(str1, str2);
	printf("%s\n", str1);
	printf("%s\n", str2);
	system("pause");
	return 0;
}

//5.实现strcmp
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int Strcmp(const char* str1, const char* str2){
	int i = 0;
	for (; str1[i] != '\0' && str2[i] != '\0'; ++i){
		if (str1[i] < str2[i]){
			return -1;
		}
		else if (str1[i] > str2[i]){
			return 1;
		}
		else{
			//啥都不干，直接进行下一个字符比较。
		}
	}
	if (str1[i] < str2[i]){
		return -1;
	}
	else if (str1[i] > str2[i]){
		return 1;
	}
	else {
		return 0;
	}
}

int main(){
	char str1[1024] = "bbb";
	char str2[1024] = "bbbaf";
	//
	int ret = Strcmp(str1, str2);
	if (ret > 0){
		printf("str1 > str2\n");
	}
	else if (ret < 0){
		printf("str1 < str2\n");
	}
	else if (ret == 0){
		printf("str1 == str2\n");
	}
	system("pause");
	return 0;
}

//3.实现strstr 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
char* Strstr(const char* str1, const char* str2){
	assert(str1 != NULL);
	assert(str2 != NULL);
	if (*str2 == '\0'){
		return NULL;
	}
	//黑指针记录从哪个位置找字符串子串
	char* black_ptr = str1;
	while (*black_ptr != '\0'){
		//红指针帮我们完成具体的子串比较
		char* red_ptr = black_ptr;
		char* sub_ptr = str2;
		while (*red_ptr != '\0'
			&& *sub_ptr != '\0'
			&& *red_ptr == *sub_ptr){
			++sub_ptr;
			++red_ptr;
		}
		if (*sub_ptr == '\0'){
			//找到了
			return black_ptr;
		}
		++black_ptr;
	}
	return NULL;
}

int main(){
	char str1[] = "abcdef";
	char str2[] = "bcd";
	//ret指向了str1中第一处str2子串的位置
	//如果没找到子串，就返回空指针NULL
	char* ret = Strstr(str1, str2);
	printf("%p\n", str1);
	printf("%p\n", str2);
	system("pause");
	return 0;
}
//6.实现memcpy
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void* Memcpy(void* dest, const void* src, size_t num){
	const char* psrc = (const char*)src;
	char* pdest = (char*)dest;
	for (size_t i = 0; i < num; ++i){
		pdest[i] = psrc[i];
	}
	return dest;
}
int main(){
	int arr1[4] = { 0 };
	int arr2[4] = { 1, 2, 3, 4 };
	Memcpy(arr1, arr2, 16);
	for (int i = 0; i < 4; ++i){
		printf("%d\n", arr1[i]);
	}
	system("pause");
	return 0;
}


//7.实现memmove 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
void *my_memmove(void* dest, void* src, int n){
	assert(dest);
	assert(src);
	char* pdest = (char *)dest;
	const char* psrc = (const char*)src;
	if (pdest <= psrc && pdest >= psrc + n){
		while (n--){
			*pdest = *psrc;
		}
	}
	else{
		while (n--){
			*(pdest + n) = *(psrc + n);
		}
	}
	return dest;
}
int main(){
	int arr1[4] = { 0 };
	int arr2[4] = { 1, 2, 3, 4 };
	my_memmove(arr1, arr2, 16);
	for (int i = 0; i < 4; ++i){
		printf("%d\n", arr1[i]);
	}
	system("pause");
	return 0;
}
