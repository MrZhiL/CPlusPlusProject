#include<iostream>

using namespace std;

// pair����Ĵ��������ô�������ͷ�ļ�

void test01(){
	
	// ֱ�Ӹ�ֵ
	pair<string, int> p1("Tom", 21);
	// ʹ��make_pair���и�ֵ 
	pair<string, int> p2 = make_pair("Jerry", 19);
	
	cout << "������" << p1.first << ", ���䣺" << p1.second << endl;
	cout << "������" << p2.first << ", ���䣺" << p2.second << endl;
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0; 
} 
