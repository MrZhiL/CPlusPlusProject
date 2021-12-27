#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// vector�����д���Զ����������� 

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
	
	v.push_back(Person("�����",500));
	v.push_back(Person("��˽�",800));
	v.push_back(Person("�׹Ǿ�",777));
	v.push_back(Person("ɳ����",400));
	v.push_back(Person("������",300));
	
	// ��һ��ʹ�õ��������������е�����
	cout << "��һ��ʹ�õ��������������е����ݣ�" << endl; 
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
		//cout << "name: " << it->m_Name << ", age: " << it->m_Age << endl;  // ֱ����ָ�������ú���������� 
		cout << "name: " << (*it).m_Name << ", age: " << (*it).m_Age << endl; // (*it)��ʾPerson�������ͣ���ʱ����(*it).m_Age����*it.m_Age���� 
	}
	
	// ������ʹ�ñ�׼�㷨��������
	cout << "������ʹ��algorithm�е��㷨����������" << endl; 
	for_each(v.begin(), v.end(), printPerson);
	
}

void printPerson2(const Person *p){
	cout << "name: " << p->m_Name << ", age: " << p->m_Age << endl; 
}

// ����Զ����������͵�ָ��
void test02(){
	
	vector<Person*> v;
	
	Person *p1 = new Person("�����",500);
	Person *p2 = new Person("��˽�",800);
	Person *p3 = new Person("�׹Ǿ�",777);
	Person *p4 = new Person("ɳ����",400);
	Person *p5 = new Person("������",300);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	// ��һ��ʹ�õ��������������е�����
	cout << "��һ��ʹ�õ��������������е����ݣ�" << endl; 
	for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
		//cout << "name: " << it->m_Name << ", age: " << it->m_Age << endl;  // ֱ����ָ�������ú���������� 
		cout << "name: " << (*it)->m_Name << ", age: " << (*it)->m_Age << endl; // (*it)��ʾPerson�������ͣ���ʱ����(*it).m_Age����*it.m_Age���� 
	}
	
	// ������ʹ�ñ�׼�㷨��������
	cout << "������ʹ��algorithm�е��㷨����������" << endl; 
	for_each(v.begin(), v.end(), printPerson2);
	
} 

int main(){

	//test01();
	test02();
	
	system("pause");
	return 0;
} 

