// swap_zhi.h的头文件 

#include<iostream>

using namespace std;

// 实现两个数字交换的函数的声明 
void aaa(int a, int b);
// 函数的定义
void aaa(int a, int b){

	// 创建临时变量
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "交换后：" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}
