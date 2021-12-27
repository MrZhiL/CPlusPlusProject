#include <iostream>

using namespace std;

// ��ģ���еĳ�Ա�����Ĵ��� �� ��ͨ��Ա�����Ĵ�����������ģ�
// 1����ͨ��Ա������һ��ʼ�Ϳ��Դ���
// 2����ģ���еĳ�Ա������ʹ��ʱ�Ŵ���

class Person1{
	
	public:
		void ShowPerson1(){
			cout << "Person1 ShowFunction!" << endl;
		}
}; 

class Person2{
	
	public:
		void ShowPerson2(){
			cout << "Person2 ShowFunction!" << endl;
		}
};

template<class T>
class MyClass{
	
	public:
		T Per;
		
		// func1��func2���Ե���ShowPerson1()��ShowPerson2()��������Ϊ����������ʱ�޷�ȷ�� T ����������
		// ��˸�func1��func2������δ������ֻ�е��øú���ʱ�Ŵ����ú��� 
		void func1(){
			Per.ShowPerson1();
		} 
		
		void func2(){
			Per.ShowPerson2();
		}
	
};

void test01(){
	
	MyClass<Person1> myc;
	myc.func1();	// ֻ��ָ��TΪPerson1���ͣ��������func1���������ȴ����ú������ڵ��� 
	//myc.func2();    // ���ָ��TΪPerson1���Զ����������ͣ��򲻿ɵ���func2��������ΪPerson1��Person2�������Ͳ�ͬ 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
