#include<iostream>
#include<algorithm>
#include<string> 
#include<vector>

using namespace std;

// 常用查找算法：_count_if(beg, end, _Pred);//按条件统计元素个数

// 内置数据类型按条件统计

class GrateThirteenNum{
	public:
		bool operator() (int num){
			return num >= 13;
		}
};

void test01(){
	vector<int> vec;
	
	vec.push_back(10);
	vec.push_back(13);
	vec.push_back(15);
	vec.push_back(11);
	vec.push_back(10);
	vec.push_back(10);
	vec.push_back(16);
	
	// 统计元素中大于等于13的个数
	int num = count_if(vec.begin(), vec.end(), GrateThirteenNum());
	
	cout << "vec容器中大于等于13的元素个数为：" << num << endl;
} 

// 自定义数据类型按条件统计 

class Person{
	public:
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		// 如果统计自定义数据类型，则需要重载对比操作符 
		bool operator== (const Person &p){
			if(this->m_Age == p.m_Age){
				return true;
			}else
				return false;
		} 
		
		string m_Name;
		int m_Age;
};

bool GrateThirteenNum02(const Person &p){
	if(p.m_Age >= 35){
		return true;
	}else{
		return false;
	}
}

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
	
	// 统计年龄大于等于35的人数 
	int num = count_if(vec.begin(), vec.end(), GrateThirteenNum02); 
	cout << "年龄大于35的人数共有：" << num << endl;
}

int main(){
	
	//test01();
	test02();
		
	system("pause");
	return 0;
}
