#include <iostream>
#include <string>
using namespace std;

// string的构造函数
// 1、string s; // 创建空字符串 
// 2、string(const char* s); // 使用字符串s初始化  
// 3、string(const string &s); // 使用string中的拷贝函数赋值 
// 4、string(int n, char c);    // 使用n个字符c初始化 


void test01(){
	
	// 1、string s
	string s1("hello2");
	
	// 2、使用字符串c初始化 
	const char *c = "HelloWorld!";
	string s2(c);
	
	// 3、使用拷贝函数赋值 
	string s3(s1);	
	
	// 4、使用n个字符c初始化
	string s4(10, 'e');
	
	cout << "s1: " << s1 << endl; 
	cout << "s2: " << s2 << endl; 
	cout << "s3: " << s3 << endl; 
	cout << "s4: " << s4 << endl; 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
 
