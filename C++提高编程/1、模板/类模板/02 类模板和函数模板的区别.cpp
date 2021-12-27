#include <iostream>
#include <string>
using namespace std; 

// ��ģ��ͺ���ģ�������
// 1����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
// 2����ģ����ģ������б��п�����Ĭ�ϲ��� 

template<class NameType, class AgeType = int>
class Person{
	
	public:
		Person(NameType name, AgeType age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		void showPerson(){
			cout << "name��" << this->m_Name << "  age��" << this->m_Age << endl;			
		}
		
		NameType m_Name;
		AgeType m_Age;
	
};

void test01(){
	
	// 1����ģ����û���Զ������Ƶ�
	//Person p1("�����",999); 	// ���� 
	Person<string, int> p2("�����",999); // ��ȷ����ģ��ֻ��ʹ��ָ������
	p2.showPerson(); 
	
	// 2����ģ���еĲ����б����ָ��Ĭ�ϲ���
	Person<string> p3("��˽�",998);
	p3.showPerson();
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
