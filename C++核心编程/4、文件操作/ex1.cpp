#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void test01(){
	
	// �������������
	fstream file2;
	
	// ���ļ�
	file2.open("example2.txt", ios::out);
	// ��������
	file2  << "#include <iostream> " << endl
		   << "using namespace std;" << endl
		   << endl
		   << "void main(){ " << endl
		   << "    cout << \"HelloWorld!\" << endl; " << endl
		   << "    system(\"pause\");" << endl
		   << "    return 0;" << endl
		   << "}" << endl;
	file2  << "HelloWorld!" << endl; 
	file2.write("Hello! Mr.Zhi, I'm meet to you!",sizeof("Hello! Mr.Zhi, I'm meet to you!"));
	cout << sizeof("Hello! Mr.Zhi, I'm meet to you!") << endl;
	file2.close();
	
	file2.open("example2.txt", ios::in);
	if (file2.is_open()){
		cout << "-------���ļ��ɹ���--------" << endl; 
	}else{
		cout << "-------���ļ�ʧ�ܣ�--------" << endl; 
	}
	
	// ��ȡ����
//	// ����1��
//	char buff[1024] = {0};
//	while (file2 >> buff){
//		cout << buff << endl;
//	} 
	
//	// ����2��
//	char buff[1024] = {0};
//	while (file2.getline(buff,sizeof(buff))){
//		cout << buff << endl;
//	} 
//	
//	cout << "--------------------------" << endl; 
	
	// �Ű�3
	string buf2;
	while ((getline(file2,buf2))){
		cout << buf2 << endl;
	} 
	 
	// �ر��ļ� 
	file2.close(); 
	
}

int main(){
	
	test01();

	system("pause");
	return 0;
}
