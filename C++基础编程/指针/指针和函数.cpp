#include <iostream>

using namespace std;

// ʹ�ñ�������ֵ 
void swap1(int a, int b);
// ʹ��ָ�봫��ֵ 
void swap2(int *, int *); 

int main(){
	
	// ָ��ͺ���
	// note�������βε�ֵ�޷��ı�ʵ�ε�ֵ 
	// 1��ֵ����	2����ַ����
	// �ܽ᣺��������޸�ʵ�ξ���ֵ���ݣ����޸�ʵ�ξ��õ�ַ���� 
	
	int  a = 10,b=20;
	cout << "ֵ����ǰ��" << endl; 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; 
	
	// 1��ֵ���� 
	swap1(a,b);
	
	cout << "swap1ֵ���ݺ�" << endl; 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; 
	
	// 2����ַ���� 
	// ͨ����ַ���в������ݣ���������ʵ�� 
	swap2(&a,&b);
	
	cout << "swap2ֵ���ݺ�" << endl; 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	system("pause");
	return 0;
}

// ʹ�ñ�������ֵ 
void swap1(int a, int b){
	// ���в���a��b�Ľ��� 
	int temp;
	temp = a;
	a = b;
	b = temp;
}
// ʹ��ָ�봫��ֵ 
void swap2(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp; 
	cout << "ֵ���ݺ�" << endl; 
	cout << "*a = " << *a << endl;
	cout << "*b = " << *b << endl; 
} 

