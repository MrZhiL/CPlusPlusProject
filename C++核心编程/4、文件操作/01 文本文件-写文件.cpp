#include <iostream>
#include <fstream>

// �ı��ļ��������裺
// 1���������ļ� #include <fstream>
// 2���������ļ� ofstream ofs;
// 3�����ļ�   ofs.open("�ļ�·��", �򿪷�ʽ);
// 4��д������   ofs << "data" << endl;
// 5���ر��ļ� 

using namespace std;

void test01(){
	
	// 1���������ļ� #include <fstream>
	// 2���������ļ� ofstream ofs;
	ofstream ofs;
	
	// 3�����ļ�   ofs.open("�ļ�·��", �򿪷�ʽ);
	ofs.open("test.txt", ios::out);
	
	// 4��д������   ofs << "data" << endl;
	ofs << "name: Jack" << endl;
	ofs << "age: 18 " << endl;
	ofs << "sex:man" << endl;
	
	// 5���ر��ļ� 
	ofs.close();
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
