#include <iostream>
#include <cmath>

using namespace std;

// �������������
// ���ã�ͨ�������������ʵ���Լ�����������
// ǰ��������������ã��������������ֵ 

class myInteger{
	
	friend ostream & operator<< (ostream &cout, myInteger myint);
//	friend void operator++ (myInteger &myint, int );
	
	public:
		myInteger(){
			m_Num = 0; 
		}
		// ��ȡm_Num��ֵ 
		int getNum(){
			return m_Num;
		}
		
		// ����ǰ��++ �����
		// ����������Ϊ��һֱ��һ�����ݽ��е������� 
		myInteger& operator++ (){
			++m_Num;
			return *this;
		}
		// ���غ���++ ����� :::���õ���һ��Ҫ����ֵ��ǰ�õ���Ҫ�������� 
		// operator++ (int ):int����ռλ������������������ǰ�úͺ��õ��� 
		myInteger operator++ (int){
			
			// �ȣ���¼��ǰ��ֵ��Ȼ���ñ����ֵ��1�����Ƿ�����ǰ��ֵ���Ӷ�ʵ���ȷ��غ�++ 
			myInteger temp = *this; 
			// �󣺵��� 
			this->m_Num++;
			// ���:����¼��������� 
			return temp;
		}
		
	private:
		int m_Num;
};

// ���������������& operator����Ϊ���õ�ostream�࣬������ֱ�Ӵ��� 
ostream & operator<< (ostream &cout, myInteger myint){
	cout << "myint.m_num = " << myint.m_Num;
	return cout;
} 

/** 
// ���غ���++����� 
void operator++ (myInteger &myint, int ){
	myint.m_Num++;
//	cout << myint.m_Num;
//	return cout;
} */ 

void test01(){
	myInteger myint;
	cout << myint << endl; 
	
	cout << "ǰ�õ�����" << ++(++myint) << endl;
	cout << myint << endl; 
	
	cout << "���õ�����" << (myint++)++ << endl; 
	cout << myint << endl; 
}

void test02(){
	myInteger myint;
	cout << myint << endl; 
	
	cout << "���õ�����" << (myint++)++ << endl; 
	cout << myint << endl; 
}

int main(){
	
	test02();

	system("pause");
	return 0;
}
