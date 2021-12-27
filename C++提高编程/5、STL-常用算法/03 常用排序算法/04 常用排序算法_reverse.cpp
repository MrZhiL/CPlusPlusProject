#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// reverse(iterator beg, iterator end); 反转算法 

void PrintVec(int num){
	cout << num << "  ";
}

void test01(){
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	
	// 打印vec容器中的元素
	cout << "原容器中的元素序列：" ;
	for_each(vec.begin(), vec.end(), PrintVec);
	cout << endl;
	 
	// 将vec元素反转 
	reverse(vec.begin(), vec.end()); 
	cout << "反转后容器中的元素序列为："; 
	for_each(vec.begin(), vec.end(), PrintVec);
	cout << endl;
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
