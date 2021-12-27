#include<iostream>
#include<map>

using namespace std;

// map冗长的查找和统计 
// 使用find查找key值是否存在，如果存在则返回该值的迭代器，如果不存在则返回mp.end(); 
// count(key) 函数用来统计键值为key的元素个数，返回值为整形 

void printMapRoom(const map<int, int> &mp){
	if(mp.empty()){
		cout << "该容器为空@" << endl;
	}
	for(map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++){
		cout << "key = " << it->first << " ,value = " << it->second << endl;
	}
	cout << endl;
}

void test01(){
	map<int, int> mp;
	mp.insert(make_pair(1,10));
	mp.insert(make_pair(3,21));
	mp.insert(make_pair(5,16));
	mp.insert(make_pair(2,17));
	
	mp.insert(map<int, int>::value_type(4,23));
	
	printMapRoom(mp);
	
	int i;
	cout << "请输入查找的键值："; 
	cin >> i;
	// 使用find查找key值是否存在，如果存在则返回该值的迭代器，如果不存在则返回mp.end(); 
	if(mp.find(i) != mp.end()){
		cout << "键值为" << i << "的元素存在，该元素为键值为：" << mp.find(i)->first << ", 值为：" << (*mp.find(i)).second << endl; 
	}else{
		cout << "找不到该键值@" << endl;
	}
	
	// map中不允许插入重复的键值，因此mp.count(key)的返回值为1或0
	// multtimap可以插入重复的键值，因此返回值可以大于1 
	cout << "键值为" << i << "的元素个数为：" << mp.count(i) << endl; 
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
