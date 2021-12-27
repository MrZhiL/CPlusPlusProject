#include<iostream>
#include<set>

using namespace std;

// 创建仿函数，改变排序规则
class MyCompare{
	
	public:
		bool operator() (int num1, int num2){
			// 使容器中的元素按从大到小的方式排序 
			return num1>num2;	
		}
};

void printSetRoom(const set<int> &st){
	
	if(st.empty()){
		cout << "容器为空！" << endl;
		return ;
	}
	
	for(set<int>::const_iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

void test01(){
	
	set<int> st;
	// set容器插入元素时，会进行默认排序
	// set容器使用insert插入元素后就已经排序，不可更改
	// 因此，如果想要改变排序规则，则需要在插入之前就改变排序规则 
	st.insert(10);
	st.insert(22);
	st.insert(8);
	st.insert(19);
	st.insert(43);
	
	// 遍历
	cout << "默认排序（从小到大）："; 
	printSetRoom(st);
	
	// 进行从大到小的排序 
	set<int,MyCompare> st2;
	// 通过仿函数改变容器的排序规则 
	st2.insert(10);
	st2.insert(22);
	st2.insert(8);
	st2.insert(19);
	st2.insert(43);
	// 遍历
	cout << "通过仿函数改变排序规则（从大到小）："; 
	
	for(set<int, MyCompare>::iterator it = st2.begin(); it != st2.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0;
} 
