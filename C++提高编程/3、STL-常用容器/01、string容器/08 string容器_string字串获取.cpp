#include<iostream>
#include<string>

using namespace std;

/**
	�������������ַ����ֻ�ȡ��Ҫ���ִ�
	����ԭ�ͣ�string substr(int pos=0, int n = npos) const; // ������pos��ʼ��n���ַ���ɵ��ַ��� 
 */ 

void test01(){
	
	string str = "HelloWorld! Tody is Tuesday and it is QiXi Festival!";
	
	string substr = str.substr(0,10);
	
	cout << substr << endl; 
	
}

// ʵ������ȡ�������Ч�û���
void test02(){
	
	string Email;
	cout << "Please input your Email Adderss: ";
	cin >> Email;
	
	int EmailLoac = Email.find('@');
	
	if (EmailLoac == -1){
		cout << "�����������!������xxxx@xx.xx��ʽ" << endl; 
	} else {
		string userName = Email.substr(0,EmailLoac);
		cout << "�û���Ϊ��" << userName << endl;
	}

	
} 

int main(){
	
	// test01();
	test02();
	
	system("pause");
	return 0;
} 
