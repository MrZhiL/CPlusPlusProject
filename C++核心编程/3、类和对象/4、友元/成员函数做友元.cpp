#include <iostream>
#include <string>

using namespace std; 

// ��Ա��������Ԫ

class Building; 

class GoodFriend{
	
	public:
		
		// GoodFriend�Ĺ��캯��
		GoodFriend();
		
		void visit();	// visit���Է���Building�е�˽�г�Ա 
		void visit2();	// visit2�����Է���Building�е�˽�г�Ա 
	
		Building * building; 
};

class Building{
	
	// GoodFriend���еĳ�Ա��������Ԫ��֪ͨBuilding�࣬visitΪ�����ѣ����Է���˽������ 
	friend void GoodFriend::visit();
	
	public:
		
		// Building�Ĺ��캯�� 
		Building(); 
		
		string m_sittingRoom;	// ���� 
		
	private:
		string m_bedRoom;		// ���� 
};

void test01(); 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}

// ����Ϊ�Գ�Ա������ʼ��
GoodFriend::GoodFriend(){
	building = new Building;
}

Building::Building(){
	m_sittingRoom = "����";
	m_bedRoom = "����"; 
}

void GoodFriend::visit(){
	cout << "visit���ڷ��ʣ�" << building->m_sittingRoom << endl;
	cout << "visit���ڷ��ʣ�" << building->m_bedRoom << endl;
} 

void GoodFriend::visit2(){
	cout << "visit2���ڷ��ʣ�" << building->m_sittingRoom << endl;
//	cout << "visit2���ڷ��ʣ�" << building->m_bedRoom << endl;
}

void test01(){
	GoodFriend gf;
	gf.visit();
	gf.visit2();
}

