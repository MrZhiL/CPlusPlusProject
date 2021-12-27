#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//������ģ���г�Ա���� ����ʵ��

template<class T1, class T2>
class Person{
	public:
		// �������캯���ͳ�Ա������������ʵ�� 
		Person(T1 name, T2 age);
		void showPerson();
		
	public:
		T1 m_Name;
		T2 m_Age;
};

// ��ģ���еĹ��캯������ʵ��
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
	this->m_Name = name;
	this->m_Age = age;
} 

// ��ģ��ĳ�Ա��������ʵ��
template<class T1, class T2>
void Person<T1,T2>::showPerson(){
	cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
} 

void test01(){
	
	Person<string, int> p1("Jack", 21);
	p1.showPerson();
	
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0; 
}
