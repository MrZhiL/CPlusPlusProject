#include <iostream>
#include <string>

using namespace std;

// string字符的插入和删除
/**			
	函数原型：string& insert(int pos, const string& str); 	// 插入字符串str
	 		  string& insert(int pos, const char* s); 		// 插入字符串s
	 		  string& insert(int pos, int n, char c);       // 在指定位置插入n个字符c
			  string& erase(int pos, int n = npos);			// 删除从pos开始的n个字符 
*/ 

void test01(){
	
	string str = "HelloWorld!";
	cout << "插入前:str = " << str << endl;
	
	// string字符的插入
	str.insert(0,"Welcome! ");
	cout << "插入后:str = " << str << endl;
	
	// 在指定位置插入n个字符c
	str.insert(10,5,'e');
	cout << "在指定位置插入5个e后：str = " << str << endl; 
	
	// 删除从pos开始的n个字符
	str.erase(10,5);
	cout << "删除从10开始的5个字符后：str = " << str << endl; 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
