#include <iostream>

using namespace std;

// �̳�ͬ����̬��Ա����ʽ
// question: �̳���ͬ���ľ�̬��Ա�������������ν��з���
// ��̬��Ա�ͷǾ�̬��Ա����ͬ��----�Ĵ���ʽһ�� 
// 1����������ͬ����Ա---ֱ�ӷ��ʼ���
// 2�����ʸ���ͬ����Ա----��Ҫ��������

class Base{
	
	public:
		static int m_A;
		
		static void func(){
			cout << "Base::static void func() !!" << endl;
		}
		
		void func(int a){
			m_A = a;
			cout << "Base::void func(int a) !!" << endl;
		}
}; 

// ʹ�þ�̬��Ա����ʱ�����еľ�̬��Ա������Ҫ����������ʼ������������ 
int Base::m_A = 22;

class Son : public Base{
	
	public: 
		static int m_A;
		
//		void func(int a){
//			cout << "Son::void func(int a) !!" << endl;
//		}
		
		static void func(){
			cout << "Son::static void func() !!" << endl;
		} 
	
};
// ʹ�þ�̬��Ա����ʱ�����еľ�̬��Ա������Ҫ����������ʼ������������ 
int Son::m_A = 11;

void test01(){
	
	Son s1;
	
	// ��̬ͬ����Ա�����ķ��� 
	cout << "--------- ��̬ͬ����Ա���� -----------" << endl; 
	
	cout << "-----ͨ���������ͬ����Ա����-----" << endl;
	cout << "Son::static m_A = " << s1.m_A << endl; 
	cout << "Base::static m_A = " << s1.Base::m_A << endl << endl; 
	
	cout << "-----ͨ����������ͬ����Ա����-----" << endl;
	cout << "Son::m_A = " << Son::m_A << endl;
	cout << "Base::m_A = " << Son::Base::m_A << endl << endl;
	
	
	// ��̬ͬ����Ա�亯���ķ��� 
	cout << "--------- ��̬��Ա���� -----------" << endl; 
	
	cout << "-----ͨ���������ͬ����Ա����-----" << endl;
	// �����е�ͬ����̬��Ա���� �� ���ظ��������е�ͬ��������������̬�ͷǾ�̬��Ա������ 
	// �������ʸ����е�ͬ����Ա���� ��Ҫ�������� 
	s1.func(); 
	s1.Base::func();
//	s1.func(10);
	s1.Base::func(100);
	cout <<  "Son::m_A = " << s1.m_A << endl;
	cout <<  "Son::Base::m_A = " << s1.Base::m_A << endl;
	
	cout << "-----ͨ����������ͬ����Ա����-----" << endl;
	Son::func();
	Son::Base::func();
//    Son::Base::func(100);
	cout <<  "Son::Base::m_A = " << Son::Base::m_A << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
