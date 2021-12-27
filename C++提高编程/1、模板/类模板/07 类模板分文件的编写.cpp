#include <iostream>
#include <string>

//#include "Person.h" // 直接调用.h的头文件，会导致函数实现的.cpp文件连接不到 

using namespace std;

// 函数分文件的编写：类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到 
// 解决方案：1、直接调用.cpp文件 (但该方法使用较少)
//#include "Person.cpp"

// 解决方案：2、将声明和实现写在一个文件中，并后缀名改为.hpp(该方法比较常用)
#include "Person.hpp" 

void test01(){
	
	Person<string, int> p1("jack", 23);
	
	p1.showPerson();
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}

