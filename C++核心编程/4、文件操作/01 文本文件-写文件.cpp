#include <iostream>
#include <fstream>

// 文本文件操作步骤：
// 1、引入流文件 #include <fstream>
// 2、创建流文件 ofstream ofs;
// 3、打开文件   ofs.open("文件路径", 打开方式);
// 4、写入数据   ofs << "data" << endl;
// 5、关闭文件 

using namespace std;

void test01(){
	
	// 1、引入流文件 #include <fstream>
	// 2、创建流文件 ofstream ofs;
	ofstream ofs;
	
	// 3、打开文件   ofs.open("文件路径", 打开方式);
	ofs.open("test.txt", ios::out);
	
	// 4、写入数据   ofs << "data" << endl;
	ofs << "name: Jack" << endl;
	ofs << "age: 18 " << endl;
	ofs << "sex:man" << endl;
	
	// 5、关闭文件 
	ofs.close();
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
