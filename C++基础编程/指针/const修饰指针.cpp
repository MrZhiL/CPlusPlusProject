#include <iostream>

using namespace std;

int main(){
	
	// const修饰指针有三种情况：
	// 1、const修饰指针 --常量指针    特点：指针的指向可以修改，但是指针指向的值不可以改 
	// 2、const修饰常量 --指针常量    特点：指针的指向不可以修改，但是指针指向的值可以该 
	// 3、const即修饰指针，有修饰常量 特点：指针的指向和指针指向的值都不可以改 
	
	int a=10,b=20,c=30;
	
	// 1、常量指针 
	const int *p1 = &a;
	
	// 2、指针常量
	int * const p2 = &b;
	
	// 3、修饰常量
	const int * const p3 = &c; 
	
	cout << "p1 = " << p1 << endl;
	cout << "*p1 = " << *p1 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "*p2 = " << *p2 << endl;
	
	/* 此时可以直接修改变量的值，只是不可以修改常量指针的值 */
//	*p1 = 12; // error
	p1 = &b;	// right
	b = 21;	
		
	/* 此时可以直接修改变量的值，也可以修改常量指针的值--但是不可以修改指针的指向*/
//	p2 = &a;  // error
	*p2 = 22; // right
	
	/* 此时可以直接修改变量的值--不可以修改常量指针的值，不可以修改指针的指向*/
//	p3 = &a; // error
//	*p3 = 50; //error
	
	cout << "p1 = " << p1 << endl;
	cout << "*p1 = " << *p1 << endl;  
	
	system("pause");
	return 0;
} 
