#include <iostream>

using namespace std;

// ���õ����ã������������
// �﷨���������� &���� = ԭ�� 
// ����ע��������ñ����ʼ�����ڳ�ʼ���󲻿��ڸı� 

int main(){
	
	int a = 10,c=200;
	int &b = a;
//	int &d; // ����ģ�����Ҫ��ʼ�� 
	b = c; // ���Ǹ�ֵ���������Ǹ������� 

	cout << "1:a = " << a << endl; 
	cout << "1:b = " << b << endl;
	cout << "1:a�ĵ�ַΪ�� " << &a << endl; 
	cout << "1:b�ĵ�ַΪ:  " << &b << endl;
	
	b = 20;
	
	cout << "2:a = " << a << endl;
	cout << "2:b = " << b << endl;
	cout << "2:a�ĵ�ַΪ�� " << &a << endl; 
	cout << "2:b�ĵ�ַΪ:  " << &b << endl; 
		
	return 0;
}
