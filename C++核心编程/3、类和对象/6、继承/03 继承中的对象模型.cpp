#include <iostream>

using namespace std;

// �̳��еĶ���ģ��
// ���⣺�Ӹ���̳й����ĳ�Ա����Щ������������� 

class Base{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;
}; 

// ��Visio Stdio�п������ÿ�������������ʾ���߲鿴����ģ��
// 1����ת�̷�
// 2����ת�ļ�·�� cd ����·��
// 3���鿴����
// 4��cl /d1 reportSingleClassLayout+���� �ļ��� 

class Son1 : public Base{
	public:
		int m_D;
};

void test01(){
	
	// ���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	// �����е�˽�г�Ա���ԣ��Ǳ������������ˣ���˷��ʲ���������ȷʵ�Ǳ��̳��� 
	Son1 s1;
	
	cout << "sizeof(s1) = " << sizeof(s1) << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
