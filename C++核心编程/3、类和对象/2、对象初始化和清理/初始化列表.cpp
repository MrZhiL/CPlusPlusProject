#include <iostream>
#include <cstdlib>

using namespace std;

	/* 初始化列表 
	 * C++中提供了初始化列表语法，用来初始化属性 
	 * 语法：构造函数(): 属性1(值1), 属性2(值2), ..... {}
	 * 
	 */ 

class Person{
	
	public:
		
		// 初始化列表，初始化属性 
		Person(int age, float length, float weight): m_age(age), m_length(length), m_weight(weight){
			cout << "Person初始化属性构造函数" << endl;
		}
/**		
		Person(int age, float length, float weight){
			m_age = age;
			m_length = length;	
			m_length = weight;
			cout << "Person有参构造函数" << endl;
		}
*/		
		Person(const Person &p){
			m_age = p.m_age;
			m_length = p.m_length;
			m_weight = p.m_weight;
			cout << "Person拷贝构造函数" << endl;
		}
		
		~Person(){
			cout <<   "Person析构函数" << endl;
		}
		
		int m_age;		// 年龄 
		float m_length;	// 身高 
		float m_weight;	// 体重 
};


int main(){
	
	Person p(10,150,40);
	
//	p.m_age = 20;
	
	cout << "p.age = " << p.m_age << endl;
	cout << "p.length = " << p.m_length << endl;
	cout << "p.weigth = " << p.m_weight << endl;
		
	return 0;
}
