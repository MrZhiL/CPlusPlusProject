#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// copy(iterator beg, iterator end, iterator dest); 拷贝函数 

void MyPrint(int num){
	cout << num << "  ";
}

void test01(){
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(rand()%10+1);
	}
	
	cout << "vec容器中的元素为：";
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl;
	
	// 将vec容器中的元素拷贝到vec2中
	
	vector<int> vec2;
	vec2.resize(vec.size());
	
	copy(vec.begin(), vec.end(), vec2.begin());
	cout << "vec2容器中的元素为：";
	for_each(vec2.begin(), vec2.end(), MyPrint);
	cout << endl;	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
