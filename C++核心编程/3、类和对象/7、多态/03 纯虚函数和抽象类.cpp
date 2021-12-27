#include <iostream>

using namespace std;

// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容

// 因此可以将虚函数改为 纯虚函数 

// 纯虚函数语法：virturl 返回值类型 函数名 (参数列表) = 0; 

// 当类中有了纯虚函数，这个类也称为抽象类

// 抽象类特点：
// 1、无法实例化对象；
// 2、子类必须重写父类中的纯虚函数，否则也属于抽象类 

// 如果子类中没有堆区数据，可以不写虚析构或纯虚析构函数 

class Base{
	
	public:
		// 纯虚函数，此时该类为抽象类； 
		// 抽象类的特点：1、无法进行实例化；2、子类必须重写该函数，否则也为抽象类 
		virtual void func() = 0;
	
}; 

class Son1 : public Base{
	
	public:
		virtual void func(){
			cout << "This function is Son1::Base!" << endl;			
		}
};

int main(){
	
	//Base ba;  // 抽象类无法进行实例化
	//Son1 s;	// 若不进行重写纯虚函数，则无法进行实例化
	
	Base *ba = new Son1();
	
	ba->func(); 
	
	system("pause");
	return 0;
} 
