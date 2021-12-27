#include <iostream>

using namespace std;

/************************************************************
 *通函数和模板函数的区别：
 *1、普通函数调用时可以发生自动类型转换（隐式类型转换）
 *2、函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
 *3、如果利用显示指定类型的方式，可以发生隐式类型转换
**************************************************************
 */
 
// 普通函数
int MyAdd01(int a, int b){
	return a+b;
} 

// 模板函数
template <typename T>
T MyAdd02(T a, T b){
	return a + b;
}

void test01(){
	
	int a = 10;
	int b = 20;
	char c = 'c'; 	// c的ASCII为99 
	
	// 1、普通函数可以发生隐式转换 
	cout << MyAdd01(a,c) << endl; 
	
	// 2、模板函数如果使用自动类型推导，则不可以发生隐式转换
	//MyAdd02(a,c); // 错误
	
	// 3、模板函数如果指定数据类型，则可以发生隐式转换
	cout << MyAdd02<int>(a,c) << endl; 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
}
