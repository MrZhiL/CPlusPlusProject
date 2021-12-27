#include <iostream>

using namespace std;

	/* 拷贝函数的调用时机： 
	 * 1、使用一个已经创建完毕的对象来初始化一个新对象 
	 * 2、使用值传递的方式给函数参数传值 
	 * 3、值方式返回局部对象 (在Visio Stdio中可以观察到，但是在Dev-C++中观察不到)
	 */ 


class Person{
	
	public:
		Person(){
			cout << "Person默认构造函数" << endl;
		}
		Person(int a){
			m_age = a;
			cout << "Person有参构造函数" << endl;
		}
		Person(const Person &p){
			m_age = p.m_age; 
			cout << "Person拷贝构造函数" << endl;
		}
		
		~Person(){
			cout << "Person析构函数" << endl;
		}
		
		int m_age;
};

// 1、使用一个已经创建完成的对象来初始化一个新对象
void test01(){
	Person p1;
	Person p2(p1);
} 

// 2、使用值传递的方式给默认参数赋值
void testWork(Person p){
	p.m_age = 100;
}
void test02(){
	Person p1(10);
	testWork(p1);
	cout << "p1的年龄为：" << p1.m_age << endl;
} 

// 3、值方式返回局部对象
Person testWork2(){
	Person p(10);
	cout << "testWork2中p的地址为：" << &p << endl;
	return p;
}
void test03(){
	Person p = testWork2();
	cout << "test03中p的地址为：" << &p << endl;
} 

int main(){
	
	//test01();
	//test02();
	test03();
	
	return 0;
} 
