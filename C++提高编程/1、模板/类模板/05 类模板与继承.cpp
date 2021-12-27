#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// 类模板与继承：
// 当类模板 使用 继承时，需要注意以下几点：
// 1、当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
// 2、如果不指定，编译器无法给子类分配内存
// 3、如果想灵活指定父类中T的类型，子类也需变为类模板

template<class T1, class T2>
class Base{
	public:
		T1 m_Name;
		T2 m_Age;
}; 

// 子类继承的父类是一个类模板时：
//class Son1 :: public Base{ // 错误，当子类继承的父类为类模板时，子类必须声明父类的数据类型,如果不指定，则无法分配内存 
class Son1:public Base<string, int>{
	public:
		Son1(){
			cout << "Son1的数据类型为：" << typeid(Son1).name() << endl;
			cout << "Base的数据类型为：" << typeid(Base).name() << endl; 
		} 
		int m_Num; 
}; 

// 子类 如果想要 灵活指定父类中的T，则需要进行模板化
template<class T1, class T2, class T3>
class Son2:public Base<T2, T3>{
	public:
		Son2(){
			cout << "Son2的数据类型为：" << typeid(Son2).name() << endl;
			cout << "T1的数据类型为：" << typeid(T1).name() << endl; 
			cout << "T2的数据类型为：" << typeid(T2).name() << endl; 
			cout << "T3的数据类型为：" << typeid(T3).name() << endl; 
		}
}; 

void test01(){
	
	Son1 s1;
	Son2<int, string, char> s2;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
