#include <iostream>

using namespace std;

// 子类继承父类后，当创建子类对象，也会调用父类的构造函数
// 问题：父类和子类的构造和析构函数的顺序是谁先谁后?
// 答：先调用父类的构造函数，在调用子类的构造函数
//     析构函数时，先调用 子类的析构函数， 在调用 父类的析构函数 

class Base{
	public:
		
		Base(){
			cout << "This is Base class Creation function!" << endl; 
		}
		~Base(){
			cout << "This is Base class Decreation function!" << endl;
		}
		
		int m_A;
}; 

class Son : public Base{
	public:
		
		Son(){
			cout << "This is Son class of Base Creation function!" << endl;
		}
		~Son(){
			cout << "This is Son class of Base Decreation function!" << endl;
		}
		
		int m_B;
};

void test01(){
	
	
	// 先构造父类，再构造子类；析构函数顺序与构造函数相反 
	Son s1;
	s1.m_A = 10;
	s1.m_B = 20;
	
	cout << "m_A = " << s1.m_A << endl;
	cout << "m_B = " << s1.m_B << endl;
}

int main(){
	
	test01();
		
	system("pause");
	return 0;
} 
