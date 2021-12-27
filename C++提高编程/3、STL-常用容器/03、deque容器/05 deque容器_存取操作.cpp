#include<iostream>
#include<deque>

using namespace std;

// deque�����Ĵ�ȡ����
// 1��operator[int idx]���ж�ȡ
// 2��ʹ��at.(int idx)���ж�ȡ 
// 3��back()����ȡ���һ��Ԫ��
// 4��front(); ��ȡ��һ��Ԫ�� 

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
	deq.push_back(8);
	deq.push_back(9);
	deq.push_back(10);
	deq.push_front(3);
	deq.push_front(2);
	deq.push_front(1);
	
	printDeque(deq);
	
	// ��ȡ�����е�����
	cout << "ʹ������=�������ȡָ��λ�õ����ݣ� "; 
	for(int i=0; i< deq.size(); i++){
		cout << deq[i] << " ";
	} 
	cout << endl;
	
	cout << "ʹ��at(int idx)�������ȡָ��λ�õ����ݣ� "; 
	for(int i=0; i< deq.size(); i++){
		cout << deq.at(i) << " ";
	} 
	cout << endl;
	
	cout << "deque�����еĵ�һ��Ԫ��Ϊ��" << deq.front() << endl;
	cout << "deque���������һ��Ԫ��Ϊ��" << deq.back() << endl; 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
