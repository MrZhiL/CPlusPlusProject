#include <iostream>
#include <string>

using namespace std;

// 使用全局函数打印类模板中的信息 

/**
// 类模板和友元：掌握类模板配合友元函数的类内实现和类外实现 
// 全局函数类内实现：直接在类内声明友元即可（建议全局函数做类内实现，实现简单且编译器可以直接识别） 
// 全局函数类外实现：需要提前让编译器知道全局函数的存在
*/



template<class T1, class T2> class Person;
// 使用全局函数（类外实现）时，需要提前告诉编译器该函数的存在 
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p); 

template<class T1, class T2>
class Person{
	
	// 全局函数类内实现，Person后面需要加<T1,T2>，是因为Person类为类模板 
	friend void printPerson(Person<T1, T2> &p){
		cout << "Name: " << p.m_Name << ", Age: " << p.m_Age << endl;
	} 
	
	// 全局函数声明（需在类外实现）：需要提前告诉编译器的实现 
	// friend void printPerson2(Person<T1, T2> &p); 此时该函数为普通的全局函数
	//而下面声明的printPerson函数为模板函数，因此需要将该函数表示为模板函数
	// 只需要在函数后面加上模板声明<>即可 
	friend void printPerson2<>(Person<T1, T2> &p); 
	
	public:
		
		Person(T1 name, T2 age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
	private:
		T1 m_Name;
		T2 m_Age;
}; 

template<class T1, class T2>
void printPerson2(Person<T1, T2> &p){
	cout << "Name: " << p.m_Name << ", Age: " << p.m_Age << endl;
} 

void test01(){
	Person<string, int> p("jack",20);
	// 1、通过全局函数（类内实现）打印信息 
	printPerson(p); // printPerson(Person &p)为全局函数，不是类内成员函数，因此可以直接调用 
	
	// 2、通过全局函数（类外实现）打印信息 
	Person<string, int> p2("Mejg", 21);
	printPerson2(p2);
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
