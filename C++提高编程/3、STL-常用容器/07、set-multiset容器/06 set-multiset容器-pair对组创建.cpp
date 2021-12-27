#include<iostream>

using namespace std;

// pair对组的创建，不用创建其余头文件

void test01(){
	
	// 直接赋值
	pair<string, int> p1("Tom", 21);
	// 使用make_pair进行赋值 
	pair<string, int> p2 = make_pair("Jerry", 19);
	
	cout << "姓名：" << p1.first << ", 年龄：" << p1.second << endl;
	cout << "姓名：" << p2.first << ", 年龄：" << p2.second << endl;
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0; 
} 
