//#include "SList.h"
//
//void Swap(int** pLeft, int** pRight){
//	printf("&pLeft = %p\n", &pLeft);
//	printf("&pRight = %p\n", &pRight);
//
//	int* tmp = *pLeft;
//	*pLeft = *pRight;
//	*pRight = tmp;
//
//}
//
//int main(){
//	int a = 10;
//	int b = 20;
//
//	int* pa = &a;
//	int* pb = &b;
//	printf("&pa = %p\n",&pa);
//	printf("&pb = %p\n",&pb);
//
//	Swap(&pa, &pb);//将两个变量的地址传过去
//	system("pause");
//	return 0;
//}