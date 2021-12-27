#include <iostream>
#include <string>
using namespace std;

// 类模板的语法：
// 类模板和函数模板的语法非常类似，在template后面直接加class 

template<class NameType, class AgeType>
class Person{
	
	public:
		
		Person(NameType name, AgeType age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		void showFunc(){
			cout << "name:" << this->m_Name <<"  age:" << this->m_Age << endl; 
		}
		
		NameType m_Name;
		AgeType m_Age;
	
};

void test01(){
	
	Person<string,int> p1("lisi",999);
	
	p1.showFunc();
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
