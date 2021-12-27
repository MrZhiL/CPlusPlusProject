#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// 常用查找算法_count(beg, end, value);

// 1、统计内置数据类型

void test01(){
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(13);
	vec.push_back(15);
	vec.push_back(11);
	vec.push_back(10);
	vec.push_back(10);
	
	// 统计vec容器中元素10的数量
	int num = count(vec.begin(), vec.end(), 10); 
	
	cout << "元素10的个数为：" << num << endl;
}

// 2、统计自定义数据类型 
class Person{
	public:
		Person(string name, int age){
			this->m_Name = name,
			this->m_Age = age;
		}
		
		// 如果统计自定义数据类型，则需要重载== 
		bool operator== (const Person &p){
			if(this->m_Age == p.m_Age){
				return true;
			}else{
				return false;
			}
		}
		
		string m_Name;
		int m_Age;
};
void test02(){
	vector<Person> vec;
	
	vec.push_back(Person("张飞", 32));
	vec.push_back(Person("刘备", 29));
	vec.push_back(Person("关羽", 31));
	vec.push_back(Person("庞德", 40));
	vec.push_back(Person("曹操", 40));
	vec.push_back(Person("孙权", 38));
	vec.push_back(Person("小乔", 32));
	vec.push_back(Person("大桥", 32));
	
	// 统计年龄为32的人数 
	int num = count(vec.begin(), vec.end(), Person("as",32));
	cout << "年龄为32的共有 " << num << "人！" << endl;
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
