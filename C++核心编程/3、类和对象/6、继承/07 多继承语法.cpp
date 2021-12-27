#include <iostream>

using namespace std;

// ��̳��﷨

// C++����һ����̳ж����
// �﷨��class ����:�̳з�ʽ ����1, �̳з�ʽ ����2, ... 
// ��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������ 

// ��C++ʵ�ʿ����в�����ʹ�ö�̳� 

class Base1{
	public:
		
		Base1(){
			m_A = 100;
		}
		
		int m_A;
		
}; 

class Base2{
	public:
		
		Base2(){
			m_A = 111;
			m_B = 222;
		}
		
		int m_A;
		int m_B;
		
}; 

class Son : public Base1, public Base2{
	
	public:
		
		Son(){
			m_A = 1;
			m_B = 2;
			m_C = 3;
		}
		
		int m_A;
		int m_B;
		int m_C;
	
};

void test01(){
	
	Son s1;
	
	// ����̳и���󣬸��������еĳ�Ա��������̳У���������еĳ�Ա�����븸������������������ظ����е�������Ա 
	cout << "sizeof(Son) = " << sizeof(s1) << endl;
	
	cout << "Son::m_A = " << s1.m_A << endl;
	cout << "Son::m_B = " << s1.m_B << endl;
	cout << "Son::m_C = " << s1.m_C << endl;
	
	cout << "Son::Base1::m_A = " << s1.Base1::m_A << endl;
	cout << "Son::Base2::m_A = " << s1.Base2::m_A << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
}
