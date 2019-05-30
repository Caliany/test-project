//修饰局部变量
#include <stdio.h>
void test(){
	static int i = 0;
	i++;
	printf("%d\n", i);
}
int main(){
	int i;
	for (i = 0; i < 10; i++){
		test();
	}
	system("pause");
	return 0;
}


//define定义常量和宏
#define MAX 1000
#define ADD(x,y)((x)+(y))

#include <stdio.h>

int main(){
	int sum = ADD(5, 6);
	printf("sum=%d\n", sum);
	sum = 10 * ADD(5, 6);
	printf("sum=%d\n", sum);
	system("pause");
	return 0;
}