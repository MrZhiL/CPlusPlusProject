#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/* C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
 * 总结：当其他类对象作为本类成员时，构造时先构造类对象，再构造自身
 *       析构的顺序与构造相反 
 ****************************************************************** 
 * 例如： 
 * class A{}
 * class B{
 *     A a;
 * }
 * B 类中有对象A作为成员，A为对象成员
 * 那么当创建B对象时，A与B的构造和析构函数的顺序谁先谁后？？ 
 */
 
 
class Phone{
	
	public:
		// 初始化属性和参数 
		Phone(string name): m_PName(name){ 
			cout << "Phone的初始化构造" << endl; 
		}
		~Phone(){
			cout << "Phone的析构函数" << endl; 
		}
		
		// 手机品牌名字 
		string m_PName;
		// 手机号：
		string m_Num; 
}; 

class Person{
	
	public:
		// Phone m_Phone = phone  隐式转换法 
		Person(string name, string phone): m_Name(name), m_Phone(phone){
			cout << "Person的初始化构造" << endl; 
		} 
		
		~Person(){
			cout << "Person的析构函数" << endl; 
		} 
		
		// 姓名：
		string m_Name;
		// 手机
		Phone m_Phone; 
}; 

void test01(){
	
	Person p("张三", "iPhone");
	
	cout << p.m_Name << "的手机为： " << p.m_Phone.m_PName << endl;
	cout << p.m_Name << "的手机号为： " << p.m_Phone.m_Num << endl;  
}

int main(){
	
	test01();
	
	return 0;
}
