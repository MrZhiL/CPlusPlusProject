#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 二分法查找：bool binary_search(beg, end, value); 
// note: 只能在有序序列中使用，不可在无序序列中使用

void test01(){
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	//vec.push_back(8);
	// 如果查找的容器中元素没有规则（未排序），则无法保证查找的结果是否准确，即使有该元素，也可能查找不到 
	bool findVal = binary_search(vec.begin(), vec.end(), 9);
	
	if(findVal == true){
		cout << "查找到该元素!" << endl; 
	}else{
		cout << "未找到该元素!" << endl;
	}
	
} 
 
int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
