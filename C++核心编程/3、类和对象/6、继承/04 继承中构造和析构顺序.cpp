#include <iostream>

using namespace std;

// ����̳и���󣬵������������Ҳ����ø���Ĺ��캯��
// ���⣺���������Ĺ��������������˳����˭��˭��?
// ���ȵ��ø���Ĺ��캯�����ڵ�������Ĺ��캯��
//     ��������ʱ���ȵ��� ��������������� �ڵ��� ������������� 

class Base{
	public:
		
		Base(){
			cout << "This is Base class Creation function!" << endl; 
		}
		~Base(){
			cout << "This is Base class Decreation function!" << endl;
		}
		
		int m_A;
}; 

class Son : public Base{
	public:
		
		Son(){
			cout << "This is Son class of Base Creation function!" << endl;
		}
		~Son(){
			cout << "This is Son class of Base Decreation function!" << endl;
		}
		
		int m_B;
};

void test01(){
	
	
	// �ȹ��츸�࣬�ٹ������ࣻ��������˳���빹�캯���෴ 
	Son s1;
	s1.m_A = 10;
	s1.m_B = 20;
	
	cout << "m_A = " << s1.m_A << endl;
	cout << "m_B = " << s1.m_B << endl;
}

int main(){
	
	test01();
		
	system("pause");
	return 0;
} 
