#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

// deque排序
// 使用sort(begin, end); 对begin到end区间的元素进行排序


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
	deq.push_back(80);
	deq.push_back(19);
	deq.push_back(10);
	deq.push_front(13);
	deq.push_front(2);
	deq.push_front(11);
	
	//printDeque(deq);
	cout << "deque容器排序之前的数据为："; 
	// 读取容器中的数据
	for(int i=0; i< deq.size(); i++){
		cout << deq[i] << " ";
	} 
	cout << endl;
	
	cout << "使用algorithm中的sort()函数对容器进行排序后，该容器中的数据为：" << endl; 
	
	sort(deq.begin(),deq.end());	//默认排序为从小到大 
	
	for(int i=0; i< deq.size(); i++){
		cout << deq.at(i) << " ";
	} 
	cout << endl;
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
