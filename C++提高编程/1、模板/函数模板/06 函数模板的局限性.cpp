#include <iostream>
#include <string>
using namespace std;
/** 
// 函数模板的局限性: 模板的通用性并不是万能的
// 例如：template<class T>
//       void f(T a, T b) { a = b; }
// 在上述代码中提供的赋值操作，如果传输的为数组则无法实现

// 在例如：template<class T>
//         void f(T a, T b){ 
//		 			if(a>b) {...} 
//				} 
// 在上述代码中，如果T的数据类型传输的像是Person这样的自定义数据类型，也无法正常运行 

// 因此C++为了解决这种问题，提供了模板的重载，可以为这些特定的类型提供具体的模板 
*/ 

// 利用具体化的模板，可以解决自定义数据类型的通用化
// 学习模板并不是为了写模板，而是在STL能够运用系统系统的模板

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

// 通过具体化模板，解决自定义数据类型的调用
// 利用具体化Person的版本实现代码，具体化优先调用 
template<> bool MyCompare(Person &p1, Person &p2){
	if(p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
		return true;
	}else{
		return false;
	}
}


// 对系统存在的数据类型做对比 
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

// 对自定义数据类型做对比
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
