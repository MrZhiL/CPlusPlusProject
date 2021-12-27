#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/* C++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ �����Ա
 * �ܽ᣺�������������Ϊ�����Աʱ������ʱ�ȹ���������ٹ�������
 *       ������˳���빹���෴ 
 ****************************************************************** 
 * ���磺 
 * class A{}
 * class B{
 *     A a;
 * }
 * B �����ж���A��Ϊ��Ա��AΪ�����Ա
 * ��ô������B����ʱ��A��B�Ĺ��������������˳��˭��˭�󣿣� 
 */
 
 
class Phone{
	
	public:
		// ��ʼ�����ԺͲ��� 
		Phone(string name): m_PName(name){ 
			cout << "Phone�ĳ�ʼ������" << endl; 
		}
		~Phone(){
			cout << "Phone����������" << endl; 
		}
		
		// �ֻ�Ʒ������ 
		string m_PName;
		// �ֻ��ţ�
		string m_Num; 
}; 

class Person{
	
	public:
		// Phone m_Phone = phone  ��ʽת���� 
		Person(string name, string phone): m_Name(name), m_Phone(phone){
			cout << "Person�ĳ�ʼ������" << endl; 
		} 
		
		~Person(){
			cout << "Person����������" << endl; 
		} 
		
		// ������
		string m_Name;
		// �ֻ�
		Phone m_Phone; 
}; 

void test01(){
	
	Person p("����", "iPhone");
	
	cout << p.m_Name << "���ֻ�Ϊ�� " << p.m_Phone.m_PName << endl;
	cout << p.m_Name << "���ֻ���Ϊ�� " << p.m_Phone.m_Num << endl;  
}

int main(){
	
	test01();
	
	return 0;
}
