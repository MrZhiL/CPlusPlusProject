#include <iostream>
#include <string>
using namespace std;

// �ַ����Ƚ�
//�ַ����Ƚ��ǰ��ַ���ASCII����жԱȡ� 
//������(=)���򷵻أ�; �������(>)���򷵻�1�����С��(<)���򷵻�-1 
void test01(){
	
	string str1 = "HelloWorld!";
	
	string str2 = "HelloWorld����";
	
	// ��str1��str2���жԱȣ�compare()��������ֵΪ���� 
	int comp = str1.compare(str2);
	
	if(comp == 0){
		cout << "str1��str2��ȣ�" << endl; 
	} else if(comp == -1){
		cout << "str1��str2����ȣ�����str1��ASCII��С��str2��" << endl;
	}else{
		cout << "str1��str2����ȣ�����str1��ASCII�����str2��" << endl;
	} 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
