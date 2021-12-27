#include <iostream>
#include <stdlib.h>
using namespace std;

/**************************************
 * C++中利用new操作符在堆区开辟数据 
 * 堆区开辟的数据，由程序员手动开辟，手动释放，什邡市利用操作符delete 
 * 利用new创建的数据，会返回该数据对应的类型的指针 
 *************************************** 
 */

// 1、利用new关键字分配内存 
int *func1(){
	
	int *p = new int(10); 
	return p;
}

// 2、利用new关键字为数组分配内存
int *func2(){
	
	// 利用new关键字给一个10个元素的数组分配内存，此时new返回的是数组的首地址 
	int *arr = new int[10];

	return arr; 
} 


int main(){
	
	int *test01 = func1();
	int *test02 = func2();
	int i; 
	
	cout << "test01:" << endl;
	cout << "1:*test01 = " << *test01 << endl;
	cout << "2:*test01 = " << *test01 << endl;
	cout << "3:*test01 = " << *test01 << endl;
	cout << "4:*test01 = " << *test01 << endl;
	
	// 释放test01的内存，此时在引用test01就会报错
	delete test01; 
	
	cout << "5:*test01 = " << *test01 << endl;
	cout << "6:*test01 = " << *test01 << endl;
	
	cout << "test02:" << endl;
	// 利用for循环给test02的数组赋值 
	for(i=0; i<10; i++){
		test02[i] = i; 
	}
	
	for(i=0; i<10; i++){
		cout << "test02[" << i << "] = " << *(test02+i) << endl; 
	}
	
	delete[] test02; // 释放test02的内存，注意：释放数组的内存时，需要在delete后面加上[] 
	
	//此时在引用test02就会报错
	cout << endl;
	for(i=0; i<10; i++){
		cout << "test02[" << i << "] = " << *(test02+i) << endl; 
	}

	return 0;
	
}
