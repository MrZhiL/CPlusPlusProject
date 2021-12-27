#include<iostream>
#include<set>

using namespace std;

//set/multiset容器的插入和删除操作 

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
	
	set<int> st;
	
	// 遍历容器，并打印数据元素 
	cout << "插入数据前：" ; 
	printSetRoom(st);
	
	cout << "--------------------------" << endl;
	cout << "插入数据后：" << endl;;
	// 使用insert函数插入数据元素 
	st.insert(89);
	st.insert(79);
	st.insert(81);
	st.insert(8);
	st.insert(19);
	
	// 遍历容器，并打印数据元素 
	cout << "st1:"; 
	printSetRoom(st);
	
	cout << "插入元素后，st1容器的大小为：" << st.size() << endl;
	
	st.erase(st.begin());	// 删除位置为0的元素
	cout << "删除位置为1的元素后，st1的元素为：" ; 
	printSetRoom(st); 
	cout << "删除元素后，st1容器的大小为：" << st.size() << endl;
	
	st.erase(81);	// 删除值为81的所有元素 
	printSetRoom(st); 
	// 删除[begin,end)区间的所有元素,相当于clear() 
	st.erase(st.begin(),st.end());
	printSetRoom(st); 
	cout << "删除元素后，st1容器的大小为：" << st.size() << endl;
	
} 

int main(){
	
	test01(); 
	
	system("pause");
	return 0; 
}
