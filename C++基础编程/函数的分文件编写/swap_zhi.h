// swap_zhi.h��ͷ�ļ� 

#include<iostream>

using namespace std;

// ʵ���������ֽ����ĺ��������� 
void aaa(int a, int b);
// �����Ķ���
void aaa(int a, int b){

	// ������ʱ����
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "������" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}
