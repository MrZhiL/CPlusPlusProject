#include <iostream>
#include <string>

using namespace std; 

class Buliding{
	
	// ���߱����� goodFriend��Buliding��ĺ����ѣ����Է������е�˽������ 
	friend void goorFriend(Buliding *room);
	
	public:
		Buliding(){
			cittingRoom = "����";
			bedRoom = "����"; 
		} 
	
	public:
		string cittingRoom;	//����
	private:
		string bedRoom;		//���� 
	
	
};

// ����ȫ�ֺ���
void goorFriend(Buliding *room){
	
	cout << "goodfriend���ڷ���" << room->cittingRoom << endl;
	cout << "goodfriend���ڷ���" << room->bedRoom << endl; 
	
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
