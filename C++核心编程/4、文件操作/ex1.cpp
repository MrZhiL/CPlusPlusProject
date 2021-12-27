#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void test01(){
	
	// 创建输入输出流
	fstream file2;
	
	// 打开文件
	file2.open("example2.txt", ios::out);
	// 输入数据
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
		cout << "-------打开文件成功！--------" << endl; 
	}else{
		cout << "-------打开文件失败！--------" << endl; 
	}
	
	// 读取数据
//	// 方案1：
//	char buff[1024] = {0};
//	while (file2 >> buff){
//		cout << buff << endl;
//	} 
	
//	// 方案2：
//	char buff[1024] = {0};
//	while (file2.getline(buff,sizeof(buff))){
//		cout << buff << endl;
//	} 
//	
//	cout << "--------------------------" << endl; 
	
	// 放案3
	string buf2;
	while ((getline(file2,buf2))){
		cout << buf2 << endl;
	} 
	 
	// 关闭文件 
	file2.close(); 
	
}

int main(){
	
	test01();

	system("pause");
	return 0;
}
