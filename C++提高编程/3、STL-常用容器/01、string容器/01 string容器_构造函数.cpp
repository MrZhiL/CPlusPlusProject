#include <iostream>
#include <string>
using namespace std;

// string�Ĺ��캯��
// 1��string s; // �������ַ��� 
// 2��string(const char* s); // ʹ���ַ���s��ʼ��  
// 3��string(const string &s); // ʹ��string�еĿ���������ֵ 
// 4��string(int n, char c);    // ʹ��n���ַ�c��ʼ�� 


void test01(){
	
	// 1��string s
	string s1("hello2");
	
	// 2��ʹ���ַ���c��ʼ�� 
	const char *c = "HelloWorld!";
	string s2(c);
	
	// 3��ʹ�ÿ���������ֵ 
	string s3(s1);	
	
	// 4��ʹ��n���ַ�c��ʼ��
	string s4(10, 'e');
	
	cout << "s1: " << s1 << endl; 
	cout << "s2: " << s2 << endl; 
	cout << "s3: " << s3 << endl; 
	cout << "s4: " << s4 << endl; 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
 
