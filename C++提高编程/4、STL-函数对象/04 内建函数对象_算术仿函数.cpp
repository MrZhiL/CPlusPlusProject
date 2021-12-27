#include<iostream>
#include<functional> 
using namespace std;

// 内建函数对象：算术仿函数
// 使用内建函数对象，需要使用#include<functional>头文件 

void test01(){
	
	// negate仿函数（取反函数），为一元谓词
	negate<int> n;
	cout << "取反仿函数的调用！50取反后为："; 
	cout << n(50) << endl; 
	
	// plus加法仿函数，为二元谓词（只有negate为一元谓词，其余都是二元谓词） 
	plus<int> p;
	cout << "加法仿函数的调用：10+11 = " << p(10,11) << endl; 
	
	// minus减法仿函数
	minus<int> m;
	cout << "减法仿函数的调用：100-23 = " << m(100,23) << endl;
	
	// multiples乘法仿函数
	multiplies<int> ml;
	cout << "乘法仿函数的调用：10*23 = " << ml(10,23) << endl;
	
	// divides除法仿函数
	divides<int> div;
	cout << "出发仿函数的调用：100/25 = " << div(100,25) << endl;
	
	// modulus取模仿函数 
	modulus<int> mod;
	cout << "取模仿函数的调用：100%8 = " << mod(100, 8) << endl; 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
