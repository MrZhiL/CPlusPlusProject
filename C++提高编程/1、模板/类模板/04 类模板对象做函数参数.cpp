#include <iostream>
#include <string> 
#include <typeinfo>
using namespace std;

// 类模板对象做函数参数
// 1、直接传入指定数据类型
// 2、将参数模板化 
// 3、将整个类进行模板化 

// 总结：在工程中，最常用的方法是法一：直接传入指定数据类型（该方式简单，如果再将参数或类模板化，会变得较为复杂） 

template<class T1, class T2>
class Person{
	
	public:
		
		Person(T1 name, T2 age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		void showPerson(){
			cout << "name: " << this->m_Name << "  age: " << this->m_Age << endl; 
		}
				
		string m_Name;
		int m_Age;
	
}; 

// 1、直接指定传输参数
void showPerson01(Person<string, int> &p){
	p.showPerson();
}

// 2、类参数模板化
template<class T1, class T2>
void showPerson02(Person<T1, T2> &p){
	p.showPerson();
	cout << "T1的数据类型为: " << typeid(T1).name() << endl;
	cout << "T2的数据类型为：" << typeid(T2).name() << endl; 
} 

// 3、将整个类模板化
template<class T>
void showPerson03(T &p){
	p.showPerson();
	cout << "T的数据类型为: " << typeid(T).name() << endl;
} 

void test01(){
	
	// 1、调用 传输具体参数函数 
	Person<string, int> p("孙悟空", 999);
	showPerson01(p);
	
	// 2、调用 类参数模板化函数 
	Person<string, int> p2("猪八戒", 998); 
	showPerson02(p2);
	
	// 3、调用 整个类模板化
	Person<string, int> p3("唐僧", 100); 
	showPerson03(p3); 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
