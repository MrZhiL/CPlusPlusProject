#include<iostream>
#include<map>

using namespace std;

// map�������������Ĭ��Ϊ����Ҫ��ı����������Ҫ���÷º���

// �º���
class MyCompare{
	
	public:
		// ʹ�÷º������ı�������� 
		bool operator() (const int &m1, const int &m2){
			// �ı��������Ϊ���Ӵ�С���������� 
			return m1 > m2;
		}
	
};

class Person{
	public:
		
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		string m_Name;
		int m_Age;
	
}; 

// �Զ����������͵ķº���������ʹ������ķº������ɣ���Ϊ�ǶԼ�ֵ�����������Ӧ��Ϊint�������ͣ�������Person�������ͣ� 
class MyCompare2{
	
	public:
		// ʹ�÷º������ı�������� 
		bool operator() (const Person &p1, const Person &p2){
			// �ı��������Ϊ���Ӵ�С���������� 
			return p1.m_Age > p2.m_Age;
		}
	
};

void printMapRoom(const map<int, int, MyCompare> &mp){
	if(mp.empty()){
		cout << "������Ϊ��@" << endl;
	}
	for(map<int, int, MyCompare>::const_iterator it = mp.begin(); it != mp.end(); it++){
		cout << "key = " << it->first << " ,value = " << it->second << endl;
	}
	cout << endl;
}

// �����������ͣ�ͨ���º����ı�������򣺴Ӵ�С���� 
void test01(){
	
	// �����������ͣ�ͨ���º����ı�������򣺴Ӵ�С���� 
	map<int, int, MyCompare> mp;
	mp.insert(make_pair(1,10));
	mp.insert(make_pair(3,21));
	mp.insert(make_pair(5,16));
	mp.insert(make_pair(2,17));
	
	mp.insert(map<int, int>::value_type(4,23));
	
	printMapRoom(mp);
	
}

// �Զ����������͸ı�������� 
void test02(){
	
	map<int, Person, MyCompare> mp;
	mp.insert(make_pair(1,Person("�ŷ�",27)));
	mp.insert(make_pair(3,Person("����",26)));
	mp.insert(make_pair(5,Person("����",25)));
	mp.insert(make_pair(4,Person("�ܲ�",32)));
	mp.insert(make_pair(2,Person("��Ȩ",28))); 
	
	for(map<int, Person, MyCompare>::iterator it = mp.begin(); it != mp.end(); it++){
		cout << "��ֵΪ��" << it->first << ", ֵ������ " << it->second.m_Name << ", ����  " << it->second.m_Age << endl; 
	}
	
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
