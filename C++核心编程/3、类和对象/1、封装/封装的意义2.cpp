#include <iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * �������ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ��� 
 * ����Ȩ�������֣�public(����Ȩ��)��protected(����Ȩ��)��private(˽�б���) 
 * public����Ա�����ڿ��Է��ʣ�������Է���
 * protected: ��Ա�����ڿ��Է��ʣ����ⲻ���Է��� (����Ҳ���Է��ʸ����еı�������)
 * private: ��Ա�����ڿ��Է��ʣ����ⲻ���Է���(���Ӳ����Է��ʸ��׵�˽������)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 */ 
 
class Person{
public:
	string name;
protected:
	string car;
private:
	string password;
	
public:
	Person(){
		cout << "Person�Ĺ��캯��" << endl; 
	}
	void Init(){
		name = "jack";
		car = "polo";
		password = "123455";
	 }
};

class bob : public Person{
public:
 	bob(){
 		cout << "Bob�Ĺ��캯��" << endl;
 	}
 	bob(const Person &p){
 		name = p.name;
	 }
 	string name;
}; 

int main(){
	
	Person per1;
	
	per1.name = "lisi";
	per1.Init();
//	per1.car  = "benci";
	
	cout << per1.name << endl; 
	bob b1;
	bob b(per1);
	cout << b.name << endl;
	
	return 0;
}
 
