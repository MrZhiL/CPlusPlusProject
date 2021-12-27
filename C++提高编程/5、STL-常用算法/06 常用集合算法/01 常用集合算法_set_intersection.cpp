#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 常用集合算法：交集  set_intersection(iteration beg1, end1, beg2, end2, dest);
// set_intersection返回的是迭代器，该迭代器指示的是取完交集后的容器的末尾 
// 注意：：：：：求交集的两个容器 必须是有序序列(且两个容器的序列需要为升序序列) 

void showPrint(int num){
	cout << num << "  "; 
}

void test01(){
	
	vector<int> vec1;
	vector<int> vec2;
	
	for(int i=0; i<10; i++){
		vec1.push_back(5+i);
		vec2.push_back(i);
	}
	
	cout << "vec1: ";
	for_each(vec1.begin(), vec1.end(), showPrint);
	cout << endl;
	
	cout << "vec2: ";
	for_each(vec2.begin(), vec2.end(), showPrint);
	cout << endl;
	
	// 取vec1和vec2容器的交集，存放到vec3容器中
	vector<int> vec3;
	// 需要为vec3容器提供空间，最特殊的情况是 一个容器包含另一个容器，因此此时vec3会有最大的内存空间分配
	// min(a,b)为取最小值的算法 
	vec3.resize(min(vec1.size(),vec2.size())); 
	
	// 取vec1和vec2容器的交集，存放到vec3容器中
	vector<int>::iterator vec3End = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	
	// 遍历vec3容器中的元素，查看是否存在交集 
	// 如果使用vec3.end()标志容器末尾，则会打印容器中所有的大小，没有取到交集的元素会自动赋值为0
	// 因此需要使用set_intersection函数仿函的迭代器 
	//for_each(vec3.begin(), vec3.end(), showPrint);
	
	if(vec3.empty()){
		cout << "两个容器没有交集！" << endl;
	}else{
		cout << "两个容器存在交集，交集元素为： "; 
		for_each(vec3.begin(), vec3End, showPrint);
		cout << endl;
	}
	
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
