#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// vector容器中存放自定义数据类型 

class Person{
	
	public:
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		string m_Name;
		int m_Age;
}; 

void printPerson(const Person &p){
	cout << "name: " << p.m_Name << ", age: " << p.m_Age << endl; 
}

void test01(){
	
	vector<Person> v;
	
	v.push_back(Person("孙悟空",500));
	v.push_back(Person("猪八戒",800));
	v.push_back(Person("白骨精",777));
	v.push_back(Person("沙和尚",400));
	v.push_back(Person("白龙马",300));
	
	// 法一：使用迭代器遍历容器中的数据
	cout << "法一：使用迭代器便利容器中的数据！" << endl; 
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
		//cout << "name: " << it->m_Name << ", age: " << it->m_Age << endl;  // 直接用指针或解引用后输出都可以 
		cout << "name: " << (*it).m_Name << ", age: " << (*it).m_Age << endl; // (*it)表示Person数据类型，此时可以(*it).m_Age。但*it.m_Age不对 
	}
	
	// 法二：使用标准算法遍历容器
	cout << "法二：使用algorithm中的算法便利容器！" << endl; 
	for_each(v.begin(), v.end(), printPerson);
	
}

void printPerson2(const Person *p){
	cout << "name: " << p->m_Name << ", age: " << p->m_Age << endl; 
}

// 存放自定义数据类型的指针
void test02(){
	
	vector<Person*> v;
	
	Person *p1 = new Person("孙悟空",500);
	Person *p2 = new Person("猪八戒",800);
	Person *p3 = new Person("白骨精",777);
	Person *p4 = new Person("沙和尚",400);
	Person *p5 = new Person("白龙马",300);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	// 法一：使用迭代器遍历容器中的数据
	cout << "法一：使用迭代器便利容器中的数据！" << endl; 
	for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
		//cout << "name: " << it->m_Name << ", age: " << it->m_Age << endl;  // 直接用指针或解引用后输出都可以 
		cout << "name: " << (*it)->m_Name << ", age: " << (*it)->m_Age << endl; // (*it)表示Person数据类型，此时可以(*it).m_Age。但*it.m_Age不对 
	}
	
	// 法二：使用标准算法遍历容器
	cout << "法二：使用algorithm中的算法便利容器！" << endl; 
	for_each(v.begin(), v.end(), printPerson2);
	
} 

int main(){

	//test01();
	test02();
	
	system("pause");
	return 0;
} 

