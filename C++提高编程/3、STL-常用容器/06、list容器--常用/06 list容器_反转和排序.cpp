#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//list�����ķ�ת������
//reverse(); ��ת����������
//sort(); �������е����ݽ������� 

void printList(const list<int> &lst){
	if(lst.empty()){
		cout << "������Ϊ�գ�@" << endl;
	}
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

bool myCompare(int v1, int v2){
	// ���Ҫʵ�ֽ�����������Ҫv1 > v2
	return v1 > v2; 
}

//����ʵ�� 
void test01(){
	
	list<int> lst;
	
	lst.push_back(100);
	lst.push_back(200);
	lst.push_front(10);
	lst.push_front(20);
	
	cout << "����ǰ��";
	// ����list���� 
	printList(lst); 
	cout << "list�����еĵ�һ������Ԫ��Ϊ��" << lst.front() << endl; 
	cout << "list�����е��������Ԫ��Ϊ��" << lst.back() << endl; 
	
	cout << "�����";
	lst.sort();		// Ĭ������Ϊ�������� 
	// ����list���� 
	printList(lst); 
	cout << "list�����еĵ�һ������Ԫ��Ϊ��" << lst.front() << endl; 
	cout << "list�����е��������Ԫ��Ϊ��" << lst.back() << endl;  
	cout << "��������";
	lst.sort(myCompare); 
	printList(lst); 
	
	//��������з�ת
	cout << "��������з�ת��";
	lst.reverse(); 
	printList(lst); 
	cout << "list�����еĵ�һ������Ԫ��Ϊ��" << lst.front() << endl; 
	cout << "list�����е��������Ԫ��Ϊ��" << lst.back() << endl;  
	
	// ���в�֧��������ʵĵ����������������ñ�׼�㷨�� 
	// ��֧��������ʵ��������������ڲ����ṩ��Ӧ��һЩ�㷨 
	//sort(lst.begin(), lst.end()); // ʹ�ñ�׼���е������㷨�ᱨ�� 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
