#include <iostream>
#include <string>

using namespace std;

// 静态成员就是在成员变量和成员函数前加上关键字static，成为静态成员
// 静态成员分为：静态成员变量、静态成员函数
// 静态成员变量：所有对象共享同一份数据、在编译阶段分配内存、类内声明，类外初始化
// 静态成员函数：所有对象共享用一个函数、静态成员只能访问静态成员变量，不可访问非静态变量 
// 有两种访问方式：1、通过类名访问；2、通过对象访问 

// 静态成员函数也是有访问权限的； 

class Person{
	public:
		static void func(int a){
			m_a = a; // 静态成员函数只可访问静态成员变量，不可访问非静态成员变量 
//			m_b = 200; // 不可访问非静态成员变量,无法区分到底是那个对象的m_b的属性 
			cout << "This is a func function!" << endl;
		}
		
		static int m_a = 10; // 静态成员变量
		int m_b; // 非静态成员变量
		
	private:
		static void func2(){
			cout << "This is a func2 function!" << endl;
		}
		
}; 

// 需要初始化，要不然没法调用m_a (因为不能在类内初始化非const static变量)
//int Person::m_a = 10;

void test01(){
	
	//1、通过类名调用
	Person::func(100); 
	
	//2、通过对象访问(不需要创建对象就可访问) 
	Person p;
	p.func(11);
//	p.func2(); // private不可访问 
	cout << "p.m_a = " << p.m_a << endl;
}

void test02(){
	Person::func(1);	
	cout << "m_a = " << Person::m_a;
}
 
int main() {
	
	test01();
	
	test02();
	
	return 0;
}
