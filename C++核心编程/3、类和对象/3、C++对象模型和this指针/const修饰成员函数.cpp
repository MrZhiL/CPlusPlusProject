#include <iostream>

using namespace std;

// ������
// thisָ��ı�����һ��ָ�볣����ָ���ָ���ǲ����޸ĵ� 
class Person{
	public:
		
		// Ĭ�Ϲ��캯�� 
		Person(){
			
		}
		
		// thisָ��ı�����һ��ָ�볣����ָ���ָ���ǲ����޸ĵ� 
		// Person *const this; // ��const��void showPerson() const�е�cosntΪͬһ��const
		// �ڳ�Ա���������const�����ε�Ϊthisָ����ָ��ָ���ֵҲ�������޸� 
		void showPerson() const{ // ������ 
			//this->m_A = 100;
			//this->m_B = 100; 
			//this = NULL;	// thisָ�벻�����޸�ָ���ָ��� 
			cout << "m_A = " << m_A << endl;
			cout << "m_B = " << m_B << endl;
		} 
		
		void func(){
			cout << "this is func!@" << endl;
		}
		
		int m_A;
		mutable int m_B; 	// ����һ������ı�������ʹ�ڳ������У�Ҳ�����޸����ֵ���ӹؼ���mutable���� 
		
}; 		

void test01(){
	Person p;
	p.showPerson();
}

void test02(){
	
	const Person p; 		// ��ǰ�����const��Ϊ������
	//const int i = 10; 	// const���εı����ڶ���ʱ�����ʼ����Ҫ��Ȼ�ᱨ�� 
	//p.m_A = 1; 
	p.m_B = 11;	 // m_B������ֵ���ڳ�������Ҳ�����޸� 
	
	//p.func();    // ������ �����Ե�����ͨ��Ա������������ͨ��Ա���������޸����� 
	p.showPerson();	// ������ֻ�ܵ��ó����� 
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
