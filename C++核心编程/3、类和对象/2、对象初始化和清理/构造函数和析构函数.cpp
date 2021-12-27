#include <iostream>

using namespace std;

// 对象的初始化和清理

class Person{
	public:
		// 1、构造函数
		// 没有返回值，也不用写void
		// 函数名和类名相同
		// 构造函数可以有参数，可以发生重载
		// 创建对象的时候，构造函数会自动调用
		Person(){
			cout << "This is a Person Creation function!" << endl;
		} 
		
		// 2、析构函数 进行清理的操作
		// 没有返回值 不同写void
		// 函数名和类名相同(前面加上~)，不可以有参数，不可以发生重载
		// 对象在销毁前会自动调用析构函数，且只调用一次 
		~Person(){
			cout << "This is a Person Destruct function!" << endl;
		} 
		 
}; 

// 析构函数和构造函数是必须要有的实现，如果我们自己不提供，则编译器会提供一个空实现的构造和析构函数 
void test01(){
	Person p1;	// 在栈上的数据，test01调用结束后就会释放 
}

int main(){
	
	Person p; 
	
	test01();
//	test01();
	
	return 0;
} 
