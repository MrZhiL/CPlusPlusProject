#include <iostream>
#include <cmath>

using namespace std;

// �Ӻ����������
// 1����Ա��������+��
// 2��ȫ�ֺ�������+�� 

class Person{
	public:
		
		void printAB(){
			cout << "m_A = " << m_A << "  "; 
			cout << "m_B = " << m_B << endl; 
		}
		
		// 1��ͨ����Ա����������+�� 
		Person operator+(Person &p){
			Person temp;
			temp.m_A = this->m_A + p.m_A;
			temp.m_B = this->m_B + p.m_B;
			return temp;
		}
		// �����ʹ�����أ�����Ҫÿ������һ���µĺ����� 
		Person PersonAddPerson(Person &p){
			Person temp;
			temp.m_A = this->m_A + p.m_A;
			temp.m_B = this->m_B + p.m_B;
			return temp;
		}
		
		int m_A;
		int m_B;
};

/** 
// 2��ȫ�ֺ���Ҳ��������
Person operator+(Person &p1, Person &p2){
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
} */

// ��������� Ҳ���Է�����������
Person operator+(Person &p1, int num){
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test01(){
	
	Person p1,p2;
	
	p1.m_A = 10;
	p1.m_B = 20;
	
	p2.m_A = 11;
	p2.m_B = 22;
	
	// ��Ա�������ʵ���
	//Person p3 = p1.PersonAddPerson(p2);
	// ȫ�ֺ����ı��ʵ���
	
	// ��������� Ҳ���Է�����������
	Person p3 = p1 + 10;
	cout << "p3: " ;
	p3.printAB();
	
/**
	//Person p3 = operator+(p1,p2);
	// ����ǳ�Ա����������Person p4 = p1.operator+(p2)���Լ�Ϊ��Person p4 = p1 + p2;  
	// �����ȫ�ֺ���������Person p4 = operator+(p1,p2)���Լ�Ϊ��Person p4 = p1 + p2;
*/	 
	Person p4 = p1 + p2; 
	cout << "p4: " ;
	p4.printAB();
}

int main(){
	
	int aa = 11;
	int bb = 22;
	int cc = aa + bb;
	cout << "c= " << cc << endl; 
	test01();
	
	system("pause");
	return 0;
} 

