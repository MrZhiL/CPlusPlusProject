#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// �������������㷨: accumulate(iterator beg, iterator end, value); ����[beg,end)����������Ԫ�صĺ�
// all = value + sum(beg,end) 

void test01(){
	
	vector<int> vec;
	for(int i=0; i<=100; i++){
		vec.push_back(i); 
	} 
	
	vector<string> vecs;
	vecs.push_back("Hello");
	vecs.push_back("World");
	vecs.push_back("!");
	
	string sunStr = accumulate(vecs.begin(), vecs.end(), string(""));
	
	// ����vec����������Ԫ�ص��ܺ� 
	int sumNum = accumulate(vec.begin(), vec.end(), 1000);
	
	cout << "vec������Ԫ�ص��ܺ�Ϊ��" << sumNum << endl;
	cout << "vecsΪ:" << sunStr << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
} 
