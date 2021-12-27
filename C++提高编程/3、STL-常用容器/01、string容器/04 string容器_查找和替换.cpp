#include <iostream>
#include <string>

using namespace std;

// string�����еĲ��Һ��滻 

/**
 	int find(const string& str, int pos=0) cosnt ;			//����str��һ�γ���λ�ã���pos��ʼ����
	int find(const char *s, int pos=0) const;				//����s��һ�γ���λ�ã���pos��ʼ����
	int find(const char *s, int pos, int n) cosnt;			//��posλ�ò���s��ǰn���ַ���һ��λ��
	int find(const char c, int pos=0) const;				//�����ַ�c��һ�γ��ֵ�λ��
	int rfind(const string &str, int pos=npos) const;		//����str���һ��λ�ã���pos��ʼ����
	int rfind(const char *s, int pos=npos) cosnt;			//����s���һ�γ���λ�ã���pos��ʼ����
	int rfind(const char *s, int pos ,int n) const;			//��pos����s��ǰn���ַ����һ��λ��
	int rfind(cosnt char c, int pos = 0) const;				//�����ַ�c���һ�γ���λ��
			
	string& replace(int pos, int n, const string& str);		//�滻��pos��ʼn���ַ�Ϊ�ַ���str
	string& replace(int pos, int n, const char *s);			//�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
		
 */

// string���� 
void test01(){
	
	string str1 = "HelloWorld!This is my project!";
	
	// find��ʾ�ַ���һ�γ��ֵ�λ�� 
	int pos = str1.find("This", 0);
	if (pos == -1){
		cout << "δ�ҵ����ַ�����" << endl; 
	}else{
		cout << "�ҵ����ַ��������ַ�����λ��Ϊ��pos = " << pos << endl;
	}
	
	// rfind��find������rfind�������Ҳ��ң�find����������ң������������Ҽ��㡣
	// rfind��ʾ�����ַ������һ��λ�� 
	pos = str1.rfind("my");
	
	if (pos == -1){
		cout << "δ�ҵ����ַ�����" << endl; 
	}else{
		cout << "�ҵ����ַ��������ַ�����λ��Ϊ��pos = " << pos << endl;
	}
	
	// int rfind(const char *s, int pos ,int n)����posλ�ÿ�ʼ�����ַ���s��ǰn���ַ����һ��λ�� 
	int locat1 = str1.rfind("my project", 1, 1); 
	
	cout << "my project��һ�γ��ֵ�λ��Ϊ��" << locat1 << endl;
	
	cout << "�����ֵ����һ��λ��Ϊ��" << str1.rfind('!',15) << endl; 
} 

// �滻
void test02(){
	
	//string& replace(int pos, int n, const string& str);		//�滻��pos��ʼn���ַ�Ϊ�ַ���str
	//string& replace(int pos, int n, const char *s);			//�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
	
	string str = "HelloWorld! This is My Project!";
	str += (char)5; 
	str = str.replace(0,10,"Welcome");
	
	cout << "�滻���str = " << str << endl; 
	
} 

int main(){
	
	test01();
//	test02();
	
	system("pause");
	
	return 0;
	
} 
