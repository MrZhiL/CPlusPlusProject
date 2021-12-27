#include<iostream>
#include<set>
#include<string>

using namespace std;

// 自定义数据类型的排序
// 自定义数据类型进行排序时，都需要给定指定排序规则
 
class Person{
	
	public:
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		string m_Name;
		int m_Age;
	
}; 

// 创建仿函数，改变排序规则
class MyCompare{
	
	public:
		// 这里需要使用const修饰数据类型，否则会报错 
		bool operator() (const Person &p1, const Person &p2){
			// 使容器中的元素按年龄从大到小的方式排序 
			return p1.m_Age > p2.m_Age;	
		}
};

void test01(){
	
	set<Person> st;
//	// set容器插入元素时，会进行默认排序
//	// set容器使用insert插入元素后就已经排序，不可更改
//	// 因此，如果想要改变排序规则，则需要在插入之前就改变排序规则 
//	st.insert(Person("关羽", 32));	// 直接对自定义数据类型插入，会报错，因为编译器无法对自定义数据类型进行排序。 
//	st.insert(Person("张飞", 31));	// 因此如果想要对自定义数据类型排序，需要给定排序规则 
//	st.insert(Person("刘备", 35));
//	st.insert(Person("曹操", 38));
//	st.insert(Person("孙权", 32));
	
	// 创建自定义数据类，进行从大到小的排序 
	set<Person, MyCompare> st2;
	// 通过仿函数改变容器的排序规则 
	st2.insert(Person("关羽", 32));
	st2.insert(Person("张飞", 31));
	st2.insert(Person("刘备", 35));
	st2.insert(Person("曹操", 38));
	st2.insert(Person("孙权", 30));
	// 遍历
	cout << "通过仿函数改变排序规则（从大到小）：" << endl;; 
	
	for(set<Person, MyCompare>::iterator it = st2.begin(); it != st2.end(); it++){
		cout << "姓名： " << it->m_Name << ", 年龄: " << it->m_Age << endl;
	}
	cout << endl;
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0;
} 
