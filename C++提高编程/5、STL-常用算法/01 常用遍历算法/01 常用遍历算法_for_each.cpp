#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 常用遍历算法：for_each
// for_each算法在algorithm头文件中 

void printVector01(int num){
	cout << num << "  ";
} 

class printVector02{
	public:
		void operator() (int num){
			cout << num << "  ";
		}
}; 

void test01(){
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	
	// 使用for_each算法遍历vec容器中的元素
	// 使用函数遍历，如果使用函数则只需要写入函数名即可 
	for_each(vec.begin(), vec.end(), printVector01); 
	cout << endl;
	
	// 使用仿函数遍历容器，此时需要表明函数对象也需要加上() 
	for_each(vec.begin(), vec.end(), printVector02());
	cout << endl;
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
