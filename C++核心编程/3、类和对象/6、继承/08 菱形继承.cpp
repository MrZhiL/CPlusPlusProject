#include <iostream>

using namespace std;

// ���μ̳�
// ���μ̳еĸ������������̳�ͬһ������
//				 ������ĳ����ͬʱ�̳�������������
//				 �����ּ̳б���Ϊ���μ̳У�������ʯ�̳� 

// ���������ʹ������̳м��ɣ��ؼ��֣�virtual�� 
// ��ʱ�������Ϊ��̳У�Animal���Ϊ ����ࡢ
// ��̳л����� .vbptr��Virtual base pointer�������ָ�룬��ָ��ָ��������еĳ�Ա����
// �������ָ�루vbptr�����ж�Ӧ��vbtable��virtual base table��������� ����������д���������м̳и��������ƫ�Ƶ�ַ��С 

// ������ 
class Animal{
	public:
		int m_Age;
}; 

// ����
class Sheep : virtual public Animal{ };

// ����
class Camel : virtual public Animal{ };

// ������
class Alpaca : public Sheep, public Camel{
	
}; 


void test01(){
	
	Alpaca al;
	
	cout << "�̳к���ռ�ڴ��СΪ��sizeof(Alpaca) = " << sizeof(Alpaca) << endl;
	cout << "����̳к���ռ�ڴ��СΪ��sizeof(Sheep) = " << sizeof(Sheep) << endl;
	cout << "����̳к���ռ�ڴ��СΪ��sizeof(Camel) = " << sizeof(Camel) << endl;
	cout << "sizeof(Animal) =" << sizeof(Animal) << endl; 
	// ��Ϊ������̳������������࣬���Դ�������m_Age����ʱ����ֶ�����
	// �����μ̳�ʱ����������ӵ����ͬ�ĳ�Ա��������Ҫ���������������� 
	// ��ʱ�������ظ��ᵼ����Դ�˷� 
	//al.m_Age = 10;
	al.Sheep::m_Age = 10; 
	al.Camel::m_Age = 8;
	
	cout << "Alpace::Sheep::m_Age = " << al.Sheep::m_Age << endl;
	cout << "Alpace::Camel::m_Age = " << al.Camel::m_Age << endl;
	
	al.m_Age = 5;
	cout << "���յ�����Ϊ��" << al.m_Age << endl; 
	
}

int main(){
	
	test01();	
	
	system("pause");
	return 0;
	
}
