#include <iostream>

using namespace std;

// ���������ã�ת��Ϊ int * const ref2 = &a; 
void func(int& ref2){
	
	// ����ref���յ��ǵ�ַ�����Ե��ı�ref2ʱ��&a��ָ�������Ҳ�����ı� 
	ref2 = 100;	//ref�����ã�ת��Ϊ*ref2 = 100; 
}

void func5(int a,int ){
	cout << "this is a func5 " << endl;
} 

void printValue(const int& val){
//	val = 99; // ��const�������ú󣬲����ٸ���val��ֵ����ʱΪֻ��״̬ 
	cout << "val = " << val << endl;
}


// ���������������Ĭ�ϲ���������ʵ���оͲ�����Ĭ�ϲ��� 
// ������ʵ��ֻ����һ����Ĭ�ϲ��� 
//int func3(int a=10,int b=20);

// �������ص�����������
// 1��������ͬһ���������£�
// 2������������ͬ��
// 3�������������Ͳ�ͬ�����߸�����ͬ������˳��ͬ 
// ע�⣺�����ķ���ֵ��������Ϊ���ص����� 
int func31(int c){
	cout << "func2(int c) " << endl; 
	return c;
}

int func31(int c, int d=10){
	cout << "func2(int c,int d=10) " << endl; 
	return c;
}

int func3(int &c){
	cout << "func3(int &c) " << endl;
	return 1;
} 

int func3(const int &c){
	cout << "func3(const int &c)" << endl;
	return 1;
}

int func3(int a, int b){
	cout << "func3(int a, int b) " << endl; 
	return a+b;
}

int main(){
	
	int a = 10; // ��������
	int &ca = a;
//	func21(a); // ����ģ�������������Ĭ�ϲ��������ֶ����ԣ������������������� 
	func31(10,10); // ��ȷ�� 
	func3(a);
//	func3(10);
	// �������õ����ã���ֹ�����
	// ʹ�ó��������������βΣ���ֹ����� 
	int showa = 999;
	
	cout << func3(1,1) << endl;
	
	cout << "showa = " << showa << endl; 
	printValue(showa);
	cout << "showa = " << showa << endl;
	
	// �������ã����õı�����һ��ָ�볣����
	// ��ϵͳ��⵽������һ�����ú���ϵͳ�Զ�ת��Ϊ int * const ref = &a; 
	// ָ�볣����ָ��ָ�򲻿ɸ��ģ�Ҳ˵��Ϊʲô���ò��ɸ��� 
	int &ref = a;	 
	 
	cout << "1:a=" << a << endl; 
	cout << "1:ref=" << ref << endl;
	cout << "1:a�ĵ�ַΪ��" << &a << endl;
	cout << "1:ref�ĵ�ַΪ�� " << &ref << endl;
	
	ref = 20;	//�ڲ����������ã��Զ�ת��Ϊ*ref=20��
	
	cout << "2:a=" << a << endl; 
	cout << "2:ref=" << ref << endl;
	cout << "2:a�ĵ�ַΪ��" << &a << endl;
	cout << "2:ref�ĵ�ַΪ�� " << &ref << endl;
	
	func(a); 
	cout << "3:a=" << a << endl; 
	cout << "3:ref=" << ref << endl;
	cout << "3:a�ĵ�ַΪ��" << &a << endl;
	cout << "3:ref�ĵ�ַΪ�� " << &ref << endl;
	
//	int &b = 1;	// ����ģ����õ��ڴ�����ڶ�������ջ�����Ϸ����ڴ�ռ䣩���������ڳ����� 
	const int &b = 1; // ��ȷ�ģ���Ϊ����const�󣬱������Զ�����һ�� int temp=1, const int &b=temp; 
//	b = 2; //��const��Ǻ󣬱�Ϊֻ��״̬���������޸� 
	cout << b << endl;

	
	return 0;
} 

// ���ۣ�C++�Ƽ������ü�������Ϊ�﷨���㣬���ñ�����ָ�볣��������ָ����������������������� 
