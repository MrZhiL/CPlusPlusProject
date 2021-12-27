#include<iostream>
#include<list>

using namespace std;

// list������list�����Ĵ����͸�ֵ

void printList(const list<int> &lst){
	
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

void test01(){
	
	list<int> lst;
	
	// �������в������ݣ�ʹ��ǰ��ͺ�壩 
	lst.push_back(11); 
	lst.push_back(22); 
	lst.push_back(33); 
	lst.push_front(10);
	lst.push_front(99);
	// ����list����ӡ�����е�Ԫ�� 
	printList(lst);
	
	// ���乹�죺������[lst.begin(), lst.end())���䷶Χ�ڵ��������ݸ�ֵ��lst2 
	list<int> lst2(lst.begin(), lst.end());
	printList(lst2); 
	
	// �������죺ʹ�ÿ������캯�����и�ֵ 
	list<int> lst3(lst2);
	lst3.pop_back();
	printList(lst3); 
	
	list<int> lst4(10,100);
	printList(lst4); 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
