#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//掌握类模板中成员函数 类外实现

template<class T1, class T2>
class Person{
	public:
		// 声明构造函数和成员函数，在类外实现 
		Person(T1 name, T2 age);
		void showPerson();
		
	public:
		T1 m_Name;
		T2 m_Age;
};

// 类模板中的构造函数类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
	this->m_Name = name;
	this->m_Age = age;
} 

// 类模板的成员函数类外实现
template<class T1, class T2>
void Person<T1,T2>::showPerson(){
	cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
} 

void test01(){
	
	Person<string, int> p1("Jack", 21);
	p1.showPerson();
	
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0; 
}
