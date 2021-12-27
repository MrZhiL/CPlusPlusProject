#include <iostream>

using namespace std;

// 1��ֵ����
void mySwap01(int a, int b){
	int temp;
	temp = a;
	a = b;
	b = temp;
} 

// 2����ַ����
void mySwap02(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
} 

// 3�������������β�--�͵�ַ���ݵ�Ч����ͬ�����﷨��������ֱ�� 
void mySwap03(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	
} 

int main(){
	
	//��������ʱ�������������õļ������β�����ʵ��
	//�ŵ㣺���Լ�ָ������ʵ��
	
	int i=10,j=20;
	
	int &ai = i;
	int &bj = j;
	
	cout << "0:i = " << i << endl;
	cout << "0:j = " << j << endl;
	cout << "0:ai = " << ai << endl;
	cout << "0:bj = " << bj << endl;
	
	mySwap01(i,j); // �βν��д��ݣ�ʵ�ε�ֵ���ᷢ���ı� 
	cout << "�βν��д��ݣ�ʵ�ε�ֵ���ᷢ���ı�" << endl;
	cout << "1:i = " << i << endl;
	cout << "1:j = " << j << endl;
	
	mySwap02(&i,&j); // ʹ�õ�ַ���в������ݣ�ʵ�ε�ֵ�ᷢ���ı� 
	cout << "ʹ�õ�ַ���в������ݣ�ʵ�ε�ֵ�ᷢ���ı�" << endl;
	cout << "2:i = " << i << endl;
	cout << "2:j = " << j << endl; 
	
//	mySwap03(ai,bj); 
	mySwap03(i,j); 
	cout << "������Ϊ�βΣ�ʵ�ε�ֵ�ᷢ���ı�" << endl; 
	cout << "3:i = " << i << endl;
	cout << "3:j = " << j << endl;
	
#if 0
	int* a = &i;
	int *b = &j;
	int *c = NULL;
	
//	*c = 100; // �����Զ�0-255�ĵ�ַ�ڴ渳ֵ����������ϵͳռ�õ� 
	
	cout << a << endl;
	cout << b << endl;
	cout << *c << endl;
#endif
		
	return 0;
} 
