#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

// deque����
// ʹ��sort(begin, end); ��begin��end�����Ԫ�ؽ�������


void printDeque(const deque<int> &deq){
	if (deq.empty()){
		cout << "����Ϊ�գ�" << endl;
		return ;
	}
	for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
		cout << *it << " ";
	}
	cout << endl; 
} 

void test01(){
	
	deque<int> deq;
	
	// ʹ�����˲������� 
	deq.push_back(80);
	deq.push_back(19);
	deq.push_back(10);
	deq.push_front(13);
	deq.push_front(2);
	deq.push_front(11);
	
	//printDeque(deq);
	cout << "deque��������֮ǰ������Ϊ��"; 
	// ��ȡ�����е�����
	for(int i=0; i< deq.size(); i++){
		cout << deq[i] << " ";
	} 
	cout << endl;
	
	cout << "ʹ��algorithm�е�sort()������������������󣬸������е�����Ϊ��" << endl; 
	
	sort(deq.begin(),deq.end());	//Ĭ������Ϊ��С���� 
	
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
