#include "swap.h"

void swap_zhi(int a, int b){
	
	int temp;
	
	temp = a;
	a = b;
	b = temp;
	
	cout << "交换后：" << endl;
	cout << "a = " << a << "\tb = " << b << endl; 
}

void swap(int a, int b){
	
	int temp;
	
	temp = a;
	a = b;
	b = temp;
	
	cout << "交换后：" << endl;
	cout << "a = " << a << "\tb = " << b << endl; 
}
