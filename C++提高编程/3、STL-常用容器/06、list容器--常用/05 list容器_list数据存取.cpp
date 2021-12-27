#include<iostream>
#include<list>

using namespace std;

//list数据存取
//list[idx]不可以用[]访问list中的容器，只能访问两端的数据，不可以随机访问
//lst.at(0); 不可以用at方式访问list容器中的数据，
//原因在于list容器本质是一个链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问 

//利用迭代器可以访问其余元素（将迭代器++或--） 

void printList(const list<int> &lst){
	if(lst.empty()){
		cout << "该容器为空！@" << endl;
	}
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

//具体实现 
void test01(){
	
	list<int> lst;
	
	lst.push_back(100);
	lst.push_back(200);
	lst.push_front(10);
	lst.push_front(20);
	
	// 遍历list容器 
	printList(lst); 
	
	cout << "list链表中的第一个数据元素为：" << lst.front() << endl; 
	cout << "list链表中的最后数据元素为：" << lst.back() << endl; 
	
	//验证迭代器不支持随机访问
	list<int>::iterator it = lst.begin();
	it++;	// 迭代器支持前向递增和后向递增，即双向访问 
	it--; 
	//it = it + 1;	// 该语句错误，说明，该迭代器不支持随机访问 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
