#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;

// merge算法：将两个容器合并，并存储到另一容器中
/**
	merge(iterator beg1, iterator end, iterator beg2, iterator end2, iterator dest);
  //两个容器合并，并存储到另一容器中
  //！！！！！！注意：两个容器必须是有序的（且两个容器的排序方式相同）！！！！！！！！
  //beg1：容器1开始迭代器，end1：容器1结束迭代器，
  //beg2：容器2开始迭代器，end2：容器2结束迭代器
  //dest：目标容器开始迭代器 
*/ 

void MyPrint(int num){
	cout << num << "  ";
}

void test01(){
	
	srand((unsigned int)time(NULL));
	
	vector<int> vec1;
	vector<int> vec2;
	
	for(int i=0; i<10; i++){
		vec1.push_back(rand()%10+1);
		vec2.push_back(rand()%10+2);
	}
	
	cout << "vec1容器中的元素为：";
	for_each(vec1.begin(), vec1.end(), MyPrint);
	cout << endl;
	
	cout << "vec2容器中的元素为：";
	for_each(vec2.begin(), vec2.end(), MyPrint);
	cout << endl;
	
	// 将容器vec1和vec2中的元素合并，并存放到vec3中 
	// 注意此时vec1和vec2中的元素一定要有序，否则出来的结果是无序的 
	vector<int> vec3;
	
	// 需要对vec3容器分配大小，要不会报错 
	vec3.resize(vec1.size()+vec2.size());
	
	sort(vec1.begin(), vec1.end()); 
	sort(vec2.begin(), vec2.end()); 
	
	// 此时vec3中的容器也是有序的 
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	
	cout << "vec3容器中的元素为：";
	for_each(vec3.begin(), vec3.end(), MyPrint); 
	cout << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
