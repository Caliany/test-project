/*
#define _CRT_SECURE_NO_WARNINGS 1
//C++�γ���ҵ
//1.��һԪ���η��̵ĸ�
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
		cout << "����ʵ��Ϊ��\nx1 =" << p + q << endl << "x2 =" << p - q << endl;
	else
	if (delta == 0)
		cout << "����ʵ��Ϊ��x1 = x2 = " << p << endl;
	else{
		cout << "�������Ϊ��";
		cout << endl << "x1=" << p << "+j" << q;
		cout << endl << "x2=" << p << "-j" << q << endl;
	}
	system("pause");
}

//2.��3��4�еĶ�ά������a��ÿ��Ԫ�����л�����
//���浽��һ��4��3�еĶ�ά����b�С�
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
