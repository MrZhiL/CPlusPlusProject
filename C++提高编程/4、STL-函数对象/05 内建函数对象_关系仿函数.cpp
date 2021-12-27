#include<iostream>
#include<functional>
#include<vector>
#include<algorithm> 
using namespace std;

// 内置函数对象：关系仿函数 

class MyCompare{
	public:
		bool operator() (int num1, int num2){
			return num1 > num2;
		}
};

void showVector(vector<int> &val){
	for(vector<int>::iterator it = val.begin(); it != val.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

void test01(){
	
	vector<int> v;
	v.push_back(10);
	v.push_back(44);
	v.push_back(23);
	v.push_back(46);
	v.push_back(29);
	
	cout << "排序前：";
	showVector(v); 
	
//	sort(v.begin(), v.end(), MyCompare());
//	cout << "通过自己创建的仿函数进行降序排序：";
//	showVector(v);
	
	// 通过内建函数对象greater对容器进行降序排序 
	cout << "通过内建对象greater对荣球场进行降序排序：";
	sort(v.begin(), v.end(), greater<int>());
	showVector(v); 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
