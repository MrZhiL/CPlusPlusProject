#include <iostream>
#include <string>
using namespace std;

// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

// 解决方案：将父类中的析构函数改为虚析构或者纯虚析构

// 虚析构和纯虚析构的共性：
// 1、可以解决父类指针释放子类对象
// 2、都需要有具体的函数实现

// 虚析构和纯虚析构的区别：如果是纯虚析构，该类属于抽象类，无法实例化对象

class Animal{
	
	public:
		Animal(){
			cout << "Animal构造函数的调用！" << endl;
		}
		
		virtual void speak() = 0; 
		
//		// 利用虚析构可以解决父类指针释放对象时不干净的问题 
//		virtual ~Animal(){
//			cout << "Animal虚析构函数的调用！" << endl;
//		}
		
		// 纯虚析构函数：需要声明、也需要实现 
		virtual ~Animal() = 0; 
	
}; 

Animal::~Animal()  {
	cout << "Animal纯虚析构函数!" << endl;
}

class Cat : public Animal{
	
	public:
		
		Cat(string name){
			m_Name = new string(name);
			cout << "Cat类构造函数的调用！" << endl; 
		}
		
		virtual void speak(){
			cout << *m_Name << "小猫在说话！" << endl; 
		}
		
		~Cat(){
			cout << "Cat类析构函数的调用！" << endl; 
			
			// 释放堆区开辟的内存
			if(m_Name != NULL){
				delete m_Name;
				m_Name = NULL;
			} 
		}
		
		string *m_Name;
	
};

void test01(){
	
	Animal *cat1 = new Cat("Tom");

	cat1->speak();
	// 父类指针在析构的时候，不会调用子类中的析构函数，导致子类如果有堆区属性，会出线内存泄露 
	// 需要释放在堆区开辟的内存
	delete cat1; 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
