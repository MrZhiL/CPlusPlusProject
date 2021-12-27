#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 指定查找算法find_if
// find_if(v.begin, v.end, _Pred); 

// 内置数据类型查找 
class FindGrateFive{
	public:
		bool operator()(int num){
			return num>15;
		}
};
void test01(){
	
	vector<int> vec;
	for(int i=0; i<10; i++){
		vec.push_back(i+10);
	} 
	
	// 使用find_if查找vec容器中大于5的数 
	vector<int>::iterator it = find_if(vec.begin(), vec.end(), FindGrateFive());
	
	// 判断查找是否成功 
	if(it != vec.end()){
		cout << "查找成功@查找的值为：" << *it << endl;
	}else{
		cout << "查找失败！容器中没有该元素" << endl; 
	}
}

// 自定义数据类型的查找
class Person{
	public:
		
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		bool operator() (const Person &p){
//			if(p.m_Name == this->m_Name && p.m_Age == this->m_Age){
//				return true;
//			}else{
//				return false;
//			}
			if(p.m_Age > 30){
				return true;
			} else{
				return false;
			}
		}
		
		string m_Name;
		int m_Age;
};

class FindGrateAgeP{
	public:
		bool operator() (const Person &p){
			return p.m_Age > 35;
		}
};

void test02(){
	vector<Person> vec;
	
	vec.push_back(Person("张飞", 32));
	vec.push_back(Person("刘备", 29));
	vec.push_back(Person("关羽", 31));
	vec.push_back(Person("曹操", 40));
	vec.push_back(Person("孙权", 38));
	
	Person pfind("孙权",38);
	
	// 查找年龄大于30的成员 
	vector<Person>::iterator it = find_if(vec.begin(), vec.end(), FindGrateAgeP());
	
	// 判断是否查找成功
	if(it != vec.end()){
		cout << "查找成功！该元素的姓名为：" << it->m_Name << ", 年龄为：" << it->m_Age << endl;
		//cout << "查找成功！该元素的姓名为：" << (++it)->m_Name << ", 年龄为：" << (++it)->m_Age << endl;
	} else{
		cout << "查找失败！容器中没有该元素" << endl;
	}
} 

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
