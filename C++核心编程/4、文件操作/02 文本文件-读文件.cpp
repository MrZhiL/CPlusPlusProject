#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

void test01(){
	
	// 读文件步骤：
	// 1、创建文件流 ifstream ifs; 
	ifstream ifs;
	
	// 2、打开文件，并且判断是否打开成功： ifs.open("路径",ios::in);
	ifs.open("D:\\Program Files (x86)\\CPlusPlusProject\\C++核心编程\\说明.txt", ios::in);
	
	if(ifs.is_open()){
		cout << "文件打开成功，文件内容为：" << endl; 
	} else {
		cout << "文件打开失败！" << endl;
		return;
	}
	
	// 3、读文件（读文件的四种读取方式）：   ifs >> "" ;
	
	// 第一种读文件方式(该种方式不好用，如果检测到空格符符号，会发生换行)
//	char buff[1024] = {0};
//	while(ifs >> buff){
//		cout << buff << endl;
//	}

	// 第二种方式 
//	char buff[1024] = {0};
//	while(ifs.getline(buff,sizeof(buff))){
//		cout << buff << endl;
//	}
	
	// 第三种方式
	string buff;
	while (getline(ifs, buff)){
		cout << buff << endl;
	}
	
	// 第四种方式(不推荐，因为读取效率太低)
//	char c;
//	while( (c=ifs.get()) != EOF ){ // EOF : end of line
//		cout << c;
//	}

	// 4、关闭文件： ifs.close(); 
	ifs.close();
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
}
