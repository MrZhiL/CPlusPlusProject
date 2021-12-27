#include<iostream>
#include<stack>

using namespace std;

// stack栈的操作
// 栈的特点：只能先进后出，不可以遍历栈
 
void test01(){
	// 创建栈，默认构造函数 
	stack<int> stk;
	
	// 使用push向栈中插入数据 
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	
	cout << "栈的大小为：" << stk.size() << endl; 
	// 查看栈是否为空，如果不为空，则查看栈顶数据，并弹出 
	while(!stk.empty()){
		cout << "栈顶元素为：" << stk.top() << endl;
		stk.pop();
	}
	cout << "栈的大小为：" << stk.size() << endl; 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
