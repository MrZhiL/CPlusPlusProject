#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person{
	public:
		
//		Person(char (&name)[], int age){
//			m_Name = name;
//			m_Age = age;
//		}
//		
		char m_Name[64];
		int m_Age;
};

void test01(){
	
	Person p = {"Jack",21};
	
//	p.m_Name = "HelloWorld!";
	
	// �������ļ� 
	ofstream ofs("Person.txt", ios::out | ios::binary);
	
	// ��������
	ofs.write( (const char *)&p, sizeof(p));
	
	
	// �ر��ļ� 
	ofs.close(); 
	
	ifstream ifs("Person.txt",ios::in|ios::binary);
	
	if(!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return ;
	}
	
	Person p1;
	ifs.read((char *)&p1,sizeof(Person));
	
	cout << p1.m_Name << endl;
	cout << p1.m_Age << endl;
	
	ifs.close();
		
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 

