#include <iostream>

using namespace std;

// 引用的作用：给变量起别名
// 语法：数据类型 &别名 = 原名 
// 引用注意事项：引用必须初始化，在初始化后不可在改变 

int main(){
	
	int a = 10,c=200;
	int &b = a;
//	int &d; // 错误的，必须要初始化 
	b = c; // 这是赋值操作，不是更改引用 

	cout << "1:a = " << a << endl; 
	cout << "1:b = " << b << endl;
	cout << "1:a的地址为： " << &a << endl; 
	cout << "1:b的地址为:  " << &b << endl;
	
	b = 20;
	
	cout << "2:a = " << a << endl;
	cout << "2:b = " << b << endl;
	cout << "2:a的地址为： " << &a << endl; 
	cout << "2:b的地址为:  " << &b << endl; 
		
	return 0;
}
