#include <iostream>

using namespace std;

// ��Ա�����ͳ�Ա�����ֿ��洢
// ��C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
// ֻ�зǾ�̬��Ա������������Ķ����� 

// �ն���ռ���ڴ�ռ�Ϊ��1�ֽ�
// C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ�á� 
// ÿ���ն���ҲӦ�����͹޳���һ�޶����ڴ��ַ 

class emptyCl{
	
}; 

// this���Խ�����Ƴ�ͻ
// ���Է��ض����� return *this

class Person{
	public:
		// �޲ι��캯�� 
		Person(){
			mA = 10;
		}
		
		// �Ǿ�̬��Առ�ö���ռ� 
		int mA;
		int age; 
		// ��̬��Ա������ռ�ö���ռ� ����������Ķ����� 
		static int mB;
		// ����Ҳ��ռ�ö���ռ䣬���Ժ�������һ������ʵ�� 
		void func(int age){
			// thisָ��ָ�򱻵��õĳ�Ա���������Ķ��� 
			this->age = age;
			cout << "mA:" << this->mA << endl;
		}
		
		// �����������(Person &)������Խ�����ʽ��̣��������ֵ(Person )��ֻ���в��� 
		// ����ֵ��ʱ��ᴴ��һ���¶��󣬶������򲻻�(����ʱ���ص����Լ�����) 
		Person& addPersonAge(Person &p){
			this->age += p.age;
			
			// this ָ��p2��ָ�룬��*thisָ��p2������� 
			return *this;
		} 
		
		static int func2(){
			cout << "��̬��Ա����Ҳ��������Ķ�����" << endl; 
		}
	
}; 

int Person::mB = 0;


void test01(){
	Person p,p2;
	emptyCl ec;
	p.func(18);
	p.mB = 100;
	cout << "p1������Ϊ:" << p.age << endl; 
	
	p2.func(20);
	// ��ʽ���˼�� 
	p2.addPersonAge(p).addPersonAge(p).addPersonAge(p);
	cout << "p2������Ϊ��" << p2.age << endl; 
	
	// ֻ�зǾ�̬��Ա������ռ����Ŀռ� 
	cout << "sizeof(p):" << sizeof(p) << endl; 
	cout << "sizeof(ec):" << sizeof(ec) << endl; 
} 

int main(){
	
	test01();
	
	system("pause"); 
	return 0;
}
