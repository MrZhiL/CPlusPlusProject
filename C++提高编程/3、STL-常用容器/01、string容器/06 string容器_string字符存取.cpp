// string�ַ��Ĵ�ȡ 
//string�е����ַ���ȡ��ʽ�����֣�char& operator[](int n); // ͨ��[]��ʽȡ�ַ� 
//								  char& at(int n); 		   // ͨ��at��ʽ��ȡ�ַ�

#include <iostream>
#include <string>

using namespace std;

void test01(){
	
	string str = "HelloWorld!";
	
	char s[100];
	
	cout << "sizeof(str) = " << sizeof(str) << endl;
	cout << "sizeof(char *s) = " << sizeof(s) << endl;
	
	// 1��ͨ��[]��ȡ�ַ� 
	cout << "1��ͨ��[]��ȡ�ַ�: " ; 
	for(int i=0; i<str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;
	
	// 2��ͨ��at��ʽ��ȡ�ַ�
	cout << "2��ͨ��at��ȡ�ַ�: " ; 
	for(int i=0;i<str.size();i++){
		s[i] = str.at(i);
		cout << s[i] << " ";
	}
	cout << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
} 
