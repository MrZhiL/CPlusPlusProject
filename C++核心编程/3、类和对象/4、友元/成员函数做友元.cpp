#include <iostream>
#include <string>

using namespace std; 

// 成员函数做友元

class Building; 

class GoodFriend{
	
	public:
		
		// GoodFriend的构造函数
		GoodFriend();
		
		void visit();	// visit可以访问Building中的私有成员 
		void visit2();	// visit2不可以访问Building中的私有成员 
	
		Building * building; 
};

class Building{
	
	// GoodFriend类中的成员函数做友元，通知Building类，visit为好朋友，可以访问私有属性 
	friend void GoodFriend::visit();
	
	public:
		
		// Building的构造函数 
		Building(); 
		
		string m_sittingRoom;	// 客厅 
		
	private:
		string m_bedRoom;		// 卧室 
};

void test01(); 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}

// 在类为对成员函数初始化
GoodFriend::GoodFriend(){
	building = new Building;
}

Building::Building(){
	m_sittingRoom = "客厅";
	m_bedRoom = "卧室"; 
}

void GoodFriend::visit(){
	cout << "visit正在访问：" << building->m_sittingRoom << endl;
	cout << "visit正在访问：" << building->m_bedRoom << endl;
} 

void GoodFriend::visit2(){
	cout << "visit2正在访问：" << building->m_sittingRoom << endl;
//	cout << "visit2正在访问：" << building->m_bedRoom << endl;
}

void test01(){
	GoodFriend gf;
	gf.visit();
	gf.visit2();
}

