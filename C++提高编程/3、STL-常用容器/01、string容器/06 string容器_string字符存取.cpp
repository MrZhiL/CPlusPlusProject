// string字符的存取 
//string中单个字符存取方式有两种：char& operator[](int n); // 通过[]方式取字符 
//								  char& at(int n); 		   // 通过at方式获取字符

#include <iostream>
#include <string>

using namespace std;

void test01(){
	
	string str = "HelloWorld!";
	
	char s[100];
	
	cout << "sizeof(str) = " << sizeof(str) << endl;
	cout << "sizeof(char *s) = " << sizeof(s) << endl;
	
	// 1、通过[]获取字符 
	cout << "1、通过[]获取字符: " ; 
	for(int i=0; i<str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;
	
	// 2、通过at方式获取字符
	cout << "2、通过at获取字符: " ; 
	for(int i=0;i<str.size();i++){
		s[i] = str.at(i);
		cout << s[i] << " ";
	}
	cout << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
} 
