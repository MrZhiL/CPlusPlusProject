#include <iostream>
#include <string>

using namespace std;

// 全局变量
int g_a = 19;
int g_b = 29; 

// const修饰的全局变量
const int c_g_a = 30;
const int c_g_b = 10; 

int main(){
	
	// 全局区
	
	// 全局变量、静态变量、常量
	
	// 创建普通局部变量
	int a = 10,b=20;
	
	// 创建静态变量，可以观察到静态变量和全局变量存放的地址相同 
	static int s_a = 11;
	static int s_b = 78; 
	
	// 创建常量--字符串常量、const修饰的变量
	// 创建一个字符串常量，创建的局部字符串存放在局部地址区域 
	string  str_a = "HelloWorld!";
	
	// const修饰的变量--1、const修饰的全局变量；2、const修饰的局部变量
	/*可以观察出const修饰的局部变量的地址为局部区域，而const修饰的全局变量存在与全局区*/ 
	const int c_a = 41;
	const int c_b = 82; 
	
	cout << "局部变量a的地址为： " << &a << endl;
	cout << "局部变量b的地址为： " << &b << endl;
	
	cout << "全局变量g_a的地址为： " << &g_a << endl;
	cout << "全局变量g_b的地址为： " << &g_b << endl; 
	
	cout << "静态变量s_a的地址为： " << &s_a << endl;
	cout << "静态变量s_b的地址为： " << &s_b << endl;
	
	cout << "字符串常量str_a的地址为： " << &str_a << endl;
	cout << "字符串常量的地址为： " << &"Hello!" << endl; 

	cout << "const修饰的全局变量c_g_a的地址为： " << &c_g_a << endl;
	cout << "const修饰的全局变量c_g_b的地址为： " << &c_g_b << endl; 
	 
	cout << "const修饰的局部常量c_a的地址为： " << &c_a << endl;
	cout << "const修饰的局部常量c_b的地址为： " << &c_b << endl; 
	
	system("pause");
	return 0;
} 
