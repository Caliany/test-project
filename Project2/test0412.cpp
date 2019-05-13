/*
#define _CRT_SECURE_NO_WARNINGS 1
//C++课程作业
//1.求一元二次方程的根
#include"iostream"
using namespace std;
void main1(){
	double a, b, c, delta, p, q;
	cout << "please input a,b,c=";
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	p = -b / (2 * a);
	q = sqrt(fabs(delta)) / (2 * a);
	if (delta > 0)
		cout << "两个实根为：\nx1 =" << p + q << endl << "x2 =" << p - q << endl;
	else
	if (delta == 0)
		cout << "两个实根为：x1 = x2 = " << p << endl;
	else{
		cout << "两个虚根为：";
		cout << endl << "x1=" << p << "+j" << q;
		cout << endl << "x2=" << p << "-j" << q << endl;
	}
	system("pause");
}

//2.将3行4列的二维数组中a的每个元素行列互换，
//保存到另一个4行3列的二维数组b中。
#include "iostream"
using namespace std;
void main(){
	int a[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, i, j;
	int b[4][3];
	cout << "Array A" << endl;
	for (i = 0; i < 3;i++){
		for (j = 0; j < 4; j++){
			cout << a[i][j] << " ";
			b[j][i] = a[i][j];
		}
		cout << endl;
	}
	cout << "Array B" << endl;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 3; j++)
			cout << b[i][j] << " ";
			cout << endl;
	}
	system("pause");
}
*/
