#include<iostream>
#include<set>

using namespace std;

//set/multiset容器的大小和交换

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
	st.insert(89);
	st.insert(79);
	st.insert(81);
	st.insert(8);
	st.insert(19);
	
	// 遍历容器，并打印数据元素 
	cout << "st1:"; 
	printSetRoom(st);
	
	cout << "插入元素后，st1容器的大小为：" << st.size() << endl;
	
	set<int> st2;
	st2.insert(1); 
	st2.insert(2); 
	st2.insert(9); 
	st2.insert(8); 
	
	cout << "st2:";
	printSetRoom(st2);
	cout << "插入元素后，st1容器的大小为：" << st.size() << endl;
	
	cout << "-------------------------------" << endl;
	cout << "将st1和st2容器进行数据交换，交换后：" << endl;
	st2.swap(st);
	cout << "st1: ";
	printSetRoom(st);
	cout << "st2: ";
	printSetRoom(st2);
	
} 

int main(){
	
	test01(); 
	
	system("pause");
	return 0; 
}
