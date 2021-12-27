#include<iostream>
#include<vector>

using namespace std;

// vector容器预留空间：通过合理使用该方法，可以大大减少开辟空间的次数 
// 函数：reserve(int len); 

void test01(){
	
	vector<int> vec;
	
	vec.reserve(100000);	// 利用reserve()函数给vec预留100000的空间大小，可以减少内存开辟次数 
		
	int num = 0;		// 统计vec赋值过程中，总共开启多少次内存空间 
	int *p = NULL;		// 用该指针指向开辟空间的地址 
	for(int i=0; i<100000; i++){
		vec.push_back(i);
		
		// 该if语句表示，判断指针p是否指向vec开辟空间的首地址，如果不等于，则让p指向首地址
		// 因为如果vec中存储的元素大小超过vec的容量，则会开辟一块新的地址，并将原来vec的元素重新复制到新的vec指向的地址中 
		if(p != &vec[0]){
			p = &vec[0];
			num++;
		} 
	}
	cout << "在对vec进行数据存储时，开辟空间的次数为：" << num << endl;	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
