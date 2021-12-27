#include <iostream>

using namespace std;

// 左移运算符重载
// 可以输出自定义数据类型 

class Person{
	public:
		
		// 利用成员函数重载 左移运算符
		// p.operator << (cout) 的简化版本为：p << cout；
		// 通常不用利用成员函数重载<< 运算符，因为无法实现cout在左侧
	/**
		ostream & operator<< (ostream &cout){
			cout << "m_A = " << this->m_A << " ,m_B = " << this->m_B;
			return cout;
		} */
		
		void leftMove(int a){
			this->m_A = a;
			this->m_B = 10;
			this->m_A  = this->m_A << 2;
			this->m_A << 1;
		}
		
		int m_A;
		int m_B;
};

// 只能利用全局函数重载左移运算符 
// operator<< (ostream &cout, Person &p)本质为：(简化) cout << p 
// cout 可以换成别的名字：out、。。。 
ostream & operator<< (ostream &cout, Person &p){
	cout << "m_A = " << p.m_A << " ,m_B = " << p.m_B;
	return cout;
}

void test01(){
	Person p;
	p.leftMove(1);
//	p.m_A = 1;
	cout << p << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
