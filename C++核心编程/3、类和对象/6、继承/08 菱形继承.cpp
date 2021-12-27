#include <iostream>

using namespace std;

// 菱形继承
// 菱形继承的概念：两个派生类继承同一个基类
//				 ：又有某个类同时继承这两个派生类
//				 ：这种继承被成为菱形继承，或者钻石继承 

// 解决方法：使用虚拟继承即可（关键字：virtual） 
// 此时派生类变为虚继承，Animal类成为 虚基类、
// 虚继承会生成 .vbptr（Virtual base pointer）的虚基指针，该指针指向虚基类中的成员变量
// 而虚基类指针（vbptr）会有对应的vbtable（virtual base table）的虚基表 ，该虚基表中存放着子类中继承父类变量的偏移地址大小 

// 动物类 
class Animal{
	public:
		int m_Age;
}; 

// 羊类
class Sheep : virtual public Animal{ };

// 驼类
class Camel : virtual public Animal{ };

// 羊驼类
class Alpaca : public Sheep, public Camel{
	
}; 


void test01(){
	
	Alpaca al;
	
	cout << "继承后所占内存大小为：sizeof(Alpaca) = " << sizeof(Alpaca) << endl;
	cout << "虚拟继承后所占内存大小为：sizeof(Sheep) = " << sizeof(Sheep) << endl;
	cout << "虚拟继承后所占内存大小为：sizeof(Camel) = " << sizeof(Camel) << endl;
	cout << "sizeof(Animal) =" << sizeof(Animal) << endl; 
	// 因为羊驼类继承了两个派生类，所以存在两个m_Age，此时会出现二义性
	// 当菱形继承时，两个父类拥有相同的成员变量，需要标明作用域以区分 
	// 此时，数据重复会导致资源浪费 
	//al.m_Age = 10;
	al.Sheep::m_Age = 10; 
	al.Camel::m_Age = 8;
	
	cout << "Alpace::Sheep::m_Age = " << al.Sheep::m_Age << endl;
	cout << "Alpace::Camel::m_Age = " << al.Camel::m_Age << endl;
	
	al.m_Age = 5;
	cout << "羊驼的年龄为：" << al.m_Age << endl; 
	
}

int main(){
	
	test01();	
	
	system("pause");
	return 0;
	
}
