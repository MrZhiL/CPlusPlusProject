#include <iostream>
#include <string>

using namespace std;

// string容器中的查找和替换 

/**
 	int find(const string& str, int pos=0) cosnt ;			//查找str第一次出现位置，从pos开始查找
	int find(const char *s, int pos=0) const;				//查找s第一次出现位置，从pos开始查找
	int find(const char *s, int pos, int n) cosnt;			//从pos位置查找s的前n个字符第一次位置
	int find(const char c, int pos=0) const;				//查找字符c第一次出现的位置
	int rfind(const string &str, int pos=npos) const;		//查找str最后一次位置，从pos开始查找
	int rfind(const char *s, int pos=npos) cosnt;			//查找s最后一次出现位置，从pos开始查找
	int rfind(const char *s, int pos ,int n) const;			//从pos查找s的前n个字符最后一次位置
	int rfind(cosnt char c, int pos = 0) const;				//查找字符c最后一次出现位置
			
	string& replace(int pos, int n, const string& str);		//替换从pos开始n个字符为字符串str
	string& replace(int pos, int n, const char *s);			//替换从pos开始的n个字符为字符串s
		
 */

// string查找 
void test01(){
	
	string str1 = "HelloWorld!This is my project!";
	
	// find表示字符第一次出现的位置 
	int pos = str1.find("This", 0);
	if (pos == -1){
		cout << "未找到该字符串！" << endl; 
	}else{
		cout << "找到该字符串，该字符串的位置为：pos = " << pos << endl;
	}
	
	// rfind和find的区别：rfind从左往右查找，find从右往左查找，但都从左往右计算。
	// rfind表示查找字符的最后一次位置 
	pos = str1.rfind("my");
	
	if (pos == -1){
		cout << "未找到该字符串！" << endl; 
	}else{
		cout << "找到该字符串，该字符串的位置为：pos = " << pos << endl;
	}
	
	// int rfind(const char *s, int pos ,int n)：从pos位置开始查找字符串s的前n个字符最后一次位置 
	int locat1 = str1.rfind("my project", 1, 1); 
	
	cout << "my project第一次出现的位置为：" << locat1 << endl;
	
	cout << "！出现的最后一次位置为：" << str1.rfind('!',15) << endl; 
} 

// 替换
void test02(){
	
	//string& replace(int pos, int n, const string& str);		//替换从pos开始n个字符为字符串str
	//string& replace(int pos, int n, const char *s);			//替换从pos开始的n个字符为字符串s
	
	string str = "HelloWorld! This is My Project!";
	str += (char)5; 
	str = str.replace(0,10,"Welcome");
	
	cout << "替换后的str = " << str << endl; 
	
} 

int main(){
	
	test01();
//	test02();
	
	system("pause");
	
	return 0;
	
} 
