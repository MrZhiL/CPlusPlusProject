#include<iostream>
#include<list>

using namespace std;

//list���ݴ�ȡ
//list[idx]��������[]����list�е�������ֻ�ܷ������˵����ݣ��������������
//lst.at(0); ��������at��ʽ����list�����е����ݣ�
//ԭ������list����������һ�������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������� 

//���õ��������Է�������Ԫ�أ���������++��--�� 

void printList(const list<int> &lst){
	if(lst.empty()){
		cout << "������Ϊ�գ�@" << endl;
	}
	for(list<int>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
} 

//����ʵ�� 
void test01(){
	
	list<int> lst;
	
	lst.push_back(100);
	lst.push_back(200);
	lst.push_front(10);
	lst.push_front(20);
	
	// ����list���� 
	printList(lst); 
	
	cout << "list�����еĵ�һ������Ԫ��Ϊ��" << lst.front() << endl; 
	cout << "list�����е��������Ԫ��Ϊ��" << lst.back() << endl; 
	
	//��֤��������֧���������
	list<int>::iterator it = lst.begin();
	it++;	// ������֧��ǰ������ͺ����������˫����� 
	it--; 
	//it = it + 1;	// ��������˵�����õ�������֧��������� 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
