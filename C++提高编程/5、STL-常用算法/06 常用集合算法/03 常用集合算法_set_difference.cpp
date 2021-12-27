#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ���ü����㷨��set_difference(beg1, end1, beg2, end2, dest); 
// ע�⣺�������ϱ�������������

void ShowPrint(int num){
	cout << num << "  ";
} 

void test01(){
	
	vector<int> vec1;
	vector<int> vec2;
	
	for(int i=0; i<10; i++){
		vec1.push_back(i);
		vec2.push_back(i+5);
	}
	
	cout << "vec1: ";
	for_each(vec1.begin(), vec1.end(), ShowPrint);
	cout << endl;
	
	cout << "vec2: ";
	for_each(vec2.begin(), vec2.end(), ShowPrint);
	cout << endl;
	
	// �����������Ĳ������ŵ�vec4������ 
	vector<int> vec4;
	vec4.resize( max(vec1.size(), vec2.size()) ); 
	
	//1��vec1��vec2�Ĳ
	cout << "vec1��vec2�Ĳ��"; 
	vector<int>::iterator itEnd = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec4.begin());
	for_each(vec4.begin(), itEnd, ShowPrint);
	cout << endl;
	
	//2��vec2��vec1�Ĳ 
	cout << "vec1��vec2�Ĳ��"; 
	itEnd = set_difference(vec2.begin(), vec2.end(), vec1.begin(), vec1.end(), vec4.begin());
	for_each(vec4.begin(), itEnd, ShowPrint);
	cout << endl;
	
} 


int main(){
	
	test01();
	
	system("pause");
	return 0;
}
