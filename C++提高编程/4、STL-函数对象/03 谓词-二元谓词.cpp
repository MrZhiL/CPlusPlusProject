#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

// 谓词：如果仿函数返回值为bool类型，则为谓词
// 一元谓词；operator()函数中输入一个参数
// 二元谓词：operator()函数中输入两个参数 

class MyCompare{
	public:
		// 如果operator()函数返回值为bool类型， 则为谓词 
		bool operator() (int val1, int val2){
			return val1 > val2;	 
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
	v.push_back(50);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(10);
	
	cout << "排序前：";
	showVector(v);
	
	cout << "使用sort算法进行默认排序后：";
	sort(v.begin(), v.end());
	showVector(v); 
	
	cout << "使用仿函数改变排序规则为降序排序：";
	sort(v.begin(), v.end(), MyCompare()); 
	showVector(v); 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
