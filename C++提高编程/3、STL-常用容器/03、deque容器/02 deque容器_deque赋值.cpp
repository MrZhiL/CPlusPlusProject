#include<iostream>
#include<deque>

using namespace std;

// deque容器中的赋值操作
/*
	deque& operator=(const deque& deq);		// 重载operator=操作符 
	assign(beg, end);						// 将deque容器中的[beg，end)中的数据赋值给本身 
	assign(n,elem); 						// 将n个elem元素赋值给本身 
*/

void printDeque(const deque<int> &deq){
	
	for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void test01(){
	
	deque<int> deq;
	for(int i=0;i<10;i++){
		deq.push_back(i);
	}
	printDeque(deq);
	
	// 1、重载=运算符进行赋值操作 
	deque<int> deq2 = deq;
	printDeque(deq2);
	
	// 2、使用assign函数进行赋值操作
	deque<int> deq3;
	deq3.assign(10,10);	// 将10个10赋值给deq3
	printDeque(deq3);
	
	deque<int> deq4;
	deq4.assign(deq3.begin(), deq3.end()); 
	printDeque(deq4);
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
