#include<iostream>
#include<map> 

using namespace std;

// map容器的大小和交换 
// size();  empty();  swap(map<T,T> &st); 

void printMapRoom(const map<int, int> &mp) {
	
	if(mp.empty()){
		cout << "该容器为空！" << endl;
		return ;
	}
	for(map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++){
		cout << "key = " << (*it).first << ", value = " << it->second << endl; 
	}
	cout << endl;
}

void test01(){
	map<int, int> mp;

	// 在map容器中插入元素，插入元素时，不允许有重复的key值出现
	// 因为map容器有两个值，key和value，因此需要使用pair(对组)进行赋值 
	mp.insert(pair<int, int>(1, 10)); 
	mp.insert(pair<int, int>(5, 50)); 
	mp.insert(pair<int, int>(3, 50)); 
	mp.insert(pair<int, int>(4, 40)); 
	mp.insert(pair<int, int>(2, 20)); 
	mp.insert(pair<int, int>(1, 110)); 	// 插入失败，map容器中不允许有相同的key值 
	mp.insert(pair<int, int>(6, 10)); 	// 插入成功，允许有相同的value值 

	cout << "st容器的大小为：" << mp.size() << endl;	
	printMapRoom(mp);
	
	// 拷贝构造函数 
	map<int, int> mp2; 
	mp2.insert(pair<int, int>(101, 199)); 
	mp2.insert(pair<int, int>(102, 142)); 
	mp2.insert(pair<int, int>(103, 113)); 
	mp2.insert(pair<int, int>(108, 118)); 
	mp2.insert(pair<int, int>(106, 186)); 
	cout << "st2容器的大小为：" << mp2.size() << endl;
	printMapRoom(mp2);
	
	cout << "----------------------------------------" << endl;
	cout << "将st容器和st2容器交换后：" << endl;
	mp2.swap(mp);
	
	cout << "st容器：" << endl;
	cout << "st容器的大小为：" << mp.size() << endl;
	printMapRoom(mp);
	
	cout << "st2容器：" << endl;
	cout << "st2容器的大小为：" << mp2.size() << endl;
	printMapRoom(mp2);
	 
} 
 
int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
