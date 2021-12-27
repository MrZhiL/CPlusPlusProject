#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 常用查找算法：find算法 

// 内置数据类型查找 
void showVec(int num){
	cout << num << "  ";
}
void test01(){
	vector<int> vec;
	vec.push_back(19); 
	vec.push_back(15); 
	vec.push_back(17); 
	vec.push_back(21); 
	vec.push_back(8);
	vec.push_back(19);
	
	// 打印vec容器中的元素
	for_each(vec.begin(), vec.end(), showVec); 
	cout << endl;
	
	// 查找内置数据类型是否存在,如果存在则返回该数据的迭代器，如果不存在则返回结束迭代器 
	vector<int>::iterator it = find(vec.begin(), vec.end(), 19);
	if(it == vec.end()){
		cout << "未找到该元素！" << endl;
	}else{
		cout << "找到该元素: " << *it << endl;
		//cout << *(++it) << endl; 
	}
	 
} 

// 自定义数据类型查找
class Person{
	public:
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		// 如果要查找自定义数据类型，则需要重载==运算符，告诉find函数如何对自定义数据类型对比
		bool operator==(const Person &p){
			if(p.m_Age == this->m_Age && p.m_Name == this->m_Name){
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
	vec.push_back(Person("曹操", 40));
	vec.push_back(Person("孙权", 38));
	
	// 查找自定义数据类型 
	Person pf("孙权", 38);
	vector<Person>::iterator it = find(vec.begin(), vec.end(), pf);
	// 判断是否查找到该元素 
	if(it == vec.end()){
		cout << "未找到该元素！" << endl;
	}else{
		cout << "找到该元素@该元素的姓名为：" << it->m_Name << ", 年龄为：" << it->m_Age << endl;  
	}
	
} 

int main(){
	
	//test01(); 
	test02();
	
	system("pause");
	return 0;
} 
