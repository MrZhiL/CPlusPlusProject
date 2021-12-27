#include <iostream>

using namespace std;

// 多态

// 多态多态的满足条件:
// 1、有继承关系
// 2、子类要重写父类中的虚函数 --重写不是重载 

// 多态多态使用：父类的指针或者引用，指向子类对象 
//  

// 重写的概念：函数的返回值类型、函数名、参数列表 完全相同才是重写 

// 动物类
// 空类的占用内存大小为1 
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
// Cat类
class Cat : public Animal{
	
	public:
		int k; 
		Cat() {
			k = 10;
		}
		// 子类中的virtual可写和不写 
		// 当子类重写了父类的虚函数，子类中的虚函数表 内部 会替换成 子类的虚函数地址 
		virtual void speak(){
			cout << "The Cat is speaking!" << endl;
		}
		
		void func1() {
			cout << "Cat::func1()" << endl;
		} 
}; 

// Dog类 
class Dog : public Animal{
	public:
		void speak(){
			cout << "The Dog is speaking!" << endl;
		}
}; 

// Speaking函数：执行说话函数 
// 地址早绑定，在编译阶段确定函数的地址
// 如果想要执行让猫说话，那么这个函数地址就不能提前绑定，需要在编译阶段进行绑定，地址晚绑定 
void doSpeaking(Animal &animal){ // Animal &animal = cat/dog 
	animal.speak();
//	animal.speak2(); 
} 

void test01(){
	Animal *an = new Cat();
	cout << an->k << endl; 	// 此时调用的是Animal中的k，输出为1 
	an->speak();
//	an->func1();

	Cat *cat2 = (Cat*)an; // 强制类型转换，此时an和cat2的地址相同 
	cout << "cat2 address = " << cat2 << endl;
	cout << "an address = " << an << endl;
	cout << "cat2 == an ? " << (cat2 == an) << endl;
	cout << cat2->k << endl; // 此时调用的是ACat中的k，输出为10 
	 
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
