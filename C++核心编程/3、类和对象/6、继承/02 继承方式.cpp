#include <iostream>

using namespace std;

// 继承的语法： class 子类 : 继承方式 父类
// 继承方式一共有三种：公共继承、保护继承、私有继承 

// 父类 
class Base{
	
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_c; 
	
};

// 1、公共继承
class son1:public Base{
	public: 
		void func(){
			m_A = 10;	// 父类中公共权限的成员，子类集成后依然是公共权限 
			m_B = 10;	// 父类中的保护权限的成员，子类继承后依然是保护权限
			//m_C = 10;  // 父类中私有权限的成员，子类不可访问 
		}
	
};

class GrandSon1:public son1{
	public:
		void func(){
			m_A = 123;	// son1中公共继承Base类，因此此时m_A和m_B的属性没有改变，此时GrandSon依然可以继承son1类 
			m_B = 321;
		}
}; 

void test01(){
	son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;		// m_B为保护权限，在类外不可访问（子类在类外也不可访问）
	s1.func();
	
	cout << "m_A = " << s1.m_A << endl; 
}

// 2、保护继承
class son2:protected Base{
	public: 
		void func(){
			m_A = 10;	// 父类中公共权限的成员，子类继承后 变为 保护权限（protected） 
			m_B = 10;	// 父类中的保护权限的成员，子类继承后依然是保护权限
			//m_C = 10;  // 父类中私有权限的成员，子类不可访问，但是子类仍会继承 
		}
	
};

class GrandSon2:public son2{
	public:
		void func(){
			m_A = 123;	// son1中公共继承Base类，因此此时m_A和m_B的属性均为protected,子类可以继承，此时GrandSon依然可以继承son2类 
			m_B = 321;
		}
};

void test02(){
	son2 gs2;
	//gs2.m_A = 10;	// 因为 son2中继承的m_A和m_B均变为protected权限，此时类外不可访问 
	//cout << gs2.m_A << endl;
} 

// 3、私有继承
class son3:private Base{
	public: 
		void func(){
			m_A = 10;	// 父类中公共权限的成员，子类继承后 变为私有属性 
			m_B = 10;	// 父类中的保护权限的成员，子类继承后 变为私有属性 
			//m_C = 10;  // 父类中私有权限的成员，子类不可访问 
		}
	
};

class GrandSon3:public son3{
	public:
		void func(){
			//m_A = 123;	// son1中公共继承Base类，因此此时m_A和m_B的属性为私有属性，此时GrandSon不可以继承son3类 
			//m_B = 321;
		}
};

int main(){
	
	test01();
	
	GrandSon1 gs1;
	gs1.func();
	cout << "m_A = " << gs1.m_A << endl;
	
	system("pause");
	return 0;
}
