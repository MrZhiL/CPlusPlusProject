#include <iostream>

using namespace std;

// �������������
// ��������Զ����������� 

class Person{
	public:
		
		// ���ó�Ա�������� ���������
		// p.operator << (cout) �ļ򻯰汾Ϊ��p << cout��
		// ͨ���������ó�Ա��������<< ���������Ϊ�޷�ʵ��cout�����
	/**
		ostream & operator<< (ostream &cout){
			cout << "m_A = " << this->m_A << " ,m_B = " << this->m_B;
			return cout;
		} */
		
		void leftMove(int a){
			this->m_A = a;
			this->m_B = 10;
			this->m_A  = this->m_A << 2;
			this->m_A << 1;
		}
		
		int m_A;
		int m_B;
};

// ֻ������ȫ�ֺ���������������� 
// operator<< (ostream &cout, Person &p)����Ϊ��(��) cout << p 
// cout ���Ի��ɱ�����֣�out�������� 
ostream & operator<< (ostream &cout, Person &p){
	cout << "m_A = " << p.m_A << " ,m_B = " << p.m_B;
	return cout;
}

void test01(){
	Person p;
	p.leftMove(1);
//	p.m_A = 1;
	cout << p << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
