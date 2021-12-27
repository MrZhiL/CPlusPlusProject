#include <iostream> 
#include <string>

#include "MyArray.hpp"
 
using namespace std;

/******************************************
 *����������ʵ��һ��ͨ�õ������࣬Ҫ�����£� 
 * 1�����Զ��������������Լ��Զ����������͵����ݽ��д洢
 * 2�������캯���洢������
 * 3�����캯���п��Դ������������
 * 4���ṩ���õĿ������캯���Լ�operator=��ֹǳ��������
 * 5���ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
 * 6������ͨ���±�ķ�ʽ���������е�Ԫ��
 * 7�����Ի�ȡ�����е�ǰԪ�ظ�������������� 
 */

void printIntArray(MyArray<int> &arr){
	for(int i=0; i<arr.PrintCapacity(); i++){
		cout << arr[i] << "  ";
	}
	cout << endl;
}

// �����������ʹ洢 
void test01(){
	// �����вι��캯�� 
	MyArray<int> arr1(15);

	for(int i=0; i<arr1.PrintCapacity(); i++){
		//arr1[i] = i;
		// ͨ��β�巨��������
		arr1.PushInsert(i); 
	} 
	cout << "arr1����Ϊ: "; 
	printIntArray(arr1);
	
	arr1.PushInsert(100);
	 
	cout << "arr1����������Ϊ��" << arr1.PrintCapacity() << endl; 
	cout << "arr1�������СΪ��" << arr1.PrintSize() << endl; 
	
	// ���ÿ������캯�� 
	MyArray<int> arr2(arr1);
	cout << "arr2����Ϊ: "; 
	printIntArray(arr2);
	cout << "arr2����������Ϊ��" << arr2.PrintCapacity() << endl; 
	cout << "arr2�������СΪ��" << arr2.PrintSize() << endl; 
	
	// ͨ��βɾ��ɾ������
	arr2.BackDelete(); 
	printIntArray(arr2);
	cout << "arr2βɾ��"; 
	cout << "arr2����������Ϊ��" << arr2.PrintCapacity() << endl; 
	cout << "arr2�������СΪ��" << arr2.PrintSize() << endl; 
//	// ����operator=���� 
//	MyArray<int> arr3(100);
//	arr3 = arr2; 
	 
}

// �Զ���������������洢
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
		cout << "���䣺" << arr[i].m_Name << ", age: " << arr[i].m_Age << endl;
	}
}

void test02(){
	
	MyArray<Person> arr(10);
//	
//	Person p1("�ŷ�", 32);
//	
//	arr.PushInsert(p1);
	arr.PushInsert(Person("�ŷ�", 32));
	arr.PushInsert(Person("����", 34));
	arr.PushInsert(Person("�����", 999));
	arr.PushInsert(Person("��˽�", 888));
	arr.PushInsert(Person("������", 35));
	arr.PushInsert(Person("����", 42));

	printPersonArray(arr);
	cout << "Person��������Ϊ��" << arr.PrintCapacity() << endl;
	cout << "Person�����СΪ��" << arr.PrintSize() << endl; 
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
}
