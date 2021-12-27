#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// 常用算术生成算法: fill(iterator beg, iterator end, value); 将容器中[beg, end)区间中的所有元素填充为value元素 

void test01(){
	
	vector<int> vec;
//	for(int i=0; i<10; i++){
//		vec.push_back(i); 
//	} 
	// 后期填充 
	vec.resize(10); 
	
	// 打印容器中的元素
	cout << "容器中的元素为："; 
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << "  ";
	} 
	cout << endl;
	
	vector<int>::iterator it = vec.begin();
	it = it+5;
	
	fill(it, vec.end(), 111);
		 
	cout << "填充后容器中的元素为："; 
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << "  ";
	} 
	cout << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
} 
