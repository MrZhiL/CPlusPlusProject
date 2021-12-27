#include<iostream>
#include<list>

using namespace std;

// list容器：list容器的创建和赋值

void printList(const list<int> &lst){
	
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

void test01(){
	
	list<int> lst;
	
	// 向链表中插入数据（使用前插和后插） 
	lst.push_back(11); 
	lst.push_back(22); 
	lst.push_back(33); 
	lst.push_front(10);
	lst.push_front(99);
	// 遍历list：打印链表中的元素 
	printList(lst);
	
	// 区间构造：将链表[lst.begin(), lst.end())区间范围内的所有数据赋值给lst2 
	list<int> lst2(lst.begin(), lst.end());
	printList(lst2); 
	
	// 拷贝构造：使用拷贝构造函数进行赋值 
	list<int> lst3(lst2);
	lst3.pop_back();
	printList(lst3); 
	
	list<int> lst4(10,100);
	printList(lst4); 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
