#include <iostream>

using namespace std;

// C++中提供了初始化列表语法，用来初始化属性
// 语法：构造函数():属性1(值1),属性2(值2),属性3(值3)...{} 

class Person{
public:
	Person():m_A(10),m_B(20),m_C(30){
		cout << "Person1的构造函数" << endl;
	}
	
//	// 原始初始化
//	Person(int a, int b, int c){
//		m_A = a;
//		m_B = b;
//		m_C = c;
//	} 
//	
	Person(int a, int b, int c):m_A(a),m_B(b),m_C(c){ //注意：':"需要在构造函数括号后面 
		cout << "Person1的构造函数" << endl;
	}
	~Person(){
		cout << "Person1的析构函数" << endl;
	}
	
	int m_A;
	int m_B;
	int m_C;
}; 

class Person2{
public:
	Person2():m_A(100){
		cout << "Person2的构造函数" << endl;
	}
	~Person2(){
		cout << "Person2的析构函数" << endl;
	} 
	
	Person p;
	int m_A;
};

int main(){
	Person p;
	cout << "p.m_A = " << p.m_A << "  p.m_B = " << p.m_B << "  p.m_C = " << p.m_C << endl;
	Person p2(30,20,10);
	cout << "p2.m_A = " << p2.m_A << "  p2.m_B = " << p2.m_B << "  p2.m_C = " << p2.m_C << endl;
	cout << "----------------------------"  << endl;
	Person2 p22;
	cout << "p22.m_A = " << p22.m_A << endl; 
	cout << "-----------------------------" <<endl;
} 
