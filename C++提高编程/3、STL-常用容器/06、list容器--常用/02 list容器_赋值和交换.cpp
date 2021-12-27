#include<iostream>
#include<list>

using namespace std;

// list容器中的赋值和交换
// assign(beg, end);			//赋值函数：将[beg, end)区间中的元素赋值给创建的list容器 
// assign(n, elem);				//将n个elem赋值给创建的list容器 
// operator=(const list &lst);	//重载等号运算符，将lst赋值给创建的容器 
// swap();						//交换两个容器的数据 

void printList(const list<int> &lst){
	
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

void test01(){
	
	list<int> lst1;
	// 向链表中插入数据（使用前插和后插） 
	lst1.push_back(11); 
	lst1.push_back(22); 
	lst1.push_back(33); 
	lst1.push_front(10);
	lst1.push_front(9);
	// 遍历list：打印链表中的元素 
	printList(lst1);
	cout << "lst1链表的大小为：" << lst1.size() << endl;
	
	list<int> lst2;
	lst2 = lst1;		// 使用重载后的等号进行赋值操作 
	
	printList(lst2);
	cout << "lst2链表的大小为：" << lst2.size() << endl;
	
	list<int> lst3;
	lst3.assign(++lst2.begin(),--lst2.end());
	printList(lst3);
	cout << "lst3链表的大小为：" << lst3.size() << endl;
	
	cout << "---------------------------------" << endl; 
	cout << "lst2和lst3交换前：" << endl;
	lst3.push_back(100);
	lst3.push_front(99); 
	
	cout << "lst2链表的大小为：" ;
	printList(lst2);
	cout << "lst3链表的大小为：" ;
	printList(lst3);
	
	cout << "---------------------------------" << endl; 
	cout << "lst2和lst3交换后：" << endl;
	lst3.swap(lst2);
	
	cout << "lst2链表的大小为：" ;
	printList(lst2);
	cout << "lst3链表的大小为：" ;
	printList(lst3);
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
