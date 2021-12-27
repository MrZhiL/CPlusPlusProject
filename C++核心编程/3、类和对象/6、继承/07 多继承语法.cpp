#include <iostream>

using namespace std;

// 多继承语法

// C++允许一个类继承多个类
// 语法：class 子类:继承方式 父类1, 继承方式 父类2, ... 
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分 

// 在C++实际开发中不建议使用多继承 

class Base1{
	public:
		
		Base1(){
			m_A = 100;
		}
		
		int m_A;
		
}; 

class Base2{
	public:
		
		Base2(){
			m_A = 111;
			m_B = 222;
		}
		
		int m_A;
		int m_B;
		
}; 

class Son : public Base1, public Base2{
	
	public:
		
		Son(){
			m_A = 1;
			m_B = 2;
			m_C = 3;
		}
		
		int m_A;
		int m_B;
		int m_C;
	
};

void test01(){
	
	Son s1;
	
	// 子类继承父类后，父类中所有的成员变量都会继承，如果子类中的成员变量与父类重名，则子类会隐藏父类中的重名成员 
	cout << "sizeof(Son) = " << sizeof(s1) << endl;
	
	cout << "Son::m_A = " << s1.m_A << endl;
	cout << "Son::m_B = " << s1.m_B << endl;
	cout << "Son::m_C = " << s1.m_C << endl;
	
	cout << "Son::Base1::m_A = " << s1.Base1::m_A << endl;
	cout << "Son::Base2::m_A = " << s1.Base2::m_A << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
}
