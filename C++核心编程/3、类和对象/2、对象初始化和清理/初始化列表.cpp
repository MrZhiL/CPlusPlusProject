#include <iostream>
#include <cstdlib>

using namespace std;

	/* ��ʼ���б� 
	 * C++���ṩ�˳�ʼ���б��﷨��������ʼ������ 
	 * �﷨�����캯��(): ����1(ֵ1), ����2(ֵ2), ..... {}
	 * 
	 */ 

class Person{
	
	public:
		
		// ��ʼ���б���ʼ������ 
		Person(int age, float length, float weight): m_age(age), m_length(length), m_weight(weight){
			cout << "Person��ʼ�����Թ��캯��" << endl;
		}
/**		
		Person(int age, float length, float weight){
			m_age = age;
			m_length = length;	
			m_length = weight;
			cout << "Person�вι��캯��" << endl;
		}
*/		
		Person(const Person &p){
			m_age = p.m_age;
			m_length = p.m_length;
			m_weight = p.m_weight;
			cout << "Person�������캯��" << endl;
		}
		
		~Person(){
			cout <<   "Person��������" << endl;
		}
		
		int m_age;		// ���� 
		float m_length;	// ��� 
		float m_weight;	// ���� 
};


int main(){
	
	Person p(10,150,40);
	
//	p.m_age = 20;
	
	cout << "p.age = " << p.m_age << endl;
	cout << "p.length = " << p.m_length << endl;
	cout << "p.weigth = " << p.m_weight << endl;
		
	return 0;
}
