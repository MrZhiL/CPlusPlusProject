#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// 常用算术生成算法: accumulate(iterator beg, iterator end, value); 计算[beg,end)区间中所有元素的和
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
	
	// 计算vec容器中所有元素的总和 
	int sumNum = accumulate(vec.begin(), vec.end(), 1000);
	
	cout << "vec容器中元素的总和为：" << sumNum << endl;
	cout << "vecs为:" << sunStr << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
} 
