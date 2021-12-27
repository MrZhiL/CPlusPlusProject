#include<iostream>
#include<list>

using namespace std;

// list�����еĲ����ɾ��

void printList(const list<int> &lst){
	if(lst.empty()){
		cout << "������Ϊ�գ�@" << endl;
	}
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

void test01(){
	list<int> lst;
	
	//ʹ��push_back()������β���������ݣ�β�巨�� 
	for(int i=0; i<10; i++){
		lst.push_back(i+2);
	} 
	cout << "1: �����е�Ԫ��Ϊ��" ;
	printList(lst); 
		//ɾ������pos��Ԫ��
	int a = *lst.erase(lst.begin());
	cout << "5: �����е�Ԫ��Ϊ��" << a << endl;;
	printList(lst);
	
	//��lstͷ������10��9 
	lst.insert(lst.begin(),10,9);
	cout << "2: �����е�Ԫ��Ϊ��" ;
	printList(lst);
	
	//��lstβ������999 
	lst.insert(lst.end(),999);
	cout << "3: �����е�Ԫ��Ϊ��" ;
	printList(lst);
	
	//��posλ�ò���[beg, end)���������Ԫ�� 
	lst.insert(lst.begin(),lst.begin(), lst.end());
	cout << "4: �����е�Ԫ��Ϊ��" ;
	printList(lst);
	
	//ɾ������pos��Ԫ��
	lst.erase(--lst.end()); 
	cout << "5: �����е�Ԫ��Ϊ��" ;
	printList(lst);
		
	//ɾ�������е�������ֵΪ9��Ԫ��
	lst.remove(9);
	cout << "6: �����е�Ԫ��Ϊ��" ;
	printList(lst);
 
	//ɾ��[beg, end)���������Ԫ��
	lst.erase(++lst.begin(),--lst.end());
	cout << "7: �����е�Ԫ��Ϊ��" ;
	printList(lst);
	
	//��������е�����Ԫ��
	lst.clear();
	cout << "8: �����е�Ԫ��Ϊ��" ;
	printList(lst);
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
 
