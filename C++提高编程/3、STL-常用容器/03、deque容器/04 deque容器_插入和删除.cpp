#include<iostream>
#include<deque>

using namespace std;

// deque�в����ɾ��
/**
	���˲������ 
		  push_back(elem);		//������ĩ�˲���Ԫ��elem��β�巨�� 
		  push_front(elem);		//�������׶β���Ԫ��elem��ͷ�巨�� 
		  pop_back();			//������ĩβɾ��һ��Ԫ�أ�βɾ���� 
		  pop_front();			//ɾ����������ǰ�˵�Ԫ�أ�ͷɾ���� 
	ָ��λ�ò�����
		  insert(pos, elem);	//��posλ�ò���Ԫ��elem,�����������ݵ�λ�� 
		  insert(pos, n, elem) ;//��posλ�ò���n��elemԪ�أ��޷���ֵ 
		  insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ 
		  clear();				//��������е��������� 
		  erase(beg, end);		//���������[beg,end)��������ݣ�������һ�����ݵ�λ�� 
		  erase(pos);			//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
*/
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

// ָ��λ�ò����ɾ�� 
void test01(){
	
	deque<int> deq;
	for(int i = 1; i<10; i++){
		deq.push_back(i);
	}
	printDeque(deq);
	
	// deque������������, ��ָ��λ�ò���Ԫ��999 
	cout << *deq.insert(deq.begin(),999) << endl;
	printDeque(deq);

	// insert()��ָ��λ�ò���[beg, end)֮������� 
	deq.insert(deq.end(), deq.begin(), deq.end());
	printDeque(deq); 
	
	// insert()��ָ��λ�ò���n��elmeԪ��
	deq.insert(deq.begin(),5,888);
	printDeque(deq); 
	
	// erase(pos): ��ָ��λ��ɾ��Ԫ��,ֻɾ��һ��Ԫ��,pos��ҪΪ������ 
	deq.erase(deq.end());	// ɾ��ͷ������ 
	printDeque(deq);
	
	deque<int>::iterator it = deq.begin();
	it += 10;
	deq.erase(it); 			// ɾ����һ��λ�õ����� 					
	printDeque(deq);
	
	// ɾ��[deq.begin(), deq.end())�м���������ݣ��൱��clear() 
	deq.erase(deq.begin(),deq.end());
	printDeque(deq); 
	
} 

// ���˲����ɾ��
void test02(){
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
