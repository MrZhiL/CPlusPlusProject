#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// replace(iterator beg, iterator end, oldvalue, newvalue); �������еľ�Ԫ���滻Ϊ��Ԫ�� 

void MyPrint(int num){
	cout << num << "  ";
}

void test01(){
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	} 
	vec.push_back(5); 
	vec.push_back(15); 
	vec.push_back(5); 
	
	cout << "�滻ǰvecԪ������Ϊ��";
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl; 
	
	// ��������begin,end�����е�5�滻Ϊ10 
	replace(vec.begin(), vec.end(), 5,10); 
	cout << "�滻��vecԪ������Ϊ��";
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl; 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
