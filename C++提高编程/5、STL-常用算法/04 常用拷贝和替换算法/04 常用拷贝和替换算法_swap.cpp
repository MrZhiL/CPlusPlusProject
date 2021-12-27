#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// swap(container c1, container c2); // �������������е�Ԫ�� 

void MyPrint(int num){
	cout << num << "  ";
}

void test01(){
	
	vector<int> vec1;
	vector<int> vec2;
	
	for(int i=0; i<10; i++){
		vec1.push_back(i+1);
		vec2.push_back(5*i);
	} 
	
	// ��ӡ���������е�Ԫ��
	cout << "����ǰ��vec1: ";
	for_each(vec1.begin(), vec1.end(), MyPrint); 
	cout << endl;
	
	cout << "����ǰ��vec2: ";
	for_each(vec2.begin(), vec2.end(), MyPrint); 
	cout << endl;
	
	cout << "--------------------------------------------" << endl;
		
	// �������������е�Ԫ��
	swap(vec1,vec2);
	cout << "����ǰ��vec1: ";
	for_each(vec1.begin(), vec1.end(), MyPrint); 
	cout << endl;
	
	cout << "����ǰ��vec2: ";
	for_each(vec2.begin(), vec2.end(), MyPrint); 
	cout << endl;
	 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}  
