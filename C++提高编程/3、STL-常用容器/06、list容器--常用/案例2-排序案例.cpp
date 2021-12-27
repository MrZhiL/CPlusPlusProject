#include<iostream>
#include<list>
#include<string>

using namespace std;

// 排序案例：将Person自定义数据类型进行排序，Person中属性有姓名、身高、年龄
// 排序规则：按照年龄进行升序，如过年龄相同则按照身高进行降序 

class Person{
	
	public:
		Person(){};
		Person(string name, float height, int age){
			this->m_Name = name;
			this->m_Height = height;
			this->m_Age = age;
		} 
		
		string m_Name;		//姓名 
		int m_Height;		//身高 
		int m_Age;			//年龄 
	
};

void printList(const list<Person> &lst){
	
	for(list<Person>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << "姓名： " << it->m_Name << "\t身高： " << it->m_Height << "\t年龄： " << it->m_Age << endl; 
	}
	cout << endl;
}

// 通过函数或仿函数 对 容器的排序指定规则
bool PersonCompare(Person &p1, Person &p2){
	
	if(p1.m_Age == p2.m_Age){
		return (p1.m_Height > p2.m_Height); // 如果年龄相同，则按照身高进行降序排序
	}else{
		return p1.m_Age < p2.m_Age;			// 按照升序进行排序 
	} 
} 

void test01(){
	
	list<Person> lst;
	
	lst.push_back(Person("孙悟空", 189, 500));
	lst.push_back(Person("猪八戒", 187, 200));
	lst.push_back(Person("唐僧", 185, 300));
	lst.push_back(Person("米勒佛", 190, 500));
	lst.push_back(Person("白骨精", 178, 150));
	lst.push_back(Person("嫦娥", 169, 500));
	
	lst.push_back(Person("关羽", 169, 32));
	lst.push_back(Person("张飞", 175, 32));
	lst.push_back(Person("刘备", 180, 32));
	
	
	//排序前，链表中的内容为：
	cout << "排序前：" << endl;
	printList(lst); 
	
	// 对该链表进行排序，按年龄升序;若果年龄相同，则按照身高进行降序排序 
	cout << "-------------------------------------------" << endl; 
	cout << "排序后（按照年龄升序，如果年龄相同则按照身高进行降序排序！！）：" << endl;
	lst.sort(PersonCompare); 	// 通过函数或仿函数设定排序规则 
	printList(lst); 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
