#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// transform算法：将容器中的元素拷贝到另一个容器中
// transform(v.begin(), v.end(), v2.begin(), _func); 

// transform中的仿函数 
class CopyVec{
	public:
		// 在该函数中可以进行逻辑运算 
		int operator() (int num){
			//return num; 
			return num+100;	// 可以进行逻辑运算 
		}
};

// for_each遍历元素的仿函数 
class PrintVec2{
	public:
		void operator()(int num){
			cout << num << "  ";
		}
};

void test01(){
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	
	vector<int> vec2;  // 目标容器，将vec中的元素拷贝到vec2中
	// 如果不对目标容器分配大小，且开辟空间的大小必须大于等于源容器的空间，则会报错
	vec2.resize(vec.size()); 
	
	transform(vec.begin(), vec.end(), vec2.begin(), CopyVec());
	
	for_each(vec2.begin(), vec2.end(), PrintVec2());
	cout << endl; 
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
