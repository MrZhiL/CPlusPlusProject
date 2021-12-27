#include <iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * 
 * C++ ���������ٸ�һ�������4������ 
 * 1��Ĭ�Ϲ��캯�����޲Ρ�������Ϊ�գ� 
 * 2��Ĭ�������������޲Σ�������Ϊ�գ� 
 * 3��Ĭ�Ͽ����������������Խ���ֵ���� 
 * 4����ֵ�����operator=�������Խ���ֵ���� (�������ṩ��Ϊǳ����)
 * * * * * * * * * * * * * * * * * * * * * * * * * 
 * ע�⣺�������������ָ�����������ֵ����Ҳ�������ǳ�������� 
 */

class Person{
	
	public:
		Person(int age){
			cout << "���ڵ��ù��캯����" << endl;
			m_age = new int(age);
		}
		
		// �����������ڶ������ٵĿռ���Ҫ�г���Ա�Լ��ͷţ� 
		~Person(){
			cout << "���ڵ�������������" << endl;
			if(m_age != NULL){
				delete m_age;
				m_age = NULL;
			} 
		}
		
		// ���ظ�ֵ�����=,���Ҫ����������ֵ(��ʽ��ֵ)������Ҫ����Person���ͣ�������void���� 
		// ��Ҫ�������ã�������ֵ���������ֵ������ֵ�������ٴε��øú����� 
		Person& operator= (Person &p){
			
			// ��Ҫ���жϵ�ǰ�Ƿ��������ڶ�������������ͷŸɾ���Ȼ���ٽ������ 
			if(m_age != NULL){
				delete m_age;
				m_age = NULL;
			} 
			
			// ��ʱ���������Ϊm_age�����µĵ�ַ�ռ�
			m_age = new int(*p.m_age); 
			
			return *this; 
		} 
		
		int *m_age;
	
}; 

void test01(){
	Person *p1 = new Person(18);
	Person p2(20),p3(10);
	
	*p1 = p3 = p2; // ��ֵ���� 

	cout << "p1������Ϊ��" << *p1->m_age << endl;
	cout << "p2������Ϊ��" << *p2.m_age << endl;
	cout << "p3������Ϊ��" << *p3.m_age << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
