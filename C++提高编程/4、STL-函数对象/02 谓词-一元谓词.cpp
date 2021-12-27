#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

// 谓词：如果仿函数返回值为bool类型，则为谓词
// 一元谓词；operator()函数中输入一个参数
// 二元谓词：operator()函数中输入两个参数 

class FindGraterFive{
	public:
		// 如果operator()函数返回值为bool类型， 则为谓词 
		bool operator() (int val){
			return val > 5;	// 判断大于5的数字是否存在 
		}
};

void test01(){
	
	vector<int> v;
	for(int i=0; i<10; i++){
		v.push_back(i);
	}
	
	// find_if返回的是一个迭代器 
	vector<int>:: iterator it = find_if(v.begin(), v.end(), FindGraterFive());
	if(it == v.end()){
		cout << "未找到大于5的数字！" << endl; 
	}else{
		cout << "找到大于5的数字：该值为：" << *it << endl; 		
	}
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
