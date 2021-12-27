#include <iostream>
#include <vector>		// vector容器的头文件 
#include <algorithm>	// 标准算法头文件 

using namespace std;

// 使用容器和迭代器存放并访问数据

void printArray(int num){
	cout << num << endl;
} 

void test01(){
	
	vector<int> v;
	
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	
	// 法一：遍历容器中的数据（通过while循环，较为复杂）
	cout << "法一：通过while循环和迭代器访问容器中的数据：" << endl;
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	
	while(itBegin != itEnd){
		cout << *itBegin++ << endl;
	} 
	
	
	// 法二：通过for循环遍历容器中的数据（）
	cout << "法二：通过for循环和迭代器访问容器中的数据：" << endl; 
	for(vector<int>::iterator it=v.begin(); it != v.end(); it++){
		cout << *it << endl;
	} 
	
	// 法三：通过标准算法遍历容器中的数据
	cout << "法三：通过algorithm中的算法遍历容器中的数据" << endl; 
	for_each(v.begin(), v.end(), printArray); 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
