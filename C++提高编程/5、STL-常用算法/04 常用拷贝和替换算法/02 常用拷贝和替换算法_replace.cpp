#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// replace(iterator beg, iterator end, oldvalue, newvalue); 将容器中的旧元素替换为新元素 

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
	
	cout << "替换前vec元素序列为：";
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl; 
	
	// 将容器中begin,end区间中的5替换为10 
	replace(vec.begin(), vec.end(), 5,10); 
	cout << "替换后vec元素序列为：";
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl; 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
