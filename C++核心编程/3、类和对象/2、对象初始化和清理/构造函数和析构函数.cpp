#include <iostream>

using namespace std;

// ����ĳ�ʼ��������

class Person{
	public:
		// 1�����캯��
		// û�з���ֵ��Ҳ����дvoid
		// ��������������ͬ
		// ���캯�������в��������Է�������
		// ���������ʱ�򣬹��캯�����Զ�����
		Person(){
			cout << "This is a Person Creation function!" << endl;
		} 
		
		// 2���������� ��������Ĳ���
		// û�з���ֵ ��ͬдvoid
		// ��������������ͬ(ǰ�����~)���������в����������Է�������
		// ����������ǰ���Զ�����������������ֻ����һ�� 
		~Person(){
			cout << "This is a Person Destruct function!" << endl;
		} 
		 
}; 

// ���������͹��캯���Ǳ���Ҫ�е�ʵ�֣���������Լ����ṩ������������ṩһ����ʵ�ֵĹ������������ 
void test01(){
	Person p1;	// ��ջ�ϵ����ݣ�test01���ý�����ͻ��ͷ� 
}

int main(){
	
	Person p; 
	
	test01();
//	test01();
	
	return 0;
} 
