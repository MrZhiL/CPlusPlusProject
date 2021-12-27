#include <iostream>
#include <string>
using namespace std;

// 字符串比较
//字符串比较是按字符的ASCII码进行对比。 
//如果相等(=)，则返回０; 如果大于(>)，则返回1；如果小于(<)，则返回-1 
void test01(){
	
	string str1 = "HelloWorld!";
	
	string str2 = "HelloWorld！！";
	
	// 将str1和str2进行对比，compare()函数返回值为整形 
	int comp = str1.compare(str2);
	
	if(comp == 0){
		cout << "str1和str2相等！" << endl; 
	} else if(comp == -1){
		cout << "str1和str2不相等！其中str1的ASCII码小于str2的" << endl;
	}else{
		cout << "str1和str2不相等！其中str1的ASCII码大于str2的" << endl;
	} 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
