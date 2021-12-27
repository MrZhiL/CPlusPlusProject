#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//list容器的反转和排序
//reverse(); 反转容器的数据
//sort(); 对容器中的数据进行排序 

void printList(const list<int> &lst){
	if(lst.empty()){
		cout << "该容器为空！@" << endl;
	}
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

bool myCompare(int v1, int v2){
	// 如果要实现降序排序，则需要v1 > v2
	return v1 > v2; 
}

//具体实现 
void test01(){
	
	list<int> lst;
	
	lst.push_back(100);
	lst.push_back(200);
	lst.push_front(10);
	lst.push_front(20);
	
	cout << "排序前：";
	// 遍历list容器 
	printList(lst); 
	cout << "list链表中的第一个数据元素为：" << lst.front() << endl; 
	cout << "list链表中的最后数据元素为：" << lst.back() << endl; 
	
	cout << "排序后：";
	lst.sort();		// 默认排序为升序排序 
	// 遍历list容器 
	printList(lst); 
	cout << "list链表中的第一个数据元素为：" << lst.front() << endl; 
	cout << "list链表中的最后数据元素为：" << lst.back() << endl;  
	cout << "降序排序：";
	lst.sort(myCompare); 
	printList(lst); 
	
	//将链表进行反转
	cout << "将链表进行反转后：";
	lst.reverse(); 
	printList(lst); 
	cout << "list链表中的第一个数据元素为：" << lst.front() << endl; 
	cout << "list链表中的最后数据元素为：" << lst.back() << endl;  
	
	// 所有不支持随机访问的迭代器，都不可以用标准算法库 
	// 不支持随机访问迭代器的容器，内部会提供对应的一些算法 
	//sort(lst.begin(), lst.end()); // 使用标准库中的排序算法会报错 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
