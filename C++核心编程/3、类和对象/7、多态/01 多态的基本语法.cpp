#include <iostream>

using namespace std;

// ��̬

// ��̬��̬����������:
// 1���м̳й�ϵ
// 2������Ҫ��д�����е��麯�� --��д�������� 

// ��̬��̬ʹ�ã������ָ��������ã�ָ��������� 
//  

// ��д�ĸ�������ķ���ֵ���͡��������������б� ��ȫ��ͬ������д 

// ������
// �����ռ���ڴ��СΪ1 
class Animal{
	public:
		int k; 
		Animal() {
			k = 1;
		} 
		virtual void speak(){
			cout << "Animal is speaking!" << endl; 
		}
//		void speak2(){
//			cout << "11111" << endl;
//		} 
}; 
// Cat��
class Cat : public Animal{
	
	public:
		int k; 
		Cat() {
			k = 10;
		}
		// �����е�virtual��д�Ͳ�д 
		// ��������д�˸�����麯���������е��麯���� �ڲ� ���滻�� ������麯����ַ 
		virtual void speak(){
			cout << "The Cat is speaking!" << endl;
		}
		
		void func1() {
			cout << "Cat::func1()" << endl;
		} 
}; 

// Dog�� 
class Dog : public Animal{
	public:
		void speak(){
			cout << "The Dog is speaking!" << endl;
		}
}; 

// Speaking������ִ��˵������ 
// ��ַ��󶨣��ڱ���׶�ȷ�������ĵ�ַ
// �����Ҫִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�ڱ���׶ν��а󶨣���ַ��� 
void doSpeaking(Animal &animal){ // Animal &animal = cat/dog 
	animal.speak();
//	animal.speak2(); 
} 

void test01(){
	Animal *an = new Cat();
	cout << an->k << endl; 	// ��ʱ���õ���Animal�е�k�����Ϊ1 
	an->speak();
//	an->func1();

	Cat *cat2 = (Cat*)an; // ǿ������ת������ʱan��cat2�ĵ�ַ��ͬ 
	cout << "cat2 address = " << cat2 << endl;
	cout << "an address = " << an << endl;
	cout << "cat2 == an ? " << (cat2 == an) << endl;
	cout << cat2->k << endl; // ��ʱ���õ���ACat�е�k�����Ϊ10 
	 
	Cat cat;
	doSpeaking(cat);
	cout << "sizeof(Cat) = " << sizeof(cat) << endl;
	
	Dog dog;
	doSpeaking(dog);
	cout << "sizeof(Dog) = " << sizeof(dog) << endl;
}

void test02(int arr[]) {

}

int main(){
	
	test01();
	
	int  arr[] = {1,2,3};
//	test02(1,2,3); // error 
	
	cout << "sizeof(Animal) = " << sizeof(Animal) << endl; 
	
	system("pause");
	return 0;
} 
