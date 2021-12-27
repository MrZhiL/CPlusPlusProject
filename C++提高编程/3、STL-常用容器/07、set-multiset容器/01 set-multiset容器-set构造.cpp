#include<iostream>
#include<set>

using namespace std;

// set-multiset容器的构造函数
// set/multiset容器中是按二叉树的方式存储数据 

// set容器的特点：插入数据后会自动进行排序，且set容器中不允许插入重复的元素
// multiset容器：插入数据后也会自动进行排序，但multiset容器可以插入重复的元素 
// multiset和set容器都是用set一个头文件

//template<class T>  
void printSetRoom(set<int> &st){
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  "; 
	}
	cout << endl;
}

void printMultiSetRoom(multiset<int> &st){
	for(multiset<int>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  "; 
	}
	cout << endl;
}

void test01(){
	
	// 创建set容器，默认构造函数 
	set<int> set1;
	
	// set容器只能用insert插入元素，且不允许插入重复的元素 
	set1.insert(10);
	set1.insert(8);
	set1.insert(20); 
	set1.insert(30); 
	set1.insert(50); 
	
	printSetRoom(set1);
	
	// 拷贝构造函数 
	set<int> set2(set1); 
	printSetRoom(set1);
	
	// 赋值（重载等号运算符） 
	set<int> set3;
	set3 = set2; 
	printSetRoom(set1);
	
	// multiset容器,允许插入重复的元素 
	multiset<int> mst;
	mst.insert(3); 
	mst.insert(111); 
	mst.insert(21); 
	mst.insert(31); 
	mst.insert(8); 
	mst.insert(31); 
	printMultiSetRoom(mst);
	cout << *mst.rbegin() << endl; 
	cout << *mst.begin() << endl; 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
