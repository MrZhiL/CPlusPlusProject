#include <iostream>

using namespace std;

// �̳е��﷨�� class ���� : �̳з�ʽ ����
// �̳з�ʽһ�������֣������̳С������̳С�˽�м̳� 

// ���� 
class Base{
	
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_c; 
	
};

// 1�������̳�
class son1:public Base{
	public: 
		void func(){
			m_A = 10;	// �����й���Ȩ�޵ĳ�Ա�����༯�ɺ���Ȼ�ǹ���Ȩ�� 
			m_B = 10;	// �����еı���Ȩ�޵ĳ�Ա������̳к���Ȼ�Ǳ���Ȩ��
			//m_C = 10;  // ������˽��Ȩ�޵ĳ�Ա�����಻�ɷ��� 
		}
	
};

class GrandSon1:public son1{
	public:
		void func(){
			m_A = 123;	// son1�й����̳�Base�࣬��˴�ʱm_A��m_B������û�иı䣬��ʱGrandSon��Ȼ���Լ̳�son1�� 
			m_B = 321;
		}
}; 

void test01(){
	son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;		// m_BΪ����Ȩ�ޣ������ⲻ�ɷ��ʣ�����������Ҳ���ɷ��ʣ�
	s1.func();
	
	cout << "m_A = " << s1.m_A << endl; 
}

// 2�������̳�
class son2:protected Base{
	public: 
		void func(){
			m_A = 10;	// �����й���Ȩ�޵ĳ�Ա������̳к� ��Ϊ ����Ȩ�ޣ�protected�� 
			m_B = 10;	// �����еı���Ȩ�޵ĳ�Ա������̳к���Ȼ�Ǳ���Ȩ��
			//m_C = 10;  // ������˽��Ȩ�޵ĳ�Ա�����಻�ɷ��ʣ����������Ի�̳� 
		}
	
};

class GrandSon2:public son2{
	public:
		void func(){
			m_A = 123;	// son1�й����̳�Base�࣬��˴�ʱm_A��m_B�����Ծ�Ϊprotected,������Լ̳У���ʱGrandSon��Ȼ���Լ̳�son2�� 
			m_B = 321;
		}
};

void test02(){
	son2 gs2;
	//gs2.m_A = 10;	// ��Ϊ son2�м̳е�m_A��m_B����ΪprotectedȨ�ޣ���ʱ���ⲻ�ɷ��� 
	//cout << gs2.m_A << endl;
} 

// 3��˽�м̳�
class son3:private Base{
	public: 
		void func(){
			m_A = 10;	// �����й���Ȩ�޵ĳ�Ա������̳к� ��Ϊ˽������ 
			m_B = 10;	// �����еı���Ȩ�޵ĳ�Ա������̳к� ��Ϊ˽������ 
			//m_C = 10;  // ������˽��Ȩ�޵ĳ�Ա�����಻�ɷ��� 
		}
	
};

class GrandSon3:public son3{
	public:
		void func(){
			//m_A = 123;	// son1�й����̳�Base�࣬��˴�ʱm_A��m_B������Ϊ˽�����ԣ���ʱGrandSon�����Լ̳�son3�� 
			//m_B = 321;
		}
};

int main(){
	
	test01();
	
	GrandSon1 gs1;
	gs1.func();
	cout << "m_A = " << gs1.m_A << endl;
	
	system("pause");
	return 0;
}
