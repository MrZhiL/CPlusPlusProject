#include <iostream>

using namespace std;

// C++���ṩ�˳�ʼ���б��﷨��������ʼ������
// �﷨�����캯��():����1(ֵ1),����2(ֵ2),����3(ֵ3)...{} 

class Person{
public:
	Person():m_A(10),m_B(20),m_C(30){
		cout << "Person1�Ĺ��캯��" << endl;
	}
	
//	// ԭʼ��ʼ��
//	Person(int a, int b, int c){
//		m_A = a;
//		m_B = b;
//		m_C = c;
//	} 
//	
	Person(int a, int b, int c):m_A(a),m_B(b),m_C(c){ //ע�⣺':"��Ҫ�ڹ��캯�����ź��� 
		cout << "Person1�Ĺ��캯��" << endl;
	}
	~Person(){
		cout << "Person1����������" << endl;
	}
	
	int m_A;
	int m_B;
	int m_C;
}; 

class Person2{
public:
	Person2():m_A(100){
		cout << "Person2�Ĺ��캯��" << endl;
	}
	~Person2(){
		cout << "Person2����������" << endl;
	} 
	
	Person p;
	int m_A;
};

int main(){
	Person p;
	cout << "p.m_A = " << p.m_A << "  p.m_B = " << p.m_B << "  p.m_C = " << p.m_C << endl;
	Person p2(30,20,10);
	cout << "p2.m_A = " << p2.m_A << "  p2.m_B = " << p2.m_B << "  p2.m_C = " << p2.m_C << endl;
	cout << "----------------------------"  << endl;
	Person2 p22;
	cout << "p22.m_A = " << p22.m_A << endl; 
	cout << "-----------------------------" <<endl;
} 
