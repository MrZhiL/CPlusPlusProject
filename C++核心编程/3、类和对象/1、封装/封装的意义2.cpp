#include <iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * 类在设计时，可以把属性和行为放在不同的权限下，加以控制 
 * 访问权限有三种：public(公共权限)、protected(保护权限)、private(私有保护) 
 * public：成员：类内可以访问，类外可以访问
 * protected: 成员：类内可以访问，类外不可以访问 (儿子也可以访问父亲中的保护内容)
 * private: 成员：类内可以访问，类外不可以访问(儿子不可以访问父亲的私有内容)
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
		cout << "Person的构造函数" << endl; 
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
 		cout << "Bob的构造函数" << endl;
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
 
