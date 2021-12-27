#include<iostream>
#include "swap_zhi.h"

using namespace std; 

/********************************* 
 * 函数的分文件编写：
 * 作用：让代码结构更为清晰
 * 函数文件编写一般有4个步骤：
 * 1.创建后缀名为.h的头文件 
 * 2.创建后缀名为.cpp的源文件 
 * 3.在头文件中写函数的声明 
 * 4.在源文件中写函数的定义 
 **************************************** 
 */
 
// 函数的分文件编写
// 实现两个数字进行交换的函数

/**
// 函数的声明 
void swap(int a, int b); */

int main(){
	
	int a = 10;
	int b = 20;
	
	cout << "交换前：" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; 
	
	aaa(a,b);
	
	system("pause");
	
	return 0;
	
} 

/**
// 函数的定义 
int swap(int a, int b){
	
	// 创建临时变量 
	int temp;
	
	temp = a;
	a = b;
	b = temp;
	
	cout << "交换后：" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; 
		
} */ 

