#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// reverse(iterator beg, iterator end); ��ת�㷨 

void PrintVec(int num){
	cout << num << "  ";
}

void test01(){
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	
	// ��ӡvec�����е�Ԫ��
	cout << "ԭ�����е�Ԫ�����У�" ;
	for_each(vec.begin(), vec.end(), PrintVec);
	cout << endl;
	 
	// ��vecԪ�ط�ת 
	reverse(vec.begin(), vec.end()); 
	cout << "��ת�������е�Ԫ������Ϊ��"; 
	for_each(vec.begin(), vec.end(), PrintVec);
	cout << endl;
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
