#include <iostream>

using namespace std;

// 1、值传递
void mySwap01(int a, int b){
	int temp;
	temp = a;
	a = b;
	b = temp;
} 

// 2、地址传递
void mySwap02(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
} 

// 3、引用做函数形参--和地址传递的效果相同，但语法更清晰和直观 
void mySwap03(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	
} 

int main(){
	
	//函数传参时，可以利用引用的技术让形参修饰实参
	//优点：可以简化指针修饰实参
	
	int i=10,j=20;
	
	int &ai = i;
	int &bj = j;
	
	cout << "0:i = " << i << endl;
	cout << "0:j = " << j << endl;
	cout << "0:ai = " << ai << endl;
	cout << "0:bj = " << bj << endl;
	
	mySwap01(i,j); // 形参进行传递，实参的值不会发生改变 
	cout << "形参进行传递，实参的值不会发生改变" << endl;
	cout << "1:i = " << i << endl;
	cout << "1:j = " << j << endl;
	
	mySwap02(&i,&j); // 使用地址进行参数传递，实参的值会发生改变 
	cout << "使用地址进行参数传递，实参的值会发生改变" << endl;
	cout << "2:i = " << i << endl;
	cout << "2:j = " << j << endl; 
	
//	mySwap03(ai,bj); 
	mySwap03(i,j); 
	cout << "引用作为形参，实参的值会发生改变" << endl; 
	cout << "3:i = " << i << endl;
	cout << "3:j = " << j << endl;
	
#if 0
	int* a = &i;
	int *b = &j;
	int *c = NULL;
	
//	*c = 100; // 不可以对0-255的地址内存赋值，该区域是系统占用的 
	
	cout << a << endl;
	cout << b << endl;
	cout << *c << endl;
#endif
		
	return 0;
} 
