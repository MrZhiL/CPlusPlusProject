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
			
			// 这里的m_age相当于this->m_age 。因为*p中传入的为空指针，所以会报错 
			cout << "age = " << m_age << endl;
		}
	
		int m_age;
};

void test01(){
	
	Person *p = NULL;
	
	
	p->showPersonClass();	//该行代码可以正常调用 
	p->showPersonAge();		//该行代码不可运行 
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
