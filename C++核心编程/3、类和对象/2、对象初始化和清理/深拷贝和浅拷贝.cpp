#include <iostream>
#include <cstdlib>

using namespace std;

	/* �����ǳ���� 
	 * 
	 * ��ǳ�����Ǿ����������⣬Ҳ�ǳ�����һ���� 
	 * 
	 * ǳ�������򵥵ĸ�ֵ��������
	 * ǳ�������������⣺���Ƕ������ڴ��ظ��ͷ� 
	 * �������ṩ�Ŀ������캯��������ǳ�������� 
	 * 
	 * ������ڶ�����������ռ䣬���п������� 
	 * ǳ�������������⣬��Ҫ���������� 
	 *
	 *********************************
	 * �ܽ᣺����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ�������������� 
	 ****************************************
	 */ 

class Person{
	
	public:
		Person(){
			cout << "PersonĬ��(�޲�)���캯��" << endl;
		}
		
		Person(int age, float length){
			m_age = new int(age);
			// ͨ��new�ؼ����ڶ�������һ��float�ڴ�ռ䣬����length��ֵ��m_length 
			m_length = new float(length);	
			cout << "Person�вι��캯��" << endl;
		}
		
		// �ÿ�������Ϊǳ��������Ϊֱ�Ӹ�ֵΪǳ����
		// �������Զ��ṩ�Ŀ���ҲΪǳ��������Ϊ��ֱ���õȺŸ�ֵ�� 
		Person(const Person &p){
			//m_age = p.m_age;
			
			// ��new�ڶ��������µ��ڴ棬Ϊ��� 
			m_age = new int(*p.m_age);
			
			//m_length = p.m_length;	// ������Ĭ��ʵ�־������д���
			
			// �ڶ��������µ��ڴ棬Ϊ��� 
			m_length = new float(*p.m_length);
			
			cout << "Person�������캯��" << endl;
		}
		
		~Person(){
			// �����������ã����������ٵ����ݽ����ͷ� 
			if (m_length != NULL){
				delete m_age;
				delete m_length;
				m_length = NULL;
			} 
			cout <<   "Person��������" << endl;
		}
		
		int *m_age;			// ���� 
		float *m_length;	// ��� 
};

void test01(){
	
	Person p1(18,168);
	Person p2(p1);
	
	cout << "p1������ĵ�ַΪ��" << p1.m_age << " ,p1�����Ϊ(cm)�� " << p1.m_length << endl;
		
	cout << "p2������ĵ�ַΪ��" << p2.m_age << " ,p2�����Ϊ(cm)�� " << p2.m_length << endl;
//	cout << "p2������ĵ�ַΪ��" << p2.m_age << " ,p2�����Ϊ(cm)�� " << p2.m_length << endl;
} 


int main(){
	
	test01();
	
	return 0;
} 
