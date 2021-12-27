#include <iostream>

using namespace std;

// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据？

// 1、访问子类成员时，可以直接访问
// 2、访问父类成员时，需要加作用域

// note:如何子类中出现和父类中同名的成员函数，子类的同名成员函数会隐藏所有父类中的同名成员函数
// note:如果想访问父类中被隐藏的同名成员函数，需要加作用域 

class Base{
	
	public:
		
		Base(){
			m_A = 1;
			m_B = 22;
			m_C = 33;
		}
		
		void func(){
			cout << "This is Base class function ---- func() !!" << endl;
		}
		
		void func(int a){
			cout << "This is Base class function ----- func(int a) !!" << endl;
		} 
		
		int m_A;
		int m_B;
		int m_C;
	
}; 

class Son1 : public Base{
	public:
		
		Son1(){
			
		}
		
		void func1(){
			
			m_A = 11;
			m_B = 12;
			m_C = 13;
			
		}
		
		void func(){
			cout << "This is Son class of Base class function ---- func() !!" << endl;
		}
		
		int m_A;
};

void test01(){
	
	Son1 s1;
	
	cout << "---------继承中成员变量同名的调用---------------" << endl; 
	s1.func1();
//	s1.Base();
	
	cout << "Son1中的m_A = " << s1.m_A << endl;
	cout << "继承的Base类中的m_A = " << s1.Base::m_A<< endl;
	cout << "Son1中继承的m_B = " << s1.m_B << endl;
	cout << "Son1中继承的m_C = " << s1.m_C << endl;
	cout << endl;
	
	cout << "---------继承中成员函数同名的调用---------------" << endl;
	// 如果子类中成员函数与父类中成员函数同名，则 直接调用的为 子类中的成员函数 
	s1.func();
	// 如何调用父类中的同名成员函数----需要加作用域
	s1.Base::func(); 
	s1.Base::func(10);
}


int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
