#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// �������������㷨: fill(iterator beg, iterator end, value); ��������[beg, end)�����е�����Ԫ�����ΪvalueԪ�� 

void test01(){
	
	vector<int> vec;
//	for(int i=0; i<10; i++){
//		vec.push_back(i); 
//	} 
	// ������� 
	vec.resize(10); 
	
	// ��ӡ�����е�Ԫ��
	cout << "�����е�Ԫ��Ϊ��"; 
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << "  ";
	} 
	cout << endl;
	
	vector<int>::iterator it = vec.begin();
	it = it+5;
	
	fill(it, vec.end(), 111);
		 
	cout << "���������е�Ԫ��Ϊ��"; 
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << "  ";
	} 
	cout << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
} 
