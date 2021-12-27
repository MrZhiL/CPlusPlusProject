#include <iostream>
#include <string>

using namespace std;

// ʹ��ȫ�ֺ�����ӡ��ģ���е���Ϣ 

/**
// ��ģ�����Ԫ��������ģ�������Ԫ����������ʵ�ֺ�����ʵ�� 
// ȫ�ֺ�������ʵ�֣�ֱ��������������Ԫ���ɣ�����ȫ�ֺ���������ʵ�֣�ʵ�ּ��ұ���������ֱ��ʶ�� 
// ȫ�ֺ�������ʵ�֣���Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
*/



template<class T1, class T2> class Person;
// ʹ��ȫ�ֺ���������ʵ�֣�ʱ����Ҫ��ǰ���߱������ú����Ĵ��� 
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p); 

template<class T1, class T2>
class Person{
	
	// ȫ�ֺ�������ʵ�֣�Person������Ҫ��<T1,T2>������ΪPerson��Ϊ��ģ�� 
	friend void printPerson(Person<T1, T2> &p){
		cout << "Name: " << p.m_Name << ", Age: " << p.m_Age << endl;
	} 
	
	// ȫ�ֺ�����������������ʵ�֣�����Ҫ��ǰ���߱�������ʵ�� 
	// friend void printPerson2(Person<T1, T2> &p); ��ʱ�ú���Ϊ��ͨ��ȫ�ֺ���
	//������������printPerson����Ϊģ�庯���������Ҫ���ú�����ʾΪģ�庯��
	// ֻ��Ҫ�ں����������ģ������<>���� 
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
	// 1��ͨ��ȫ�ֺ���������ʵ�֣���ӡ��Ϣ 
	printPerson(p); // printPerson(Person &p)Ϊȫ�ֺ������������ڳ�Ա��������˿���ֱ�ӵ��� 
	
	// 2��ͨ��ȫ�ֺ���������ʵ�֣���ӡ��Ϣ 
	Person<string, int> p2("Mejg", 21);
	printPerson2(p2);
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
