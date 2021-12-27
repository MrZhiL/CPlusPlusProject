#include <iostream>
#include <string>

using namespace std;

// 构造函数的分类及调用
// 分类：
// 按照参数分类：无参构造(又称为默认构造)、有参构造 
// 按照类别分类：普通构造函数、拷贝构造函数 
class Person{

	public:
		// 无参构造函数
		Person(){
			cout << "Person的无参构造函数" << endl; 
		} 
		// 有参构造函数 
		Person(int a){
			age = a;
			cout << "Person的有参构造函数" << endl;
		} 
		
		// 拷贝构造函数
		Person (const Person &p){
			// 将传入的人身上的所有属性 拷贝到我身上 
			age = p.age;
			cout << "Person的拷贝构造函数" << endl;
		} 
		
		~Person(){
			cout << "Person的析构函数" << endl; 
		}
		
		int age;
}; 

// 调用 
void test01(){
	
	
#if 0
	// 1、括号法
	
	/* 注意事项： 
	 * 调用默认构造函数时，不要加() 
	 * 因为此时编译器会认为该代码(下一行的代码)为函数的声明,不会认为在创建对象 
	 * Person p1(); 
	 */ 

	Person p1;	// 默认构造函数
	Person p2(10);	//有参构造函数 
	Person p3(p2);	//拷贝构造函数
	
	cout << "p2的年龄为:" << p2.age << endl;
	cout << "p3的年龄为:" << p3.age << endl; 
#endif	 
	 
#if 1
	// 2、显示法
	
	/* 注意事项： 
	 * 1：Person(10); // 该Person(10)为匿名对象，（特点）在执行结束后，系统会立即回收匿名对象 
	 * 2：不要利用拷贝函数初始化匿名对象， 编译器会认为 Person (p2)==Person p2为对象声明,因此会重定义 
	 * Person p4(p2); 
	 */ 
	
	Person p1;	// 默认构造函数
	Person p2 = Person(10);	// 有参构造函数
	Person p3 = Person(p2); // 拷贝构造函数 
	cout << "p2的年龄为:" << p2.age << endl;
	cout << "p3的年龄为:" << p3.age << endl;
//	Person (p2);	
#endif
	
#if 0	
	// 3、隐式转换法 
	
	Person p1;	// 默认构造函数
	// Person p2 = 10等价于Person p2 = Person(10), 
	Person p2 = 10;	// 有参构造函数
	Person p3 = p2; // 拷贝构造函数 
	
#endif
	
}

int main(){
	
	test01();
	
	return 0;
} 
