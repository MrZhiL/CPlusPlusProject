#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

// 内建函数对象：逻辑运算符
// bool logical_and<T>、bool logical_or<T>、bool logical_not<T> 

void showVector(vector<bool> &val){
	for(vector<bool>::iterator it = val.begin(); it != val.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

void test01(){
	
	vector<bool> v;
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);
	
	cout << "v: ";
	showVector(v);
	
	// 利用内建函数中的逻辑非运算符，将v进行取反操作，然后存储到v2中
	vector<bool> v2;
	// 将v2的空间扩大成v的大小，如果不分配空间，则会报错 
	v2.resize(v.size());
	// v2.reserve(v.size()); //reserve()预留函数不行，只能使用resize()函数 
	transform(v.begin(), v.end(), v2.begin(),logical_not<bool>());
	cout << "v2: ";
	showVector(v2); 
	
	// 利用内建函数中的逻辑与运算符，将v2与v3进行与操作，然后存储到v4中
	vector<bool> v3;
	vector<bool> v4;
	
	// 将v4的空间扩大成v3的大小，如果不分配空间，则会报错 
	v3.push_back(false);
	v3.push_back(true);
	v3.push_back(false);
	v3.push_back(true);
	v3.push_back(true);
	
	cout << "v3: ";
	showVector(v3);
	 
	v4.resize(v3.size());
	
	//将v2与v3进行与操作，然后存储到v4中
	//使用逻辑与和逻辑或操作时(如c=a&b)，transform中需要有：a.begin,a.end,b.begin,c.begin, logical_and<bool>();
	transform(v2.begin(), v2.end(), v3.begin(), v4.begin(), logical_and<bool>());
	
	cout << "v4(v2&v3): ";
	showVector(v4); 
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
