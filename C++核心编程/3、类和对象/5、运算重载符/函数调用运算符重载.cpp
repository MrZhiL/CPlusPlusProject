#include <iostream>
#include <string>
 
using namespace std;

// �������������()Ҳ��������
// �������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
// �º���û�й̶�д�����ǳ����

// ������ӡ�� 
class MyPrint{
	
	// ���غ������������() 
	public:
		void operator() (string str){
			cout << str << endl;
		}
};

// α�����ǳ���û�й̶�д���� 
// �����ӷ��� 
class MyAdd{
	
	public:
		int operator() (int num1, int num2){
			return num1+num2;
		}
		
}; 

void test01(){
	
	MyPrint mp;
	mp("HelloWorld!"); // ���������ǳ���������˳�Ϊα���� 
}

void test02(){
	
	// ������������
	cout << MyAdd() (10,20) << endl;
}

int main(){
	
	test01();
	test02();
	
	system("pause");
	return 0;
}
