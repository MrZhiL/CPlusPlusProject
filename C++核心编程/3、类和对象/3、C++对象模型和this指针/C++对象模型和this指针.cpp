#include <iostream>

using namespace std;

// 成员变量和成员函数分开存储
// 在C++中，类内的成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上 

// 空对象占用内存空间为：1字节
// C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置。 
// 每个空对象也应该有油罐车独一无二的内存地址 

class emptyCl{
	
}; 

// this可以解决名称冲突
// 可以返回对象本身 return *this

class Person{
	public:
		// 无参构造函数 
		Person(){
			mA = 10;
		}
		
		// 非静态成员占用对象空间 
		int mA;
		int age; 
		// 静态成员变量不占用对象空间 ，不属于类的对象上 
		static int mB;
		// 函数也不占用对象空间，所以函数共享一个函数实例 
		void func(int age){
			// this指针指向被调用的成员函数所属的对象 
			this->age = age;
			cout << "mA:" << this->mA << endl;
		}
		
		// 如果返回引用(Person &)，则可以进行链式编程；如果返回值(Person )则只进行操作 
		// 返回值的时候会创建一个新对象，而引用则不会(引用时返回的是自己本身) 
		Person& addPersonAge(Person &p){
			this->age += p.age;
			
			// this 指向p2的指针，而*this指向p2这个本体 
			return *this;
		} 
		
		static int func2(){
			cout << "静态成员函数也不属于类的对象上" << endl; 
		}
	
}; 

int Person::mB = 0;


void test01(){
	Person p,p2;
	emptyCl ec;
	p.func(18);
	p.mB = 100;
	cout << "p1的年龄为:" << p.age << endl; 
	
	p2.func(20);
	// 链式编程思想 
	p2.addPersonAge(p).addPersonAge(p).addPersonAge(p);
	cout << "p2的年龄为：" << p2.age << endl; 
	
	// 只有非静态成员变量才占用类的空间 
	cout << "sizeof(p):" << sizeof(p) << endl; 
	cout << "sizeof(ec):" << sizeof(ec) << endl; 
} 

int main(){
	
	test01();
	
	system("pause"); 
	return 0;
}
