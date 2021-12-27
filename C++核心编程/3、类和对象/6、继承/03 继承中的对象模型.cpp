#include <iostream>

using namespace std;

// 继承中的对象模型
// 问题：从父类继承过来的成员，哪些属于子类对象中 

class Base{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;
}; 

// 在Visio Stdio中可以利用开发工具命令提示工具查看对象模型
// 1、跳转盘符
// 2、跳转文件路径 cd 具体路径
// 3、查看命名
// 4、cl /d1 reportSingleClassLayout+类名 文件名 

class Son1 : public Base{
	public:
		int m_D;
};

void test01(){
	
	// 父类中所有非静态成员属性都会被子类继承下去
	// 父类中的私有成员属性，是被编译器隐藏了，因此访问不到。但是确实是被继承了 
	Son1 s1;
	
	cout << "sizeof(s1) = " << sizeof(s1) << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
