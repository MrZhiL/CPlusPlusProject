#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

void test01(){
	
	// ���ļ����裺
	// 1�������ļ��� ifstream ifs; 
	ifstream ifs;
	
	// 2�����ļ��������ж��Ƿ�򿪳ɹ��� ifs.open("·��",ios::in);
	ifs.open("D:\\Program Files (x86)\\CPlusPlusProject\\C++���ı��\\˵��.txt", ios::in);
	
	if(ifs.is_open()){
		cout << "�ļ��򿪳ɹ����ļ�����Ϊ��" << endl; 
	} else {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	
	// 3�����ļ������ļ������ֶ�ȡ��ʽ����   ifs >> "" ;
	
	// ��һ�ֶ��ļ���ʽ(���ַ�ʽ�����ã������⵽�ո�����ţ��ᷢ������)
//	char buff[1024] = {0};
//	while(ifs >> buff){
//		cout << buff << endl;
//	}

	// �ڶ��ַ�ʽ 
//	char buff[1024] = {0};
//	while(ifs.getline(buff,sizeof(buff))){
//		cout << buff << endl;
//	}
	
	// �����ַ�ʽ
	string buff;
	while (getline(ifs, buff)){
		cout << buff << endl;
	}
	
	// �����ַ�ʽ(���Ƽ�����Ϊ��ȡЧ��̫��)
//	char c;
//	while( (c=ifs.get()) != EOF ){ // EOF : end of line
//		cout << c;
//	}

	// 4���ر��ļ��� ifs.close(); 
	ifs.close();
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
}
