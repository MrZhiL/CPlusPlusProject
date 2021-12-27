#include <iostream>
#include <string>
using namespace std;
/** 
// ����ģ��ľ�����: ģ���ͨ���Բ��������ܵ�
// ���磺template<class T>
//       void f(T a, T b) { a = b; }
// �������������ṩ�ĸ�ֵ��������������Ϊ�������޷�ʵ��

// �����磺template<class T>
//         void f(T a, T b){ 
//		 			if(a>b) {...} 
//				} 
// �����������У����T���������ʹ��������Person�������Զ����������ͣ�Ҳ�޷��������� 

// ���C++Ϊ�˽���������⣬�ṩ��ģ������أ�����Ϊ��Щ�ض��������ṩ�����ģ�� 
*/ 

// ���þ��廯��ģ�壬���Խ���Զ����������͵�ͨ�û�
// ѧϰģ�岢����Ϊ��дģ�壬������STL�ܹ�����ϵͳϵͳ��ģ��

class Person{
	
	public:
		
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		string m_Name;
		int m_Age;
	
};

template<typename T>
bool MyCompare(T &a, T &b){
	
	if(a == b) {
		return true;
	}else{
		return false;
	}
} 

// ͨ�����廯ģ�壬����Զ����������͵ĵ���
// ���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ��� 
template<> bool MyCompare(Person &p1, Person &p2){
	if(p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
		return true;
	}else{
		return false;
	}
}


// ��ϵͳ���ڵ������������Ա� 
void test01(){
	
	int a = 10;
	int b = 20;
	
	bool ret = MyCompare(a,b);
	if(ret){
		cout << "a == b" << endl;
	}else{
		cout << "a !=b " << endl;
	}
	
}

// ���Զ��������������Ա�
void test02(){
	
	Person p1("Tom", 18);
	Person p2("Tom", 18);
	
	bool ret = MyCompare(p1,p2);
	if(ret){
		cout << "p1 == p2" << endl;
	}else{
		cout << "p1 != p2 " << endl;
	}	
	 
	
} 

int main(){ 

	//test01();
	test02();
	
	system("pause"); 
	return 0; 
} 
