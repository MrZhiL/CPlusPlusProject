#include <iostream>

using namespace std;

// ���⣺�������븸�����ͬ���ĳ�Ա�����ͨ��������󣬷��ʵ����������ͬ�������ݣ�

// 1�����������Աʱ������ֱ�ӷ���
// 2�����ʸ����Աʱ����Ҫ��������

// note:��������г��ֺ͸�����ͬ���ĳ�Ա�����������ͬ����Ա�������������и����е�ͬ����Ա����
// note:�������ʸ����б����ص�ͬ����Ա��������Ҫ�������� 

class Base{
	
	public:
		
		Base(){
			m_A = 1;
			m_B = 22;
			m_C = 33;
		}
		
		void func(){
			cout << "This is Base class function ---- func() !!" << endl;
		}
		
		void func(int a){
			cout << "This is Base class function ----- func(int a) !!" << endl;
		} 
		
		int m_A;
		int m_B;
		int m_C;
	
}; 

class Son1 : public Base{
	public:
		
		Son1(){
			
		}
		
		void func1(){
			
			m_A = 11;
			m_B = 12;
			m_C = 13;
			
		}
		
		void func(){
			cout << "This is Son class of Base class function ---- func() !!" << endl;
		}
		
		int m_A;
};

void test01(){
	
	Son1 s1;
	
	cout << "---------�̳��г�Ա����ͬ���ĵ���---------------" << endl; 
	s1.func1();
//	s1.Base();
	
	cout << "Son1�е�m_A = " << s1.m_A << endl;
	cout << "�̳е�Base���е�m_A = " << s1.Base::m_A<< endl;
	cout << "Son1�м̳е�m_B = " << s1.m_B << endl;
	cout << "Son1�м̳е�m_C = " << s1.m_C << endl;
	cout << endl;
	
	cout << "---------�̳��г�Ա����ͬ���ĵ���---------------" << endl;
	// ��������г�Ա�����븸���г�Ա����ͬ������ ֱ�ӵ��õ�Ϊ �����еĳ�Ա���� 
	s1.func();
	// ��ε��ø����е�ͬ����Ա����----��Ҫ��������
	s1.Base::func(); 
	s1.Base::func(10);
}


int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
