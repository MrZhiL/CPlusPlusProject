#include <iostream>

using namespace std;

// 继承同名静态成员处理方式
// question: 继承中同名的静态成员在子类对象中如何进行访问
// 静态成员和非静态成员出现同名----的处理方式一致 
// 1、访问子类同名成员---直接访问即可
// 2、访问父类同名成员----需要加作用域

class Base{
	
	public:
		static int m_A;
		
		static void func(){
			cout << "Base::static void func() !!" << endl;
		}
		
		void func(int a){
			m_A = a;
			cout << "Base::void func(int a) !!" << endl;
		}
}; 

// 使用静态成员变量时，类中的静态成员变量需要在类外做初始化！！！！！ 
int Base::m_A = 22;

class Son : public Base{
	
	public: 
		static int m_A;
		
//		void func(int a){
//			cout << "Son::void func(int a) !!" << endl;
//		}
		
		static void func(){
			cout << "Son::static void func() !!" << endl;
		} 
	
};
// 使用静态成员变量时，类中的静态成员变量需要在类外做初始化！！！！！ 
int Son::m_A = 11;

void test01(){
	
	Son s1;
	
	// 静态同名成员变量的访问 
	cout << "--------- 静态同名成员变量 -----------" << endl; 
	
	cout << "-----通过对象访问同名成员变量-----" << endl;
	cout << "Son::static m_A = " << s1.m_A << endl; 
	cout << "Base::static m_A = " << s1.Base::m_A << endl << endl; 
	
	cout << "-----通过类名访问同名成员变量-----" << endl;
	cout << "Son::m_A = " << Son::m_A << endl;
	cout << "Base::m_A = " << Son::Base::m_A << endl << endl;
	
	
	// 静态同名成员变函数的访问 
	cout << "--------- 静态成员函数 -----------" << endl; 
	
	cout << "-----通过对象访问同名成员变量-----" << endl;
	// 子类中的同名静态成员函数 会 隐藏父类中所有的同名函数（包括静态和非静态成员函数） 
	// 如果想访问父类中的同名成员函数 需要加作用域 
	s1.func(); 
	s1.Base::func();
//	s1.func(10);
	s1.Base::func(100);
	cout <<  "Son::m_A = " << s1.m_A << endl;
	cout <<  "Son::Base::m_A = " << s1.Base::m_A << endl;
	
	cout << "-----通过类名访问同名成员变量-----" << endl;
	Son::func();
	Son::Base::func();
//    Son::Base::func(100);
	cout <<  "Son::Base::m_A = " << Son::Base::m_A << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
