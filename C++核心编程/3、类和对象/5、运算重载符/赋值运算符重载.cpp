#include <iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * 
 * C++ 编译器至少给一个类添加4个函数 
 * 1、默认构造函数（无参、函数体为空） 
 * 2、默认析构函数（无参，函数体为空） 
 * 3、默认拷贝函数，对其属性进行值拷贝 
 * 4、赋值运算符operator=，对属性进行值拷贝 (编译器提供的为浅拷贝)
 * * * * * * * * * * * * * * * * * * * * * * * * * 
 * 注意：如果类中有属性指向堆区，做赋值操作也会出现深浅拷贝问题 
 */

class Person{
	
	public:
		Person(int age){
			cout << "正在调用构造函数！" << endl;
			m_age = new int(age);
		}
		
		// 析构函数（在堆区开辟的空间需要有程序员自己释放） 
		~Person(){
			cout << "正在调用析构函数！" << endl;
			if(m_age != NULL){
				delete m_age;
				m_age = NULL;
			} 
		}
		
		// 重载赋值运算符=,如果要满足连续赋值(链式赋值)，则需要返回Person类型，而不是void类型 
		// 需要返回引用，而不是值（如果返回值则会进行值拷贝，再次调用该函数） 
		Person& operator= (Person &p){
			
			// 需要先判断当前是否有属性在堆区，如果有先释放干净，然厚再进行深拷贝 
			if(m_age != NULL){
				delete m_age;
				m_age = NULL;
			} 
			
			// 此时进行深拷贝，为m_age创建新的地址空间
			m_age = new int(*p.m_age); 
			
			return *this; 
		} 
		
		int *m_age;
	
}; 

void test01(){
	Person *p1 = new Person(18);
	Person p2(20),p3(10);
	
	*p1 = p3 = p2; // 赋值操作 

	cout << "p1的年龄为：" << *p1->m_age << endl;
	cout << "p2的年龄为：" << *p2.m_age << endl;
	cout << "p3的年龄为：" << *p3.m_age << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
