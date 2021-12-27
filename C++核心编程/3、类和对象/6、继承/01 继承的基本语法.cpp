#include <iostream>
#include <string>

using namespace std;

// 继承实现页面
// 继承的优点：较少重复代码
// 语法：class 子类 : 继承方式 父类
// 子类 也称为 派生类；父类 也称为 基类 

// 公共页面 （父类） 
class BasicPage{
	
	public:
		// 头部内容 
		void header(){
			cout << "首页、公开课、登录、注册" << endl; 
		}	
		// 底部内容
		void footer(){
			cout << "友情链接、客服、地址、网络协议" << endl; 
		} 
		// 左边内容
		void left(){
			cout << "java、Python、C++、WebPage" << endl; 
		}
		
	private:
		void priTest(){
			cout << "This is a private function!" << endl; 
		} 
}; 

//  子类 1：java 
class Java : public BasicPage{
	public:
		// 子类中包含的内容 
		void content(){
			cout << "This is a Java Web!" << endl;
		} 
};

//  子类 2：Python
class Python : public BasicPage{
	public:
		// 子类中包含的内容 
		void content(){
			cout << "This is a Python Web!" << endl;
		} 
};

//  子类 3：C++
class CPP : public BasicPage{
	public:
		// 子类中包含的内容 
		void content(){
			cout << "This is a CPP Web!" << endl;
		} 
};

void test01(){
	
	cout << "* * * * * * *  * * * * * * * * * *" << endl; 
	
	Java ja;
	ja.header();
	ja.left();
	ja.content();
	ja.footer();
//	ja.priTest();
	
	cout << "* * * * * * *  * * * * * * * * * *" << endl; 
	
	Python py;
	py.header();
	py.left();
	py.content();
	py.footer();
	
	cout << "* * * * * * *  * * * * * * * * * *" << endl; 
	
	CPP cpp;
	cpp.header();
	cpp.left();
	cpp.content();
	cpp.footer();

}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
