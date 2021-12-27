#include <iostream>

using namespace std;

// 常函数
// this指针的本质是一个指针常量，指针的指向是不可修改的 
class Person{
	public:
		
		// 默认构造函数 
		Person(){
			
		}
		
		// this指针的本质是一个指针常量，指针的指向是不可修改的 
		// Person *const this; // 该const和void showPerson() const中的cosnt为同一个const
		// 在成员函数后面加const，修饰的为this指向，让指针指向的值也不可以修改 
		void showPerson() const{ // 常函数 
			//this->m_A = 100;
			//this->m_B = 100; 
			//this = NULL;	// this指针不可以修改指针的指向的 
			cout << "m_A = " << m_A << endl;
			cout << "m_B = " << m_B << endl;
		} 
		
		void func(){
			cout << "this is func!@" << endl;
		}
		
		int m_A;
		mutable int m_B; 	// 这是一个特殊的变量，即使在常函数中，也可以修改这个值，加关键字mutable即可 
		
}; 		

void test01(){
	Person p;
	p.showPerson();
}

void test02(){
	
	const Person p; 		// 在前面加上const变为常对象
	//const int i = 10; 	// const修饰的变量在定义时必须初始化，要不然会报错 
	//p.m_A = 1; 
	p.m_B = 11;	 // m_B是特殊值，在常对象下也可以修改 
	
	//p.func();    // 常对象 不可以调用普通成员函数，因子普通成员函数可以修改属性 
	p.showPerson();	// 常对象只能调用常函数 
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
