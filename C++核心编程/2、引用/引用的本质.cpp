#include <iostream>

using namespace std;

// 发现是引用，转化为 int * const ref2 = &a; 
void func(int& ref2){
	
	// 因子ref接收的是地址，所以当改变ref2时，&a中指向的数据也发生改变 
	ref2 = 100;	//ref是引用，转化为*ref2 = 100; 
}

void func5(int a,int ){
	cout << "this is a func5 " << endl;
} 

void printValue(const int& val){
//	val = 99; // 用const修饰引用后，不可再更改val的值，此时为只读状态 
	cout << "val = " << val << endl;
}


// 如果函数声明中有默认参数，则函数实现中就不能有默认参数 
// 声明和实现只能有一个有默认参数 
//int func3(int a=10,int b=20);

// 函数重载的满足条件：
// 1、必须在同一个作用域下；
// 2、函数名称相同；
// 3、函数参数类型不同，或者个数不同，或者顺序不同 
// 注意：函数的返回值不可以作为重载的条件 
int func31(int c){
	cout << "func2(int c) " << endl; 
	return c;
}

int func31(int c, int d=10){
	cout << "func2(int c,int d=10) " << endl; 
	return c;
}

int func3(int &c){
	cout << "func3(int &c) " << endl;
	return 1;
} 

int func3(const int &c){
	cout << "func3(const int &c)" << endl;
	return 1;
}

int func3(int a, int b){
	cout << "func3(int a, int b) " << endl; 
	return a+b;
}

int main(){
	
	int a = 10; // 创建常量
	int &ca = a;
//	func21(a); // 错误的，函数重载碰到默认参数，出现二义性，保错，尽量避免该种情况 
	func31(10,10); // 正确的 
	func3(a);
//	func3(10);
	// 常量引用的作用：防止误操作
	// 使用场景：用来修饰形参，防止误操作 
	int showa = 999;
	
	cout << func3(1,1) << endl;
	
	cout << "showa = " << showa << endl; 
	printValue(showa);
	cout << "showa = " << showa << endl;
	
	// 创建引用，引用的本质是一个指针常量。
	// 当系统检测到创建了一个引用后，则系统自动转化为 int * const ref = &a; 
	// 指针常量是指针指向不可更改，也说明为什么引用不可更改 
	int &ref = a;	 
	 
	cout << "1:a=" << a << endl; 
	cout << "1:ref=" << ref << endl;
	cout << "1:a的地址为：" << &a << endl;
	cout << "1:ref的地址为： " << &ref << endl;
	
	ref = 20;	//内部发现是引用，自动转化为*ref=20；
	
	cout << "2:a=" << a << endl; 
	cout << "2:ref=" << ref << endl;
	cout << "2:a的地址为：" << &a << endl;
	cout << "2:ref的地址为： " << &ref << endl;
	
	func(a); 
	cout << "3:a=" << a << endl; 
	cout << "3:ref=" << ref << endl;
	cout << "3:a的地址为：" << &a << endl;
	cout << "3:ref的地址为： " << &ref << endl;
	
//	int &b = 1;	// 错误的，引用的内存必须在堆区或者栈区（合法的内存空间），而不能在常量区 
	const int &b = 1; // 正确的，因为加上const后，编译器自动创建一个 int temp=1, const int &b=temp; 
//	b = 2; //用const标记后，变为只读状态，不可再修改 
	cout << b << endl;

	
	return 0;
} 

// 结论：C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是指针操作编译器都帮我们做了 
