#include<iostream>
#include<deque>

using namespace std;

// deque�����еĸ�ֵ����
// deque��û�����������Ϊdeque�п���ǰ�����Ԫ�� 
/*
	deque.empty();			//�ж������Ƿ�Ϊ�� 
	deque.size();			//�ж������Ĵ�С��������Ԫ�صĸ��� 
	deque.resize(num);		//����ָ�������ĳ���Ϊnum���������߳�������Ĭ��ֵ�����λ��
							//��������С����ĩβ�����������ȵ�Ԫ�ر�ɾ�� 
	deque.resize(num,elem); //����ָ�������ĳ���Ϊnum���������߳�������elem�����λ��
					  		//��������С����ĩβ�����������ȵ�Ԫ�ر�ɾ�� 
*/

void printDeque(const deque<int> &deq){
	
	if(deq.empty()){
		cout << "������Ϊ��@" << endl;
		return;
	}
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
	cout << "�����Ĵ�СΪ��" << deq.size() << endl; 
	
	deq.resize(15,10);
	printDeque(deq);
	cout << "�����Ĵ�СΪ��" << deq.size() << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
