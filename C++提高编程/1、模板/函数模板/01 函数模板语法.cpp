#include <iostream>

using namespace std;

// 函数模板 

/**
函数模板注意事项
	1、自动类型推导，必须推导出一致的数据类型T，才可以使用
	2、模板必须要确定出T的数据类型，才可以使用 
*/			

// 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个车通用数据类型 
template<typename T>
void MySwap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

// 交换整形数据
void swapInt(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
} 

// 交换浮点型数据
void swapDouble(double &a, double &b){
	double temp = a;
	a = b;
	b = temp;
} 

void test01(){
	
	int a = 10;
	int b = 20;
	
	//swapInt(a,b);
	// 使用模板交换有两种方式：1、自动推导类型，编译器自动推导数据类型 ； 2、指定数据类型
	// 1、自动推导类型
	MySwap(a,b); 
	cout << "交换后：a = " << a << "  b = " << b << endl; 

	double c = 1.20;
	double d = 2.40;
	
	// 2、指定数据类型 
	//swapDouble(c,d);
	MySwap<double>(c,d);
	cout << "交换后：c = " << c << "  d = " << d << endl; 	
}


int main(){
	
	test01();
	
	system("pause");
	return 0;
}
