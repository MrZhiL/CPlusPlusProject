#include<iostream>
#include<vector>

using namespace std;

// vector容器中的数据存取 
/**
	at(int idx);	//返回索引idx所指的数据 
	operator[];		//返回索引idx所指的数据 
	front();		//返回容器中第一个数据元素 
	back();			//返回容器中最后一个数据元素  
 */

void test01(){
	
	vector<int> vec;
	for(int i=0;i<10;i++){
		vec.push_back(i+1);
	}

	// vector容器中的数据存取
	for(int i=0;i<vec.size();i++){
		cout << "vec[" << i << "] = " << vec[i] << endl; // 使用operator[]重载运算符读取数据
	}
		
	for(int i=0;i<vec.size(); i++)
	cout << "vec.at(" << i << ")=" << vec.at(i) << endl; // 使用at(int idx)索下标为idx的数据
	
	cout << "容器中的第一个数据为：" << vec.front() << endl;
	cout << "容器中的最后一个数据为: " << vec.back() << endl; 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
