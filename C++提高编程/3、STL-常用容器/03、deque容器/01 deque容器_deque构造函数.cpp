#include <iostream>
#include<deque>
#include<vector> 
using namespace std;

// deque容器的构造函数,deque容器和vector容器的函数功能基本一样，调用方式也相同 

/*
	deque<T> deqT;		   // 默认构造形式 
	deque(beg,end)		   // 构造函数将[beg,end)区间中的元素拷贝给自身 
	deque(n,elem);		   // 构造函数将n个elem元素拷贝给自身 
	deque(const deque &deq); // 拷贝构造函数 
*/

void printDeque(const deque<int> &deq){	// 加入const限定为只读状态 
	
	/*如果使用const限定为只读状态，则迭代器需要使用const_iterator，而不是iterator*/ 
	for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
		//*it = 100;		// 通过限定只读状态后，该值不可修改 
		cout << *it << " ";
	}
	cout << endl;
}

void test01(){
	
	deque<int> deq;				// 默认构造函数，无参构造 
	for(int i=0;i<10;i++){
		deq.push_front(9-i);	// 通过前插方式插入元素 
		deq.push_back(10+i);	// 通过后插方式插入元素 
	}
	printDeque(deq);
	
	// 拷贝构造
	deque<int> deq2(deq);
	printDeque(deq2);
	
	// 构造函数：将10个100赋值给deq3容器 
	deque<int> deq3(10,100);
	printDeque(deq3);
	
	// 构造函数：将[begin，end)中的数据赋值给自身
	deque<int> deq4(deq3.begin(), deq3.end());
	printDeque(deq4); 
	
	/*vector容器和deque容器不可进行赋值*/
//	vector<int> vec(deq4);
//	vector<int> vec;
//	for(vector<int>::iterator it = vec.begin(); it != it.end(); it++){
//		cout << *it << " ";
//	} 
//	cout << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
