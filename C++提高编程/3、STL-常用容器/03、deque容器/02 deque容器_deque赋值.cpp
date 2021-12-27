#include<iostream>
#include<deque>

using namespace std;

// deque�����еĸ�ֵ����
/*
	deque& operator=(const deque& deq);		// ����operator=������ 
	assign(beg, end);						// ��deque�����е�[beg��end)�е����ݸ�ֵ������ 
	assign(n,elem); 						// ��n��elemԪ�ظ�ֵ������ 
*/

void printDeque(const deque<int> &deq){
	
	for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void test01(){
	
	deque<int> deq;
	for(int i=0;i<10;i++){
		deq.push_back(i);
	}
	printDeque(deq);
	
	// 1������=��������и�ֵ���� 
	deque<int> deq2 = deq;
	printDeque(deq2);
	
	// 2��ʹ��assign�������и�ֵ����
	deque<int> deq3;
	deq3.assign(10,10);	// ��10��10��ֵ��deq3
	printDeque(deq3);
	
	deque<int> deq4;
	deq4.assign(deq3.begin(), deq3.end()); 
	printDeque(deq4);
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
