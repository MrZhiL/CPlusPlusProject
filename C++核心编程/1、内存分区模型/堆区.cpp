#include <iostream>

using namespace std;

int * func(){
	
	// ����new�ؼ����ڶ��������ַ 
	// ָ�뱾��Ҳ�Ǿֲ�����������ջ�ϣ���ָ�뱣������ݷ��ڶ��� 
	int *p = new int(10);
	return p;
	
} 

int main(){
	
	// �ڶ�����������
	
	int *p = func();
	
	cout << "1:*p = " << *p << endl;
	cout << "2:*p = " << *p << endl; 
	
	return 0;
} 
