#include <iostream>

using namespace std;

int main(){
	
	// ��ָ��
	// 1����ָ�����ڸ�ָ��������г�ʼ��
	// 2����ָ�벻���Խ��з��ʣ���0-255֮��ĵ�ַ��ϵͳռ�õģ���˲����Է��ʣ� 
	// 3���ڳ����У������������Ұָ�루��Ϊ���ʻ������ 
	int a = 10;
	int *p = (int *)0x184a;	// Ұָ�룬���ɷ��� 
	
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	
	*p = a; // �����Զ�ָ��ֱ�Ӹ�ֵ��Ҫ����ֱ�ӱ��� 
	p = &a;
	
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl; 
	cout << "*p = " << *p << endl;
	cout << "a = " << a << endl;
	
	system("pause");
	return 0;
}
