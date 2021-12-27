#include <iostream>
#include <string>
using namespace std;

// ��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������

// ����������������е�����������Ϊ���������ߴ�������

// �������ʹ��������Ĺ��ԣ�
// 1�����Խ������ָ���ͷ��������
// 2������Ҫ�о���ĺ���ʵ��

// �������ʹ�����������������Ǵ����������������ڳ����࣬�޷�ʵ��������

class Animal{
	
	public:
		Animal(){
			cout << "Animal���캯���ĵ��ã�" << endl;
		}
		
		virtual void speak() = 0; 
		
//		// �������������Խ������ָ���ͷŶ���ʱ���ɾ������� 
//		virtual ~Animal(){
//			cout << "Animal�����������ĵ��ã�" << endl;
//		}
		
		// ����������������Ҫ������Ҳ��Ҫʵ�� 
		virtual ~Animal() = 0; 
	
}; 

Animal::~Animal()  {
	cout << "Animal������������!" << endl;
}

class Cat : public Animal{
	
	public:
		
		Cat(string name){
			m_Name = new string(name);
			cout << "Cat�๹�캯���ĵ��ã�" << endl; 
		}
		
		virtual void speak(){
			cout << *m_Name << "Сè��˵����" << endl; 
		}
		
		~Cat(){
			cout << "Cat�����������ĵ��ã�" << endl; 
			
			// �ͷŶ������ٵ��ڴ�
			if(m_Name != NULL){
				delete m_Name;
				m_Name = NULL;
			} 
		}
		
		string *m_Name;
	
};

void test01(){
	
	Animal *cat1 = new Cat("Tom");

	cat1->speak();
	// ����ָ����������ʱ�򣬲�����������е�����������������������ж������ԣ�������ڴ�й¶ 
	// ��Ҫ�ͷ��ڶ������ٵ��ڴ�
	delete cat1; 
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
