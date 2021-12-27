#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 常用集合算法：set_difference(beg1, end1, beg2, end2, dest); 
// 注意：两个集合必须是有序序列

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
	
	// 求两个容器的差集，并存放到vec4容器中 
	vector<int> vec4;
	vec4.resize( max(vec1.size(), vec2.size()) ); 
	
	//1、vec1和vec2的差集
	cout << "vec1和vec2的差集："; 
	vector<int>::iterator itEnd = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec4.begin());
	for_each(vec4.begin(), itEnd, ShowPrint);
	cout << endl;
	
	//2、vec2和vec1的差集 
	cout << "vec1和vec2的差集："; 
	itEnd = set_difference(vec2.begin(), vec2.end(), vec1.begin(), vec1.end(), vec4.begin());
	for_each(vec4.begin(), itEnd, ShowPrint);
	cout << endl;
	
} 


int main(){
	
	test01();
	
	system("pause");
	return 0;
}
