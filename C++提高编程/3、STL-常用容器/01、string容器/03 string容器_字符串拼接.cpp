#include<iostream>
#include<string>

using namespace std;

// 字符串拼接
/**
	string& operator+=(const char* s);			//重载+=运算符
	string& operator+=(const string &str);		//重载+=运算符
	string& operator+=(char c);					//重载+=运算符
	string& append(const string *str);			//把字符串str连接到当前字符串的末尾
	string& append(const char* s, int n);		//把字符串的前n个字符连接到当前字符串的末尾
	string& append(const string &s);			//把字符串s连接到当前字符串的末尾
	string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到字符串末尾
*/ 

void test01(){
	
	string str1 = "今天"; 
	string *str2 = new string();
	*str2 = "是牛郎和织女相逢的日子";
	
	cout << "str1: " << str1 << endl; 
	
	str1 += "是七夕！"; 
	cout << "str1: " << str1 << endl; 
	
	str1 += *str2;
	cout << "str1: " << str1 << endl; 
	
	str1 += '!';
	cout << "str1: " << str1 << endl;
	
	string str3 = "今天";
	str3.append("是2020-08-26: "); 
	cout << "str3: " << str3 << endl; 
	
	str3.append(*str2);
	cout << "str3: " << str3 << endl;
	
	str3.append("Hello，织女星！", 13,2);
	cout << "str3: " << str3 << endl;
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
} 
