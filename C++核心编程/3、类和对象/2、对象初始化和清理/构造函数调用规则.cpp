#include <iostream>

using namespace std;

	/*默认情况下，C++编译器至少给一个类添加3个函数： 
	 * 1、默认构造函数(无参，函数体为空) 
	 * 2、默认析构函数(无参，函数体为空) 
	 * 3、默认拷贝构造函数，对属性进行值拷贝 
	 ***************************************** 
	 * 构造函数调用规则如下：
	 * 1、如果用户定义有参构造函数，C++不再提供默认无参构造函数，但是会提供默认拷贝构造 
	 * 2、如果用户定义拷贝构造函数，C++不会再提供其他构造函数 
	 */ 


class Person{
	
	public:
		Person(){
			cout << "Person默认构造函数" << endl;
		}
		Person(int a){
			m_age = a;
			cout << "Person有参构造函数" << endl;
		}
		Person(const Person &p){
			m_age = p.m_age; 
			cout << "Person拷贝构造函数" << endl;
		}
		
		~Person(){
			cout << "Person析构函数" << endl;
		}
		
		int m_age;
};


int main(){
	
	return 0;
}
