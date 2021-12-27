#include<iostream>
#include<deque>

using namespace std;

// deque中插入和删除
/**
	两端插入操作 
		  push_back(elem);		//在容器末端插入元素elem（尾插法） 
		  push_front(elem);		//在容器首段插入元素elem（头插法） 
		  pop_back();			//在容器末尾删除一个元素（尾删法） 
		  pop_front();			//删除容器中最前端的元素（头删法） 
	指定位置操作：
		  insert(pos, elem);	//在pos位置插入元素elem,并返回新数据的位置 
		  insert(pos, n, elem) ;//在pos位置插入n个elem元素，无返回值 
		  insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值 
		  clear();				//情况容器中的所有数据 
		  erase(beg, end);		//情况容器中[beg,end)区间的数据，返回下一个数据的位置 
		  erase(pos);			//删除pos位置的数据，返回下一个数据的位置
*/
void printDeque(const deque<int> &deq){
	if (deq.empty()){
		cout << "容器为空！" << endl;
		return ;
	}
	for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
		cout << *it << " ";
	}
	cout << endl; 
} 

// 指定位置插入和删除 
void test01(){
	
	deque<int> deq;
	for(int i = 1; i<10; i++){
		deq.push_back(i);
	}
	printDeque(deq);
	
	// deque容器插入数据, 在指定位置插入元素999 
	cout << *deq.insert(deq.begin(),999) << endl;
	printDeque(deq);

	// insert()在指定位置插入[beg, end)之间的数据 
	deq.insert(deq.end(), deq.begin(), deq.end());
	printDeque(deq); 
	
	// insert()在指定位置插入n个elme元素
	deq.insert(deq.begin(),5,888);
	printDeque(deq); 
	
	// erase(pos): 在指定位置删除元素,只删除一个元素,pos需要为迭代器 
	deq.erase(deq.end());	// 删除头部数据 
	printDeque(deq);
	
	deque<int>::iterator it = deq.begin();
	it += 10;
	deq.erase(it); 			// 删除第一个位置的数据 					
	printDeque(deq);
	
	// 删除[deq.begin(), deq.end())中间的所有数据，相当于clear() 
	deq.erase(deq.begin(),deq.end());
	printDeque(deq); 
	
} 

// 两端插入和删除
void test02(){
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
