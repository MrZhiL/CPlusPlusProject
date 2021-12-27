#include <iostream>
#include <string>

using namespace std;

// ��̬��Ա�����ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա
// ��̬��Ա��Ϊ����̬��Ա��������̬��Ա����
// ��̬��Ա���������ж�����ͬһ�����ݡ��ڱ���׶η����ڴ桢���������������ʼ��
// ��̬��Ա���������ж�������һ����������̬��Աֻ�ܷ��ʾ�̬��Ա���������ɷ��ʷǾ�̬���� 
// �����ַ��ʷ�ʽ��1��ͨ���������ʣ�2��ͨ��������� 

// ��̬��Ա����Ҳ���з���Ȩ�޵ģ� 

class Person{
	public:
		static void func(int a){
			m_a = a; // ��̬��Ա����ֻ�ɷ��ʾ�̬��Ա���������ɷ��ʷǾ�̬��Ա���� 
//			m_b = 200; // ���ɷ��ʷǾ�̬��Ա����,�޷����ֵ������Ǹ������m_b������ 
			cout << "This is a func function!" << endl;
		}
		
		static int m_a = 10; // ��̬��Ա����
		int m_b; // �Ǿ�̬��Ա����
		
	private:
		static void func2(){
			cout << "This is a func2 function!" << endl;
		}
		
}; 

// ��Ҫ��ʼ����Ҫ��Ȼû������m_a (��Ϊ���������ڳ�ʼ����const static����)
//int Person::m_a = 10;

void test01(){
	
	//1��ͨ����������
	Person::func(100); 
	
	//2��ͨ���������(����Ҫ��������Ϳɷ���) 
	Person p;
	p.func(11);
//	p.func2(); // private���ɷ��� 
	cout << "p.m_a = " << p.m_a << endl;
}

void test02(){
	Person::func(1);	
	cout << "m_a = " << Person::m_a;
}
 
int main() {
	
	test01();
	
	test02();
	
	return 0;
}
