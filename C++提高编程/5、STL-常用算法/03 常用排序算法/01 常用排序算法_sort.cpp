#include<iostream>
#include<vector>
#include<algorithm>
#include<functional> 

using namespace std;

// sort排序算法

void MyPrint(int num){
	cout << num << "  ";
}

void test01(){
	vector<int> vec;
	
	vec.push_back(13);
	vec.push_back(15);
	vec.push_back(26);
	vec.push_back(7);
	vec.push_back(11);
	
	// 升序排列
	sort(vec.begin(), vec.end());
	
	// 打印元素
	for_each(vec.begin(), vec.end(), MyPrint); 
	cout << endl;
	
	// 降序排序,可以使用内建函数对象greater来操作 ,可以使用functional头文件 
	sort(vec.begin(), vec.end(), greater<int>());
	 
	for_each(vec.begin(), vec.end(), MyPrint); 
	cout << endl;
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
 
