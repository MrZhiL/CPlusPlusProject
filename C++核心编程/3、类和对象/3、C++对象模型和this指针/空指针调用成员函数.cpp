#include <iostream>

using namespace std;

class Person{
	
	public:
		void showPersonClass(){
			cout << "This is a Person Class!" << endl; 
		}
		
		void showPersonAge(){
			
			if(this == NULL){
				return;
			}
			
			// �����m_age�൱��this->m_age ����Ϊ*p�д����Ϊ��ָ�룬���Իᱨ�� 
			cout << "age = " << m_age << endl;
		}
	
		int m_age;
};

void test01(){
	
	Person *p = NULL;
	
	
	p->showPersonClass();	//���д�������������� 
	p->showPersonAge();		//���д��벻������ 
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
