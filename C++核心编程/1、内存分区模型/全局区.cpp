#include <iostream>
#include <string>

using namespace std;

// ȫ�ֱ���
int g_a = 19;
int g_b = 29; 

// const���ε�ȫ�ֱ���
const int c_g_a = 30;
const int c_g_b = 10; 

int main(){
	
	// ȫ����
	
	// ȫ�ֱ�������̬����������
	
	// ������ͨ�ֲ�����
	int a = 10,b=20;
	
	// ������̬���������Թ۲쵽��̬������ȫ�ֱ�����ŵĵ�ַ��ͬ 
	static int s_a = 11;
	static int s_b = 78; 
	
	// ��������--�ַ���������const���εı���
	// ����һ���ַ��������������ľֲ��ַ�������ھֲ���ַ���� 
	string  str_a = "HelloWorld!";
	
	// const���εı���--1��const���ε�ȫ�ֱ�����2��const���εľֲ�����
	/*���Թ۲��const���εľֲ������ĵ�ַΪ�ֲ����򣬶�const���ε�ȫ�ֱ���������ȫ����*/ 
	const int c_a = 41;
	const int c_b = 82; 
	
	cout << "�ֲ�����a�ĵ�ַΪ�� " << &a << endl;
	cout << "�ֲ�����b�ĵ�ַΪ�� " << &b << endl;
	
	cout << "ȫ�ֱ���g_a�ĵ�ַΪ�� " << &g_a << endl;
	cout << "ȫ�ֱ���g_b�ĵ�ַΪ�� " << &g_b << endl; 
	
	cout << "��̬����s_a�ĵ�ַΪ�� " << &s_a << endl;
	cout << "��̬����s_b�ĵ�ַΪ�� " << &s_b << endl;
	
	cout << "�ַ�������str_a�ĵ�ַΪ�� " << &str_a << endl;
	cout << "�ַ��������ĵ�ַΪ�� " << &"Hello!" << endl; 

	cout << "const���ε�ȫ�ֱ���c_g_a�ĵ�ַΪ�� " << &c_g_a << endl;
	cout << "const���ε�ȫ�ֱ���c_g_b�ĵ�ַΪ�� " << &c_g_b << endl; 
	 
	cout << "const���εľֲ�����c_a�ĵ�ַΪ�� " << &c_a << endl;
	cout << "const���εľֲ�����c_b�ĵ�ַΪ�� " << &c_b << endl; 
	
	system("pause");
	return 0;
} 
