#include <iostream>
#include <string>

using namespace std; 

// ������Ԫ
class Buliding;
class goodFriend; 

class goodFriend{
	public:
		
		goodFriend();
		
		void visit();	// �ιۺ���������buliding�е����� 
		
		Buliding *building;
};

class Buliding{
	
	// goodFriend���Ǳ����ĺ����ѣ����Է���˽�е����� 
	friend class goodFriend; 
	
	public:
		Buliding();
	
	public:
		string cittingRoom;	//����
	private:
		string bedRoom;		//���� 
	
	
};

// ����д��Ա���� 
goodFriend::goodFriend(){
	building = new Buliding;
}

void goodFriend::visit(){
	cout << "goodfriend���ڷ���" << building->cittingRoom << endl;
	cout << "goodfriend���ڷ���" << building->bedRoom << endl; 
}

Buliding::Buliding(){
	cittingRoom = "����";
	bedRoom = "����"; 
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
