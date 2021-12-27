#include<iostream>
#include<set>

using namespace std;

// set和multiset的区别
// set和multiset在插入数据后会自动进行排序
// set不允许重复插入元素，因为set容器在插入数据后，会返回插入的结果，表示插入是否成功
// multiset中当元素插入成功后，不会检测数据，所以可以重复插入 

void test01(){
	
	set<int> st;
	multiset<int> mst;
	
	pair<set<int>::iterator, bool> ret = st.insert(10);
	
	// 如果pair容器中返回的bool为真，则表示插入成功，否则表示插入失败 
	if(ret.second){
		cout << "第一个元素插入成功！" << endl; 
	}else{
		cout << "第二个元素插入失败！" << endl;
	}	

	ret = st.insert(10);
	if(ret.second){
		cout << "第一个元素插入成功！" << endl; 
	}else{
		cout << "第二个元素插入失败！" << endl;
	}
	
	
	mst.insert(11);
	mst.insert(11);
	for(multiset<int>::iterator it = mst.begin(); it != mst.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
