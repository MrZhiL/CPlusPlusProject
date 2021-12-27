#include<iostream>
#include<deque>

using namespace std;

// deque容器的存取操作
// 1、operator[int idx]进行读取
// 2、使用at.(int idx)进行读取 
// 3、back()；读取最后一个元素
// 4、front(); 读取第一个元素 

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

void test01(){
	
	deque<int> deq;
	
	// 使用两端插入数据 
	deq.push_back(8);
	deq.push_back(9);
	deq.push_back(10);
	deq.push_front(3);
	deq.push_front(2);
	deq.push_front(1);
	
	printDeque(deq);
	
	// 读取容器中的数据
	cout << "使用重载=运算符读取指定位置的数据： "; 
	for(int i=0; i< deq.size(); i++){
		cout << deq[i] << " ";
	} 
	cout << endl;
	
	cout << "使用at(int idx)运算符读取指定位置的数据： "; 
	for(int i=0; i< deq.size(); i++){
		cout << deq.at(i) << " ";
	} 
	cout << endl;
	
	cout << "deque容器中的第一个元素为：" << deq.front() << endl;
	cout << "deque容器中最后一个元素为：" << deq.back() << endl; 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
