#include<iostream>
#include<string>

using namespace std;

/**
	功能描述：从字符串种获取想要的字串
	函数原型：string substr(int pos=0, int n = npos) const; // 返回由pos开始的n个字符组成的字符串 
 */ 

void test01(){
	
	string str = "HelloWorld! Tody is Tuesday and it is QiXi Festival!";
	
	string substr = str.substr(0,10);
	
	cout << substr << endl; 
	
}

// 实例：获取邮箱的有效用户名
void test02(){
	
	string Email;
	cout << "Please input your Email Adderss: ";
	cin >> Email;
	
	int EmailLoac = Email.find('@');
	
	if (EmailLoac == -1){
		cout << "邮箱输入错误!请输入xxxx@xx.xx格式" << endl; 
	} else {
		string userName = Email.substr(0,EmailLoac);
		cout << "用户名为：" << userName << endl;
	}

	
} 

int main(){
	
	// test01();
	test02();
	
	system("pause");
	return 0;
} 
