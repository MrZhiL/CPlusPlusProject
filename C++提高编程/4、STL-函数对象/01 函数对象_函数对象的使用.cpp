#include<iostream>
#include<string>

using namespace std;

// 函数对象的使用特点： 
// 1、函数对象在使用时，可以像普通函数一样有参数和返回值
// 2、函数对象超出普通函数的概念，可以有自己的状态
// 3、函数对象可以作为参数传递 


// 1、函数对象在使用时，可以像普通函数一样有参数和返回值 
class MyAdd{
	public:
		// 重载的()函数中有参数，且有int的返回值 
		int operator() (int m1, int m2){
			return m1 + m2;
		}
}; 

void test01(){
	MyAdd myadd;
	cout << myadd(10,20) << endl;	
} 

// 2、函数对象超出普通函数的概念，可以有自己的状态（因为函数对象是一个类）
class MyPrint{
	public:
		MyPrint(){
			this->count = 0;
		}
		void operator() (string st){
			cout << st << endl;
			this->count++; 
		} 
		
		int count;	// count用来记录重载的()函数调用次数 
}; 

void test02(){
	MyPrint mp;
	mp("HELLOWORLD");
	mp("HELLOWORLD");
	mp("HELLOWORLD");
	mp("HELLOWORLD");
	
	cout << "myPrint调用的次数为：" << mp.count << endl;
}

// 3、函数对象可以作为参数传递
void doPrint(MyPrint &mp, string st){
	mp(st);
	cout << "doPrint中mp调用的次数：" << mp.count << endl; 
}

void test03(){
	
	MyPrint mp;
	doPrint(mp, "HElloC++");
	doPrint(mp, "HElloC++");
	doPrint(mp, "HElloC++");
	doPrint(mp, "HElloC++");
	
	cout << "mp的调用次数：" << mp.count << endl;
} 
int main(){
	
	//test01();
	//test02();
	test03();
	
	system("pause");
	return 0;
} 
