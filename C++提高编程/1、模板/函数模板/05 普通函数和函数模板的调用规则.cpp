#include <iostream>

using namespace std;

// 普通函数和模板函数的调用规则
// 1、如果普通函数和函数模板都可以实现，则优先调用普通函数
// 2、可以通过空模板参数列表来强调函数模板 
// 3、函数模板也可以发生重载
// 4、如果函数模板可以产生更好的匹配，优先调用函数模板 


// 总结：既然提供了函数模板，最好不要提供普通函数，否则容易出现二义性

void MyPrint(int a, int b){
	cout << "普通函数的调用！" << endl; 
}

template<typename T>
void MyPrint(T a, T b){
	cout << "函数模板的调用！" << endl;
} 

template<typename T>
void MyPrint(T a, T b, T c){
	cout << "函数重载模板的调用！" << endl;
} 

void test01() {
	
	int a = 10;
	int b = 20;
	
	char c = 'a';
	char d = 'b';
	
	// 1、如果普通函数和函数模板同时存在，则优先调用普通函数
	// 即使普通函数只有声明，也会调用普通函数（但如果没有函数实现，则会报错） 
	// 普通函数可以进行隐式转换，因此即使输入char类型数据，该普通函数也可以调用，会自动把char型转为int型 
	cout << "1、如果普通函数和函数模板同时存在，则优先调用普通函数" << endl;
	MyPrint(a,b);
	cout << endl;
	
	// 2、可以通过空参数模板，强调使用模板函数 
	cout << "2、可以通过空参数模板，强调使用模板函数 " << endl;
	MyPrint<>(a,b); 
	cout << endl;
	
	// 3、函数模板也可以发生重载
	cout << "3、函数模板也可以发生重载 " << endl;
	MyPrint<>(a,b,100); 
	cout << endl; 
	
	// 4、如果函数模板有更好的匹配性，则优先使用函数模板
	cout << "4、如果函数模板有更好的匹配性，则优先使用函数模板" << endl;
	MyPrint(c,d); 
	cout << endl;
}
 
int main(){

	test01(); 
	
	system("pause");
	return 0;
	
} 
