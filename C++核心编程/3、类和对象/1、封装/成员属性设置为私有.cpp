#include <iostream>

using namespace std;

// 成员属性设置为私有：
// 1、可以自己控制读写权限；2、对于写可以检测数据的有效性 

class Person{
	
	public:
		// 设置姓名 
		void setName(string t_name){
			name = t_name;
		} 
		// 获取姓名 
		string getName(){
			return name;
		} 
		
		// 获取年龄 
		int getAge(){
			age = 0; // 初始化年龄为0 
			return age;
		}
		
		void  setLover(string t_Lover){
			Lover = t_Lover;
		}
	// 设置为私有属性 
	private:
		string name;	// 姓名：可读可写 
		int age;		// 年龄：只读 
		string Lover;	// 情人：只写 
	
}; 

int main(){
	
	Person per;
	
	per.setName("Jack"); 
	cout << "姓名为：" << per.getName() << endl;
	cout << "年龄为：" << per.getAge() << endl;
	
	per.setLover("Lihuw");
//	cout << "Lover: " << per.Lover << endl;	// Lover为只写状态，故操作错误 
	 
	return 0;
}
