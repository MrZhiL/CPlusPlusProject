#include<iostream>
#include<list>

using namespace std;

// list�����еĸ�ֵ�ͽ���
// assign(beg, end);			//��ֵ��������[beg, end)�����е�Ԫ�ظ�ֵ��������list���� 
// assign(n, elem);				//��n��elem��ֵ��������list���� 
// operator=(const list &lst);	//���صȺ����������lst��ֵ������������ 
// swap();						//������������������ 

void printList(const list<int> &lst){
	
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

void test01(){
	
	list<int> lst1;
	// �������в������ݣ�ʹ��ǰ��ͺ�壩 
	lst1.push_back(11); 
	lst1.push_back(22); 
	lst1.push_back(33); 
	lst1.push_front(10);
	lst1.push_front(9);
	// ����list����ӡ�����е�Ԫ�� 
	printList(lst1);
	cout << "lst1����Ĵ�СΪ��" << lst1.size() << endl;
	
	list<int> lst2;
	lst2 = lst1;		// ʹ�����غ�ĵȺŽ��и�ֵ���� 
	
	printList(lst2);
	cout << "lst2����Ĵ�СΪ��" << lst2.size() << endl;
	
	list<int> lst3;
	lst3.assign(++lst2.begin(),--lst2.end());
	printList(lst3);
	cout << "lst3����Ĵ�СΪ��" << lst3.size() << endl;
	
	cout << "---------------------------------" << endl; 
	cout << "lst2��lst3����ǰ��" << endl;
	lst3.push_back(100);
	lst3.push_front(99); 
	
	cout << "lst2����Ĵ�СΪ��" ;
	printList(lst2);
	cout << "lst3����Ĵ�СΪ��" ;
	printList(lst3);
	
	cout << "---------------------------------" << endl; 
	cout << "lst2��lst3������" << endl;
	lst3.swap(lst2);
	
	cout << "lst2����Ĵ�СΪ��" ;
	printList(lst2);
	cout << "lst3����Ĵ�СΪ��" ;
	printList(lst3);
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
