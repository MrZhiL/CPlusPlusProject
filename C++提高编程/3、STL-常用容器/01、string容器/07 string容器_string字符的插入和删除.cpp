#include <iostream>
#include <string>

using namespace std;

// string�ַ��Ĳ����ɾ��
/**			
	����ԭ�ͣ�string& insert(int pos, const string& str); 	// �����ַ���str
	 		  string& insert(int pos, const char* s); 		// �����ַ���s
	 		  string& insert(int pos, int n, char c);       // ��ָ��λ�ò���n���ַ�c
			  string& erase(int pos, int n = npos);			// ɾ����pos��ʼ��n���ַ� 
*/ 

void test01(){
	
	string str = "HelloWorld!";
	cout << "����ǰ:str = " << str << endl;
	
	// string�ַ��Ĳ���
	str.insert(0,"Welcome! ");
	cout << "�����:str = " << str << endl;
	
	// ��ָ��λ�ò���n���ַ�c
	str.insert(10,5,'e');
	cout << "��ָ��λ�ò���5��e��str = " << str << endl; 
	
	// ɾ����pos��ʼ��n���ַ�
	str.erase(10,5);
	cout << "ɾ����10��ʼ��5���ַ���str = " << str << endl; 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
