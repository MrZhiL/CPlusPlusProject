#include <iostream>

using namespace std;

	/* ���������ĵ���ʱ���� 
	 * 1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶��� 
	 * 2��ʹ��ֵ���ݵķ�ʽ������������ֵ 
	 * 3��ֵ��ʽ���ؾֲ����� (��Visio Stdio�п��Թ۲쵽��������Dev-C++�й۲첻��)
	 */ 


class Person{
	
	public:
		Person(){
			cout << "PersonĬ�Ϲ��캯��" << endl;
		}
		Person(int a){
			m_age = a;
			cout << "Person�вι��캯��" << endl;
		}
		Person(const Person &p){
			m_age = p.m_age; 
			cout << "Person�������캯��" << endl;
		}
		
		~Person(){
			cout << "Person��������" << endl;
		}
		
		int m_age;
};

// 1��ʹ��һ���Ѿ�������ɵĶ�������ʼ��һ���¶���
void test01(){
	Person p1;
	Person p2(p1);
} 

// 2��ʹ��ֵ���ݵķ�ʽ��Ĭ�ϲ�����ֵ
void testWork(Person p){
	p.m_age = 100;
}
void test02(){
	Person p1(10);
	testWork(p1);
	cout << "p1������Ϊ��" << p1.m_age << endl;
} 

// 3��ֵ��ʽ���ؾֲ�����
Person testWork2(){
	Person p(10);
	cout << "testWork2��p�ĵ�ַΪ��" << &p << endl;
	return p;
}
void test03(){
	Person p = testWork2();
	cout << "test03��p�ĵ�ַΪ��" << &p << endl;
} 

int main(){
	
	//test01();
	//test02();
	test03();
	
	return 0;
} 
