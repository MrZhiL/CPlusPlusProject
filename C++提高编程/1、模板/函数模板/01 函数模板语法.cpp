#include <iostream>

using namespace std;

// ����ģ�� 

/**
����ģ��ע������
	1���Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
	2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ�� 
*/			

// ����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ����ͨ���������� 
template<typename T>
void MySwap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

// ������������
void swapInt(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

// ��������������
void swapDouble(double &a, double &b){
	double temp = a;
	a = b;
	b = temp;
} 

void test01(){
	
	int a = 10;
	int b = 20;
	
	//swapInt(a,b);
	// ʹ��ģ�彻�������ַ�ʽ��1���Զ��Ƶ����ͣ��������Զ��Ƶ��������� �� 2��ָ����������
	// 1���Զ��Ƶ�����
	MySwap(a,b); 
	cout << "������a = " << a << "  b = " << b << endl; 

	double c = 1.20;
	double d = 2.40;
	
	// 2��ָ���������� 
	//swapDouble(c,d);
	MySwap<double>(c,d);
	cout << "������c = " << c << "  d = " << d << endl; 	
}


int main(){
	
	test01();
	
	system("pause");
	return 0;
}
