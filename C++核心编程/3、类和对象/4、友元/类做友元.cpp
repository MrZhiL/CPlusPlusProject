#include <iostream>
#include <string>

using namespace std; 

// 类做友元
class Buliding;
class goodFriend; 

class goodFriend{
	public:
		
		goodFriend();
		
		void visit();	// 参观函数，访问buliding中的属性 
		
		Buliding *building;
};

class Buliding{
	
	// goodFriend类是本来的好朋友，可以访问私有的属性 
	friend class goodFriend; 
	
	public:
		Buliding();
	
	public:
		string cittingRoom;	//客厅
	private:
		string bedRoom;		//卧室 
	
	
};

// 类外写成员函数 
goodFriend::goodFriend(){
	building = new Buliding;
}

void goodFriend::visit(){
	cout << "goodfriend正在访问" << building->cittingRoom << endl;
	cout << "goodfriend正在访问" << building->bedRoom << endl; 
}

Buliding::Buliding(){
	cittingRoom = "客厅";
	bedRoom = "卧室"; 
} 

void test01(){
	goodFriend gf;
	gf.visit();
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
