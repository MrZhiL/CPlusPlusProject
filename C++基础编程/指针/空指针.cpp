#include <iostream>

using namespace std;

int main(){
	
	// 空指针
	// 1、空指针用于给指针变量进行初始化
	// 2、空指针不可以进行访问，（0-255之间的地址是系统占用的，因此不可以访问） 
	// 3、在程序中，尽量避免出现野指针（因为访问会出错）。 
	int a = 10;
	int *p = (int *)0x184a;	// 野指针，不可访问 
	
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	
	*p = a; // 不可以对指针直接赋值，要不会直接崩溃 
	p = &a;
	
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl; 
	cout << "*p = " << *p << endl;
	cout << "a = " << a << endl;
	
	system("pause");
	return 0;
}
