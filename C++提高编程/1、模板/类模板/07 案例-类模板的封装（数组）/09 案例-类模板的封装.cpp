#include <iostream> 
#include <string>

#include "MyArray.hpp"
 
using namespace std;

/******************************************
 *案例描述：实现一个通用的数组类，要求如下： 
 * 1、可以对内置数组类型以及自定义数据类型的数据进行存储
 * 2、将构造函数存储到堆区
 * 3、构造函数中可以传入数组的容量
 * 4、提供对用的拷贝构造函数以及operator=防止浅拷贝问题
 * 5、提供尾插法和尾删法对数组中的数据进行增加和删除
 * 6、可以通过下标的方式访问数组中的元素
 * 7、可以获取数组中当前元素个数和数组的容量 
 */

void printIntArray(MyArray<int> &arr){
	for(int i=0; i<arr.PrintCapacity(); i++){
		cout << arr[i] << "  ";
	}
	cout << endl;
}

// 内置数组类型存储 
void test01(){
	// 调用有参构造函数 
	MyArray<int> arr1(15);

	for(int i=0; i<arr1.PrintCapacity(); i++){
		//arr1[i] = i;
		// 通过尾插法插入数据
		arr1.PushInsert(i); 
	} 
	cout << "arr1数组为: "; 
	printIntArray(arr1);
	
	arr1.PushInsert(100);
	 
	cout << "arr1的数组容量为：" << arr1.PrintCapacity() << endl; 
	cout << "arr1的数组大小为：" << arr1.PrintSize() << endl; 
	
	// 调用拷贝构造函数 
	MyArray<int> arr2(arr1);
	cout << "arr2数组为: "; 
	printIntArray(arr2);
	cout << "arr2的数组容量为：" << arr2.PrintCapacity() << endl; 
	cout << "arr2的数组大小为：" << arr2.PrintSize() << endl; 
	
	// 通过尾删法删除数据
	arr2.BackDelete(); 
	printIntArray(arr2);
	cout << "arr2尾删后："; 
	cout << "arr2的数组容量为：" << arr2.PrintCapacity() << endl; 
	cout << "arr2的数组大小为：" << arr2.PrintSize() << endl; 
//	// 调用operator=函数 
//	MyArray<int> arr3(100);
//	arr3 = arr2; 
	 
}

// 自定义数据类型数组存储
class Person {
	public:
		
		Person(){};
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		
		string m_Name;
		int m_Age;
};

void printPersonArray(MyArray<Person> &arr){
	for (int i=0; i<arr.PrintSize(); i++){
		cout << "年龄：" << arr[i].m_Name << ", age: " << arr[i].m_Age << endl;
	}
}

void test02(){
	
	MyArray<Person> arr(10);
//	
//	Person p1("张飞", 32);
//	
//	arr.PushInsert(p1);
	arr.PushInsert(Person("张飞", 32));
	arr.PushInsert(Person("关羽", 34));
	arr.PushInsert(Person("孙悟空", 999));
	arr.PushInsert(Person("猪八戒", 888));
	arr.PushInsert(Person("神算子", 35));
	arr.PushInsert(Person("周起", 42));

	printPersonArray(arr);
	cout << "Person数组容量为：" << arr.PrintCapacity() << endl;
	cout << "Person数组大小为：" << arr.PrintSize() << endl; 
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
}
