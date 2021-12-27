#include <iostream>
#include <string>
 
using namespace std;

// 函数调用运算符()也可以重载
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数
// 仿函数没有固定写法，非常灵活

// 创建打印类 
class MyPrint{
	
	// 重载函数调用运算符() 
	public:
		void operator() (string str){
			cout << str << endl;
		}
};

// 伪函数非常灵活，没有固定写法。 
// 创建加法类 
class MyAdd{
	
	public:
		int operator() (int num1, int num2){
			return num1+num2;
		}
		
}; 

void test01(){
	
	MyPrint mp;
	mp("HelloWorld!"); // 调用起来非常像函数，因此成为伪函数 
}

void test02(){
	
	// 匿名函数对象
	cout << MyAdd() (10,20) << endl;
}

int main(){
	
	test01();
	test02();
	
	system("pause");
	return 0;
}
