#include <iostream>
#include <string>

using namespace std;

// ���ع�ϵ�����

class Person{
	
	public:
		
		Person(string name, int age){
			m_name = name;
			m_age = age;
		}
		
		// ����==�������������������䶼��ȣ�����Ϊ��������� 
		bool operator== (Person &p){
			if(this->m_name == p.m_name){
				if(this->m_age == p.m_age){
					return true;
				}else{
					return false;
				}
			}
			
			return false; 
		}
		
		// ����!=�����
		bool operator!= (Person &p){
			if( (this->m_name != p.m_name) || (this->m_age != p.m_age)){
				return true;
			}else {
				return false;
			}
		} 
		
		string m_name;
		int    m_age;
}; 

void test01(){
	
	Person p1("jack",18);
	Person p2("jack",19);
	
	if (p1 == p2){
		cout << "p1 is equal to p2!" << endl;
	}else if(p1 != p2){
		cout << "p1 is no equal to p2!" << endl;
	}
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
