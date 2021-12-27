#include <iostream>
#include <string> 
#include <typeinfo>
using namespace std;

// ��ģ���������������
// 1��ֱ�Ӵ���ָ����������
// 2��������ģ�廯 
// 3�������������ģ�廯 

// �ܽ᣺�ڹ����У���õķ����Ƿ�һ��ֱ�Ӵ���ָ���������ͣ��÷�ʽ�򵥣�����ٽ���������ģ�廯�����ý�Ϊ���ӣ� 

template<class T1, class T2>
class Person{
	
	public:
		
		Person(T1 name, T2 age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		void showPerson(){
			cout << "name: " << this->m_Name << "  age: " << this->m_Age << endl; 
		}
				
		string m_Name;
		int m_Age;
	
}; 

// 1��ֱ��ָ���������
void showPerson01(Person<string, int> &p){
	p.showPerson();
}

// 2�������ģ�廯
template<class T1, class T2>
void showPerson02(Person<T1, T2> &p){
	p.showPerson();
	cout << "T1����������Ϊ: " << typeid(T1).name() << endl;
	cout << "T2����������Ϊ��" << typeid(T2).name() << endl; 
} 

// 3����������ģ�廯
template<class T>
void showPerson03(T &p){
	p.showPerson();
	cout << "T����������Ϊ: " << typeid(T).name() << endl;
} 

void test01(){
	
	// 1������ �������������� 
	Person<string, int> p("�����", 999);
	showPerson01(p);
	
	// 2������ �����ģ�廯���� 
	Person<string, int> p2("��˽�", 998); 
	showPerson02(p2);
	
	// 3������ ������ģ�廯
	Person<string, int> p3("��ɮ", 100); 
	showPerson03(p3); 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
