#include <iostream>

using namespace std;

// 类模板中的成员函数的创建 与 普通成员函数的创建是有区别的：
// 1、普通成员函数在一开始就可以创建
// 2、类模板中的成员函数在使用时才创建

class Person1{
	
	public:
		void ShowPerson1(){
			cout << "Person1 ShowFunction!" << endl;
		}
}; 

class Person2{
	
	public:
		void ShowPerson2(){
			cout << "Person2 ShowFunction!" << endl;
		}
};

template<class T>
class MyClass{
	
	public:
		T Per;
		
		// func1和func2可以调用ShowPerson1()和ShowPerson2()函数是因为，编译器此时无法确定 T 的数据类型
		// 因此该func1和func2函数尚未创建，只有调用该函数时才创建该函数 
		void func1(){
			Per.ShowPerson1();
		} 
		
		void func2(){
			Per.ShowPerson2();
		}
	
};

void test01(){
	
	MyClass<Person1> myc;
	myc.func1();	// 只是指定T为Person1类型，如果调用func1函数，则先创建该函数，在调用 
	//myc.func2();    // 如果指定T为Person1的自定义数据类型，则不可调用func2函数，因为Person1和Person2数据类型不同 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
