#include<iostream>
#include<map> 

using namespace std;

// map容器的构造和赋值 
// map容器在插入元素的时候，会自动按照key值进行排序
// map容器中不允许重复插入相同的key值，但是value值可以相同

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
	
	printMapRoom(mp);
	
	// 拷贝构造函数 
	map<int, int> mp2(mp); 
	printMapRoom(mp2);
	
	// 赋值
	map<int, int> mp3;
	mp3 = mp2;
	printMapRoom(mp3);
	 
} 
 
int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
