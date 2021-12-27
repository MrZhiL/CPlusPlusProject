#include <iostream>
#include <cmath>

using namespace std;

// 加号运算符重载
// 1、成员函数重载+号
// 2、全局函数重载+号 

class Person{
	public:
		
		void printAB(){
			cout << "m_A = " << m_A << "  "; 
			cout << "m_B = " << m_B << endl; 
		}
		
		// 1、通过成员函数重载了+号 
		Person operator+(Person &p){
			Person temp;
			temp.m_A = this->m_A + p.m_A;
			temp.m_B = this->m_B + p.m_B;
			return temp;
		}
		// 如果不使用重载，则需要每次命名一个新的函数名 
		Person PersonAddPerson(Person &p){
			Person temp;
			temp.m_A = this->m_A + p.m_A;
			temp.m_B = this->m_B + p.m_B;
			return temp;
		}
		
		int m_A;
		int m_B;
};

/** 
// 2、全局函数也可以重载
Person operator+(Person &p1, Person &p2){
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
} */

// 运算符重载 也可以发生函数重载
Person operator+(Person &p1, int num){
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test01(){
	
	Person p1,p2;
	
	p1.m_A = 10;
	p1.m_B = 20;
	
	p2.m_A = 11;
	p2.m_B = 22;
	
	// 成员函数本质调用
	//Person p3 = p1.PersonAddPerson(p2);
	// 全局函数的本质调用
	
	// 运算符重载 也可以发生函数重载
	Person p3 = p1 + 10;
	cout << "p3: " ;
	p3.printAB();
	
/**
	//Person p3 = operator+(p1,p2);
	// 如果是成员函数重载则：Person p4 = p1.operator+(p2)可以简化为：Person p4 = p1 + p2;  
	// 如果是全局函数重载则：Person p4 = operator+(p1,p2)可以简化为：Person p4 = p1 + p2;
*/	 
	Person p4 = p1 + p2; 
	cout << "p4: " ;
	p4.printAB();
}

int main(){
	
	int aa = 11;
	int bb = 22;
	int cc = aa + bb;
	cout << "c= " << cc << endl; 
	test01();
	
	system("pause");
	return 0;
} 

