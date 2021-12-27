#include<iostream>
#include<vector>

using namespace std;

// vector构造函数
/** 
	vector<T> v;					//采用模板类实现，默认构造函数 
	vector<v.begin(), v.end());		//将[v.begin(),v.end())区间(前闭后开)中的元素拷贝给自身 
	vector(n, elem);				//构造函数将n个elem拷贝给本身 
	vector(const vector &vec); 		//拷贝构造函数  
*/ 

// 对vector容器中的数据进行输出 
void printVector(vector<int> &vec){
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
} 

void test01(){
	
	// 1、默认构造函数，无参构造 
	vector<int> v1;
	
	for(int i=0; i<10; i++){	// 对v1进行赋值 
		v1.push_back(i);
	} 
	printVector(v1);
	
	// 2、vector<v.begin(), v.end())：将[v.begin(),v.end() )中的数据拷贝
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);
	
	// 3、vector(n, elem)：将n个elem数据赋值给vector容器
	vector<int> v3(10,100);	//将10个100赋值给v3
	printVector(v3);
	
	// 4、vector(const vector &vec)：拷贝构造函数
	vector<int> v4(v3);
	printVector(v4);
	 
}


int main(){

	test01();
		
	system("pause");
	return 0;
} 
