#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 查找相邻重复元素是否存在: adjacent_find(begin, end); 

void test01(){
	vector<int> vec;
	
	vec.push_back(10);	// 虽然后面也有元素10，但是不相邻 
	vec.push_back(14);
	vec.push_back(16);
	vec.push_back(12);	// 可以观察到12元素和相邻元素重复 
	vec.push_back(12);
	vec.push_back(10);
	vec.push_back(14);
	
	vector<int>::iterator it = adjacent_find(vec.begin(), vec.end());
	
	// 判断查找是否成功
	if(it != vec.end()){
		cout << "查找成功：" << *it << endl;
	}else{
		cout << "查找失败，容器中相邻元素无重复！" << endl;
	}
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
