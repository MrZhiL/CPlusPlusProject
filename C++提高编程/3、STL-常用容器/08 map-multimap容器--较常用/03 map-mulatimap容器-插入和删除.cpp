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
	
	// 第一种插入方式 
	mp.insert(pair<int, int>(1, 10)); 
	mp.insert(pair<int, int>(5, 50)); 
	mp.insert(pair<int, int>(3, 50)); 
	mp.insert(pair<int, int>(4, 40)); 
	mp.insert(pair<int, int>(2, 20)); 
	mp.insert(pair<int, int>(1, 110)); 	// 插入失败，map容器中不允许有相同的key值 
	mp.insert(pair<int, int>(6, 10)); 	// 插入成功，允许有相同的value值 
	
	// 第二种插入方式（推荐使用该种方法） 
	mp.insert(make_pair(7,77));
	
	// 第三种插入方式
	mp.insert(map<int, int>::value_type(8,88));
	
	// 第四种插入方式---不建议使用该种方式 
	mp[9] = 99;
	
	// 如果打印的mp[key]元素中，键值为key的元素不存在，则编译器自动创建mp[key] = 0
	// mp[key]该种方法可以通过key值访问到value值 
	cout << "mp[9] = " << mp[9] << endl; 
	
	cout << "st容器的大小为：" << mp.size() << endl;	
	printMapRoom(mp);
	
	// 删除key为key的的元素
	mp.erase(1); 
	cout << "st容器的大小为：" << mp.size() << endl;	
	printMapRoom(mp);
	
	// 删除mp容器中的最后一个元素,容器中的最后一个元素位置为--mp.end() 
	mp.erase(--mp.end());
	cout << "st容器的大小为：" << mp.size() << endl;	
	printMapRoom(mp); 
	
	// 删除[beg,end)区间的所有元素,beg和end用迭代器表示
	mp.erase(++mp.begin(),--mp.end());
	cout << "st容器的大小为：" << mp.size() << endl;	
	printMapRoom(mp);
	
	// 删除所有元素 
	mp.clear();
	cout << "st容器的大小为：" << mp.size() << endl;	
	printMapRoom(mp);
	
} 
 
int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
