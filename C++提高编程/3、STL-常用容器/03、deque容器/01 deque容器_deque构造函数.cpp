#include <iostream>
#include<deque>
#include<vector> 
using namespace std;

// deque�����Ĺ��캯��,deque������vector�����ĺ������ܻ���һ�������÷�ʽҲ��ͬ 

/*
	deque<T> deqT;		   // Ĭ�Ϲ�����ʽ 
	deque(beg,end)		   // ���캯����[beg,end)�����е�Ԫ�ؿ��������� 
	deque(n,elem);		   // ���캯����n��elemԪ�ؿ��������� 
	deque(const deque &deq); // �������캯�� 
*/

void printDeque(const deque<int> &deq){	// ����const�޶�Ϊֻ��״̬ 
	
	/*���ʹ��const�޶�Ϊֻ��״̬�����������Ҫʹ��const_iterator��������iterator*/ 
	for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
		//*it = 100;		// ͨ���޶�ֻ��״̬�󣬸�ֵ�����޸� 
		cout << *it << " ";
	}
	cout << endl;
}

void test01(){
	
	deque<int> deq;				// Ĭ�Ϲ��캯�����޲ι��� 
	for(int i=0;i<10;i++){
		deq.push_front(9-i);	// ͨ��ǰ�巽ʽ����Ԫ�� 
		deq.push_back(10+i);	// ͨ����巽ʽ����Ԫ�� 
	}
	printDeque(deq);
	
	// ��������
	deque<int> deq2(deq);
	printDeque(deq2);
	
	// ���캯������10��100��ֵ��deq3���� 
	deque<int> deq3(10,100);
	printDeque(deq3);
	
	// ���캯������[begin��end)�е����ݸ�ֵ������
	deque<int> deq4(deq3.begin(), deq3.end());
	printDeque(deq4); 
	
	/*vector������deque�������ɽ��и�ֵ*/
//	vector<int> vec(deq4);
//	vector<int> vec;
//	for(vector<int>::iterator it = vec.begin(); it != it.end(); it++){
//		cout << *it << " ";
//	} 
//	cout << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
