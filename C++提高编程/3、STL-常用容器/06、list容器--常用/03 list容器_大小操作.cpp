#include<iostream>
#include<list>

using namespace std; 

// 链表的大小操作
// size(); 返回容器的大小
// resize(int num); 重新设定容器的大小，超出部分补默认值0，多余部分删除
// resize(int num, elem) 重新设定容器的大小，超出部分补elem，多余部分删除
// empty(); 判断容器是否为空
 
void printList(const list<int> &lst){
	// 判断容器是否为空 
	if(lst.empty()){
		cout << "该容器为空@" << endl;
		return ; 
	} 
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

void test01(){
	
	// 创建list容器
	list<int> lst;
	
	// 在容器插入元素	
	for(int i=0; i<10; i++){
		lst.push_back(i+1);
	} 
	cout << "1：lst容器的大小为：" << lst.size() << endl;
	printList(lst);
	
	// 重新设定lst容器大小为15，超出部分补充默认值0 
	lst.resize(15);
	cout << "2：lst容器的大小为：" << lst.size() << endl;
	printList(lst);
	
	// 重新设定lst容器大小为15，超出部分补充elem（111） 
	lst.resize(20,111);
	cout << "3：lst容器的大小为：" << lst.size() << endl;
	printList(lst);
	
	lst.resize(10,111);
	cout << "4：lst容器的大小为：" << lst.size() << endl;
	printList(lst);
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0; 
}
 
