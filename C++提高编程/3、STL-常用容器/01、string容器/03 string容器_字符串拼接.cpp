#include<iostream>
#include<string>

using namespace std;

// �ַ���ƴ��
/**
	string& operator+=(const char* s);			//����+=�����
	string& operator+=(const string &str);		//����+=�����
	string& operator+=(char c);					//����+=�����
	string& append(const string *str);			//���ַ���str���ӵ���ǰ�ַ�����ĩβ
	string& append(const char* s, int n);		//���ַ�����ǰn���ַ����ӵ���ǰ�ַ�����ĩβ
	string& append(const string &s);			//���ַ���s���ӵ���ǰ�ַ�����ĩβ
	string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ���ĩβ
*/ 

void test01(){
	
	string str1 = "����"; 
	string *str2 = new string();
	*str2 = "��ţ�ɺ�֯Ů��������";
	
	cout << "str1: " << str1 << endl; 
	
	str1 += "����Ϧ��"; 
	cout << "str1: " << str1 << endl; 
	
	str1 += *str2;
	cout << "str1: " << str1 << endl; 
	
	str1 += '!';
	cout << "str1: " << str1 << endl;
	
	string str3 = "����";
	str3.append("��2020-08-26: "); 
	cout << "str3: " << str3 << endl; 
	
	str3.append(*str2);
	cout << "str3: " << str3 << endl;
	
	str3.append("Hello��֯Ů�ǣ�", 13,2);
	cout << "str3: " << str3 << endl;
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
} 
