#include <iostream>

using namespace std;

// ��Ա��������Ϊ˽�У�
// 1�������Լ����ƶ�дȨ�ޣ�2������д���Լ�����ݵ���Ч�� 

class Person{
	
	public:
		// �������� 
		void setName(string t_name){
			name = t_name;
		} 
		// ��ȡ���� 
		string getName(){
			return name;
		} 
		
		// ��ȡ���� 
		int getAge(){
			age = 0; // ��ʼ������Ϊ0 
			return age;
		}
		
		void  setLover(string t_Lover){
			Lover = t_Lover;
		}
	// ����Ϊ˽������ 
	private:
		string name;	// �������ɶ���д 
		int age;		// ���䣺ֻ�� 
		string Lover;	// ���ˣ�ֻд 
	
}; 

int main(){
	
	Person per;
	
	per.setName("Jack"); 
	cout << "����Ϊ��" << per.getName() << endl;
	cout << "����Ϊ��" << per.getAge() << endl;
	
	per.setLover("Lihuw");
//	cout << "Lover: " << per.Lover << endl;	// LoverΪֻд״̬���ʲ������� 
	 
	return 0;
}
