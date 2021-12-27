#include<iostream>
#include<list>
#include<string>

using namespace std;

// ����������Person�Զ����������ͽ�������Person����������������ߡ�����
// ������򣺰�����������������������ͬ������߽��н��� 

class Person{
	
	public:
		Person(){};
		Person(string name, float height, int age){
			this->m_Name = name;
			this->m_Height = height;
			this->m_Age = age;
		} 
		
		string m_Name;		//���� 
		int m_Height;		//��� 
		int m_Age;			//���� 
	
};

void printList(const list<Person> &lst){
	
	for(list<Person>::const_iterator it = lst.begin(); it != lst.end(); it++){
		cout << "������ " << it->m_Name << "\t��ߣ� " << it->m_Height << "\t���䣺 " << it->m_Age << endl; 
	}
	cout << endl;
}

// ͨ��������º��� �� ����������ָ������
bool PersonCompare(Person &p1, Person &p2){
	
	if(p1.m_Age == p2.m_Age){
		return (p1.m_Height > p2.m_Height); // ���������ͬ��������߽��н�������
	}else{
		return p1.m_Age < p2.m_Age;			// ��������������� 
	} 
} 

void test01(){
	
	list<Person> lst;
	
	lst.push_back(Person("�����", 189, 500));
	lst.push_back(Person("��˽�", 187, 200));
	lst.push_back(Person("��ɮ", 185, 300));
	lst.push_back(Person("���շ�", 190, 500));
	lst.push_back(Person("�׹Ǿ�", 178, 150));
	lst.push_back(Person("�϶�", 169, 500));
	
	lst.push_back(Person("����", 169, 32));
	lst.push_back(Person("�ŷ�", 175, 32));
	lst.push_back(Person("����", 180, 32));
	
	
	//����ǰ�������е�����Ϊ��
	cout << "����ǰ��" << endl;
	printList(lst); 
	
	// �Ը�����������򣬰���������;����������ͬ��������߽��н������� 
	cout << "-------------------------------------------" << endl; 
	cout << "����󣨰��������������������ͬ������߽��н������򣡣�����" << endl;
	lst.sort(PersonCompare); 	// ͨ��������º����趨������� 
	printList(lst); 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
