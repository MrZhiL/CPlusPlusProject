#include <iostream>
#include <string>

using namespace std;

// �̳�ʵ��ҳ��
// �̳е��ŵ㣺�����ظ�����
// �﷨��class ���� : �̳з�ʽ ����
// ���� Ҳ��Ϊ �����ࣻ���� Ҳ��Ϊ ���� 

// ����ҳ�� �����ࣩ 
class BasicPage{
	
	public:
		// ͷ������ 
		void header(){
			cout << "��ҳ�������Ρ���¼��ע��" << endl; 
		}	
		// �ײ�����
		void footer(){
			cout << "�������ӡ��ͷ�����ַ������Э��" << endl; 
		} 
		// �������
		void left(){
			cout << "java��Python��C++��WebPage" << endl; 
		}
		
	private:
		void priTest(){
			cout << "This is a private function!" << endl; 
		} 
}; 

//  ���� 1��java 
class Java : public BasicPage{
	public:
		// �����а��������� 
		void content(){
			cout << "This is a Java Web!" << endl;
		} 
};

//  ���� 2��Python
class Python : public BasicPage{
	public:
		// �����а��������� 
		void content(){
			cout << "This is a Python Web!" << endl;
		} 
};

//  ���� 3��C++
class CPP : public BasicPage{
	public:
		// �����а��������� 
		void content(){
			cout << "This is a CPP Web!" << endl;
		} 
};

void test01(){
	
	cout << "* * * * * * *  * * * * * * * * * *" << endl; 
	
	Java ja;
	ja.header();
	ja.left();
	ja.content();
	ja.footer();
//	ja.priTest();
	
	cout << "* * * * * * *  * * * * * * * * * *" << endl; 
	
	Python py;
	py.header();
	py.left();
	py.content();
	py.footer();
	
	cout << "* * * * * * *  * * * * * * * * * *" << endl; 
	
	CPP cpp;
	cpp.header();
	cpp.left();
	cpp.content();
	cpp.footer();

}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
