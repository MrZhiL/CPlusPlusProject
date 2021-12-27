#include<iostream>
#include<vector>

using namespace std;

//实现两个容器内元素进行互换

void printVector(vector<int> &vec){
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
}

// 1、具体实现 
void test01(){
	
	vector<int> vec;
	for(int i=0; i<10; i++){
		vec.push_back(i);
		//vec[i] = 10+i;
	}
	cout << "交换前：" << endl; 
	printVector(vec);
	
	vector<int> vec2;
	for(int i=999; i>=990; i--){
		vec2.push_back(i);
	}
	printVector(vec2);
	
	// 交换后：
	cout << "交换后：" << endl; 
	vec.swap(vec2);
	printVector(vec);
	printVector(vec2);
}

// 2、应用案例： 
// 巧用容器互换，可以减少内存空间
void test02(){
	
	vector<int> vec;
	for(int i=0; i<100000; i++){
		vec.push_back(i);
	}
	cout << "vec的容量为：" << vec.capacity() << endl;
	cout << "vec的大小为：" << vec.size() << endl;
	
	// 巧用容器互换可以收缩内存空间
	vec.resize(10); 
	cout << "收缩vec容器中的数据大小为10后：" << endl; 
	cout << "vec的容量为：" << vec.capacity() << endl;
	cout << "vec的大小为：" << vec.size() << endl;
	
	vector<int> vec2 = vec;
	cout << "vec2的容量为：" << vec2.capacity() << endl;
	cout << "vec2的大小为：" << vec2.size() << endl;
	
	// vector<int>(vec)表示匿名对象，用完后系统立即进行销毁 
	vector<int>(vec).swap(vec);	//表示先创建一个匿名容器x，x(vec)表示进行拷贝构造函数，再将x与vec进行容器互换，之后将匿名容器进行销毁 
	cout << "进行容器交换后vec容器后：" << endl; 
	cout << "vec的容量为：" << vec.capacity() << endl;
	cout << "vec的大小为：" << vec.size() << endl;

} 
 
int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
	
} 
