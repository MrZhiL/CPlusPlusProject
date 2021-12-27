#include <iostream>
#include <string>
using namespace std; 

// 类模板和函数模板的区别
// 1、类模板没有自动类型推导的使用方式
// 2、类模板在模板参数列表中可以有默认参数 

template<class NameType, class AgeType = int>
class Person{
	
	public:
		Person(NameType name, AgeType age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		void showPerson(){
			cout << "name：" << this->m_Name << "  age：" << this->m_Age << endl;			
		}
		
		NameType m_Name;
		AgeType m_Age;
	
};

void test01(){
	
	// 1、类模板中没有自动类型推导
	//Person p1("孙悟空",999); 	// 错误 
	Person<string, int> p2("孙悟空",999); // 正确，类模板只能使用指定类型
	p2.showPerson(); 
	
	// 2、类模板中的参数列表可以指定默认参数
	Person<string> p3("猪八戒",998);
	p3.showPerson();
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
