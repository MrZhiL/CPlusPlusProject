#include <iostream>

using namespace std; 

/*引用的本质在C++内部实现是一个指针常量*/ 

// 1、不要返回局部变量引用 
int& func(){
	
	int a = 10; //局部变量 存放在栈区中,由系统自动释放 
	
	cout << "func2中的a=" << a << endl; 
	return a;
}

// 2、返回静态变量引用
// 函数调用可以作为左值 
int &func2(){
	static int a = 20;	// 静态变量存放在全局区,全局区上的数据在程序结束后由系统释放 
	return a; 
} 

int main(){
	int &ref1 = func();
	int &ref2 = func2();
	
	cout << ref1 << endl;	// 第一次输出正确结果的原因在于编译器做了保留 
	cout << ref1 << endl; 	// 因子func函数运行后,里面变量的内存会进行释放.第二次编译器不再保留,因此不可再对此地址操作
	cout << ref1 << endl;
	
	cout << ref2 << endl;
	cout << ref2 << endl;
	
	func2() = 1000;			// 如果函数的返回值是引用,这个函数待用可以作为左值 
	func2();
	cout << ref2 << endl;
	cout << ref2 << endl;
	
	return 0;
}
