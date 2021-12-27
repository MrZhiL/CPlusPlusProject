#include <iostream>
#include <string>

using namespace std; 

class Buliding{
	
	// 告诉编译器 goodFriend是Buliding类的好朋友，可以访问类中的私有内容 
	friend void goorFriend(Buliding *room);
	
	public:
		Buliding(){
			cittingRoom = "客厅";
			bedRoom = "卧室"; 
		} 
	
	public:
		string cittingRoom;	//客厅
	private:
		string bedRoom;		//卧室 
	
	
};

// 创建全局函数
void goorFriend(Buliding *room){
	
	cout << "goodfriend正在访问" << room->cittingRoom << endl;
	cout << "goodfriend正在访问" << room->bedRoom << endl; 
	
} 

void test01(){
	Buliding room;
	goorFriend(&room);
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
	
}
