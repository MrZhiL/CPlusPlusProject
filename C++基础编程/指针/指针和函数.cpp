#include <iostream>

using namespace std;

// 使用变量传递值 
void swap1(int a, int b);
// 使用指针传递值 
void swap2(int *, int *); 

int main(){
	
	// 指针和函数
	// note：传递形参的值无法改变实参的值 
	// 1、值传递	2、地址传递
	// 总结：如果不想修改实参就有值传递；想修改实参就用地址传递 
	
	int  a = 10,b=20;
	cout << "值传递前：" << endl; 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; 
	
	// 1、值传递 
	swap1(a,b);
	
	cout << "swap1值传递后：" << endl; 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; 
	
	// 2、地址传递 
	// 通过地址进行参数传递，可以修饰实参 
	swap2(&a,&b);
	
	cout << "swap2值传递后：" << endl; 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	system("pause");
	return 0;
}

// 使用变量传递值 
void swap1(int a, int b){
	// 进行参数a和b的交换 
	int temp;
	temp = a;
	a = b;
	b = temp;
}
// 使用指针传递值 
void swap2(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp; 
	cout << "值传递后：" << endl; 
	cout << "*a = " << *a << endl;
	cout << "*b = " << *b << endl; 
} 

