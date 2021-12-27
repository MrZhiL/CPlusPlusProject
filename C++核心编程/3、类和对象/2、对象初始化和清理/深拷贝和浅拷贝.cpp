#include <iostream>
#include <cstdlib>

using namespace std;

	/* 深拷贝和浅拷贝 
	 * 
	 * 深浅拷贝是经典面试问题，也是常见的一个坑 
	 * 
	 * 浅拷贝：简单的赋值拷贝操作
	 * 浅拷贝带来的问题：就是堆区的内存重复释放 
	 * 编译器提供的拷贝构造函数，会做浅拷贝操作 
	 * 
	 * 深拷贝：在堆区重新申请空间，进行拷贝操作 
	 * 浅拷贝遇到的问题，需要用深拷贝来解决 
	 *
	 *********************************
	 * 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题 
	 ****************************************
	 */ 

class Person{
	
	public:
		Person(){
			cout << "Person默认(无参)构造函数" << endl;
		}
		
		Person(int age, float length){
			m_age = new int(age);
			// 通过new关键字在堆区开辟一个float内存空间，并将length赋值给m_length 
			m_length = new float(length);	
			cout << "Person有参构造函数" << endl;
		}
		
		// 该拷贝函数为浅拷贝，因为直接赋值为浅拷贝
		// 编译器自动提供的拷贝也为浅拷贝（因为是直接用等号赋值） 
		Person(const Person &p){
			//m_age = p.m_age;
			
			// 用new在堆区开辟新的内存，为深拷贝 
			m_age = new int(*p.m_age);
			
			//m_length = p.m_length;	// 编译器默认实现就是这行代码
			
			// 在堆区开辟新的内存，为深拷贝 
			m_length = new float(*p.m_length);
			
			cout << "Person拷贝构造函数" << endl;
		}
		
		~Person(){
			// 析构代码作用：将堆区开辟的数据进行释放 
			if (m_length != NULL){
				delete m_age;
				delete m_length;
				m_length = NULL;
			} 
			cout <<   "Person析构函数" << endl;
		}
		
		int *m_age;			// 年龄 
		float *m_length;	// 身高 
};

void test01(){
	
	Person p1(18,168);
	Person p2(p1);
	
	cout << "p1的年龄的地址为：" << p1.m_age << " ,p1的身高为(cm)： " << p1.m_length << endl;
		
	cout << "p2的年龄的地址为：" << p2.m_age << " ,p2的身高为(cm)： " << p2.m_length << endl;
//	cout << "p2的年龄的地址为：" << p2.m_age << " ,p2的身高为(cm)： " << p2.m_length << endl;
} 


int main(){
	
	test01();
	
	return 0;
} 
