#include <iostream>
#include <vector>		// vector������ͷ�ļ� 
#include <algorithm>	// ��׼�㷨ͷ�ļ� 

using namespace std;

// ʹ�������͵�������Ų���������

void printArray(int num){
	cout << num << endl;
} 

void test01(){
	
	vector<int> v;
	
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	
	// ��һ�����������е����ݣ�ͨ��whileѭ������Ϊ���ӣ�
	cout << "��һ��ͨ��whileѭ���͵��������������е����ݣ�" << endl;
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	
	while(itBegin != itEnd){
		cout << *itBegin++ << endl;
	} 
	
	
	// ������ͨ��forѭ�����������е����ݣ���
	cout << "������ͨ��forѭ���͵��������������е����ݣ�" << endl; 
	for(vector<int>::iterator it=v.begin(); it != v.end(); it++){
		cout << *it << endl;
	} 
	
	// ������ͨ����׼�㷨���������е�����
	cout << "������ͨ��algorithm�е��㷨���������е�����" << endl; 
	for_each(v.begin(), v.end(), printArray); 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
