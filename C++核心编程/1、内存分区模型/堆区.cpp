#include <iostream>

using namespace std;

int * func(){
	
	// 利用new关键字在堆区分配地址 
	// 指针本质也是局部变量，放在栈上，但指针保存的数据放在堆区 
	int *p = new int(10);
	return p;
	
} 

int main(){
	
	// 在堆区开辟数据
	
	int *p = func();
	
	cout << "1:*p = " << *p << endl;
	cout << "2:*p = " << *p << endl; 
	
	return 0;
} 
