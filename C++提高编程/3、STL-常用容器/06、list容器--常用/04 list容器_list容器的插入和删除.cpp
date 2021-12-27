#include<iostream>
#include<list>

using namespace std;

// list容器中的插入和删除

void printList(const list<int> &lst){
	if(lst.empty()){
		cout << "该容器为空！@" << endl;
	}
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

void test01(){
	list<int> lst;
	
	//使用push_back()对链表尾部插入数据（尾插法） 
	for(int i=0; i<10; i++){
		lst.push_back(i+2);
	} 
	cout << "1: 容器中的元素为：" ;
	printList(lst); 
		//删除链表pos的元素
	int a = *lst.erase(lst.begin());
	cout << "5: 容器中的元素为：" << a << endl;;
	printList(lst);
	
	//在lst头部插入10个9 
	lst.insert(lst.begin(),10,9);
	cout << "2: 容器中的元素为：" ;
	printList(lst);
	
	//在lst尾部插入999 
	lst.insert(lst.end(),999);
	cout << "3: 容器中的元素为：" ;
	printList(lst);
	
	//在pos位置插入[beg, end)区间的所有元素 
	lst.insert(lst.begin(),lst.begin(), lst.end());
	cout << "4: 容器中的元素为：" ;
	printList(lst);
	
	//删除链表pos的元素
	lst.erase(--lst.end()); 
	cout << "5: 容器中的元素为：" ;
	printList(lst);
		
	//删除链表中的所有数值为9的元素
	lst.remove(9);
	cout << "6: 容器中的元素为：" ;
	printList(lst);
 
	//删除[beg, end)区间的所有元素
	lst.erase(++lst.begin(),--lst.end());
	cout << "7: 容器中的元素为：" ;
	printList(lst);
	
	//清空容器中的所有元素
	lst.clear();
	cout << "8: 容器中的元素为：" ;
	printList(lst);
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
 
