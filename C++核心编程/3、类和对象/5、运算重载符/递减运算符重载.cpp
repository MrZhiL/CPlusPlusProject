#include <iostream>

using namespace std;

class MyInteger{
	
	// �������������<<
	friend ostream & operator<< (ostream &cout, MyInteger myInt);

	public:
		MyInteger(){
			m_Num = 0;
		}
		
		// ����ǰ����������� 
		MyInteger& operator--(){
			this->m_Num--;
			return *this;
		}
		// ���غ������������ 
		MyInteger operator--(int){
			
			MyInteger temp = *this; 
			this->m_Num--;
			return temp;
		}  
		
		
	private:
		int m_Num;
};

// ���������������& operator����Ϊ���õ�ostream�࣬������ֱ�Ӵ��� 
ostream & operator<< (ostream &cout, MyInteger myInt){
	cout << myInt.m_Num; 
	return cout;
}

void test01(){
	MyInteger myInt;
	cout << "0:m_Num = " << myInt << endl;
	cout << "1(ǰ��--):m_Num = " << --myInt << endl;
	cout << "2(����--):m_Num = " << myInt-- << endl;
	cout << "3:m_Num = " << myInt << endl;
}


int main(){
	test01();
	
	system("pause");
	return 0;
}
