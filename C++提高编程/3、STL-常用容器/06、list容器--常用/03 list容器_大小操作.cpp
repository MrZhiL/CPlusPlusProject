#include<iostream>
#include<list>

using namespace std; 

// ����Ĵ�С����
// size(); ���������Ĵ�С
// resize(int num); �����趨�����Ĵ�С���������ֲ�Ĭ��ֵ0�����ಿ��ɾ��
// resize(int num, elem) �����趨�����Ĵ�С���������ֲ�elem�����ಿ��ɾ��
// empty(); �ж������Ƿ�Ϊ��
 
void printList(const list<int> &lst){
	// �ж������Ƿ�Ϊ�� 
	if(lst.empty()){
		cout << "������Ϊ��@" << endl;
		return ; 
	} 
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

void test01(){
	
	// ����list����
	list<int> lst;
	
	// ����������Ԫ��	
	for(int i=0; i<10; i++){
		lst.push_back(i+1);
	} 
	cout << "1��lst�����Ĵ�СΪ��" << lst.size() << endl;
	printList(lst);
	
	// �����趨lst������СΪ15���������ֲ���Ĭ��ֵ0 
	lst.resize(15);
	cout << "2��lst�����Ĵ�СΪ��" << lst.size() << endl;
	printList(lst);
	
	// �����趨lst������СΪ15���������ֲ���elem��111�� 
	lst.resize(20,111);
	cout << "3��lst�����Ĵ�СΪ��" << lst.size() << endl;
	printList(lst);
	
	lst.resize(10,111);
	cout << "4��lst�����Ĵ�СΪ��" << lst.size() << endl;
	printList(lst);
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0; 
}
 
