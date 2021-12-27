#include<iostream>
#include<set>

using namespace std;

//set/multiset容器的插入和删除操作 
// 使用find(key)查找key值是否存在，如果存在返回该元素的迭代器，如果不存在则返回set.end(); 
// 使用count(key) 统计key值的个数 

void printSetRoom(set<int> &st){
	
	if(st.empty()){
		cout << "容器为空@" << endl;
		return ;
	}
	
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  "; 
	}
	cout << endl;
}

void printMultiSetRoom(multiset<int> &st){
	
	if(st.empty()){
		cout << "容器为空@" << endl;
		return ;
	}
	
	for(multiset<int>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  "; 
	}
	cout << endl;
}


void test01(){
	
	multiset<int> st;
	
	// 遍历容器，并打印数据元素 
	cout << "插入数据前：" ; 
	printMultiSetRoom(st);
	
	cout << "--------------------------" << endl;
	cout << "插入数据后：" << endl;;
	// 使用insert函数插入数据元素 
	st.insert(89);
	st.insert(79);
	st.insert(81);
	st.insert(8);
	st.insert(19);
	st.insert(19);
	st.insert(19);
	
	// 遍历容器，并打印数据元素 
	cout << "st1:"; 
	printMultiSetRoom(st);
	
	cout << "插入元素后，st1容器的大小为：" << st.size() << endl;
	
	// st.find(key)返回的是迭代器，可以用*解引用找出数据
	//set<int>::iterator it = st.find(19); 
	cout << "元素19的所在的位置为：" << *st.find(89) << endl;
	
	// 统计容器中key元素的个数
	cout << "元素19的个数为：" << st.count(19) << endl; 
} 

int main(){
	
	test01(); 
	
	system("pause");
	return 0; 
}
