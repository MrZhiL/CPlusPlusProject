#include<iostream>
#include<map>

using namespace std;

// map容器的排序规则默认为升序，要想改变排序规则需要利用仿函数

// 仿函数
class MyCompare{
	
	public:
		// 使用仿函数，改变排序规则 
		bool operator() (const int &m1, const int &m2){
			// 改变排序规则为：从大到小，降序排列 
			return m1 > m2;
		}
	
};

class Person{
	public:
		
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		string m_Name;
		int m_Age;
	
}; 

// 自定义数据类型的仿函数（错误，使用上面的仿函数即可，因为是对键值进行排序，因此应该为int数据类型，而不是Person数据类型） 
class MyCompare2{
	
	public:
		// 使用仿函数，改变排序规则 
		bool operator() (const Person &p1, const Person &p2){
			// 改变排序规则为：从大到小，降序排列 
			return p1.m_Age > p2.m_Age;
		}
	
};

void printMapRoom(const map<int, int, MyCompare> &mp){
	if(mp.empty()){
		cout << "该容器为空@" << endl;
	}
	for(map<int, int, MyCompare>::const_iterator it = mp.begin(); it != mp.end(); it++){
		cout << "key = " << it->first << " ,value = " << it->second << endl;
	}
	cout << endl;
}

// 内置数据类型：通过仿函数改变排序规则：从大到小排序 
void test01(){
	
	// 内置数据类型：通过仿函数改变排序规则：从大到小排序 
	map<int, int, MyCompare> mp;
	mp.insert(make_pair(1,10));
	mp.insert(make_pair(3,21));
	mp.insert(make_pair(5,16));
	mp.insert(make_pair(2,17));
	
	mp.insert(map<int, int>::value_type(4,23));
	
	printMapRoom(mp);
	
}

// 自定义数据类型改变排序规则 
void test02(){
	
	map<int, Person, MyCompare> mp;
	mp.insert(make_pair(1,Person("张飞",27)));
	mp.insert(make_pair(3,Person("刘备",26)));
	mp.insert(make_pair(5,Person("关羽",25)));
	mp.insert(make_pair(4,Person("曹操",32)));
	mp.insert(make_pair(2,Person("孙权",28))); 
	
	for(map<int, Person, MyCompare>::iterator it = mp.begin(); it != mp.end(); it++){
		cout << "键值为：" << it->first << ", 值：姓名 " << it->second.m_Name << ", 年龄  " << it->second.m_Age << endl; 
	}
	
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
