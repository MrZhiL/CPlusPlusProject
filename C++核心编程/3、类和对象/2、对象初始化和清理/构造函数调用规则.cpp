#include <iostream>

using namespace std;

	/*Ĭ������£�C++���������ٸ�һ�������3�������� 
	 * 1��Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��) 
	 * 2��Ĭ����������(�޲Σ�������Ϊ��) 
	 * 3��Ĭ�Ͽ������캯���������Խ���ֵ���� 
	 ***************************************** 
	 * ���캯�����ù������£�
	 * 1������û������вι��캯����C++�����ṩĬ���޲ι��캯�������ǻ��ṩĬ�Ͽ������� 
	 * 2������û����忽�����캯����C++�������ṩ�������캯�� 
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


int main(){
	
	return 0;
}
