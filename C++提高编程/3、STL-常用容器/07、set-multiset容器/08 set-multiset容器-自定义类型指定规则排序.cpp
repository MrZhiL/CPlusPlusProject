#include<iostream>
#include<set>
#include<string>

using namespace std;

// �Զ����������͵�����
// �Զ����������ͽ�������ʱ������Ҫ����ָ���������
 
class Person{
	
	public:
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		string m_Name;
		int m_Age;
	
}; 

// �����º������ı��������
class MyCompare{
	
	public:
		// ������Ҫʹ��const�����������ͣ�����ᱨ�� 
		bool operator() (const Person &p1, const Person &p2){
			// ʹ�����е�Ԫ�ذ�����Ӵ�С�ķ�ʽ���� 
			return p1.m_Age > p2.m_Age;	
		}
};

void test01(){
	
	set<Person> st;
//	// set��������Ԫ��ʱ�������Ĭ������
//	// set����ʹ��insert����Ԫ�غ���Ѿ����򣬲��ɸ���
//	// ��ˣ������Ҫ�ı������������Ҫ�ڲ���֮ǰ�͸ı�������� 
//	st.insert(Person("����", 32));	// ֱ�Ӷ��Զ����������Ͳ��룬�ᱨ����Ϊ�������޷����Զ����������ͽ������� 
//	st.insert(Person("�ŷ�", 31));	// ��������Ҫ���Զ�����������������Ҫ����������� 
//	st.insert(Person("����", 35));
//	st.insert(Person("�ܲ�", 38));
//	st.insert(Person("��Ȩ", 32));
	
	// �����Զ��������࣬���дӴ�С������ 
	set<Person, MyCompare> st2;
	// ͨ���º����ı�������������� 
	st2.insert(Person("����", 32));
	st2.insert(Person("�ŷ�", 31));
	st2.insert(Person("����", 35));
	st2.insert(Person("�ܲ�", 38));
	st2.insert(Person("��Ȩ", 30));
	// ����
	cout << "ͨ���º����ı�������򣨴Ӵ�С����" << endl;; 
	
	for(set<Person, MyCompare>::iterator it = st2.begin(); it != st2.end(); it++){
		cout << "������ " << it->m_Name << ", ����: " << it->m_Age << endl;
	}
	cout << endl;
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0;
} 
