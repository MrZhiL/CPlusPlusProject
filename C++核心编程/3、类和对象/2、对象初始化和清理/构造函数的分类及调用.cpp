#include <iostream>
#include <string>

using namespace std;

// ���캯���ķ��༰����
// ���ࣺ
// ���ղ������ࣺ�޲ι���(�ֳ�ΪĬ�Ϲ���)���вι��� 
// ���������ࣺ��ͨ���캯�����������캯�� 
class Person{

	public:
		// �޲ι��캯��
		Person(){
			cout << "Person���޲ι��캯��" << endl; 
		} 
		// �вι��캯�� 
		Person(int a){
			age = a;
			cout << "Person���вι��캯��" << endl;
		} 
		
		// �������캯��
		Person (const Person &p){
			// ������������ϵ��������� ������������ 
			age = p.age;
			cout << "Person�Ŀ������캯��" << endl;
		} 
		
		~Person(){
			cout << "Person����������" << endl; 
		}
		
		int age;
}; 

// ���� 
void test01(){
	
	
#if 0
	// 1�����ŷ�
	
	/* ע����� 
	 * ����Ĭ�Ϲ��캯��ʱ����Ҫ��() 
	 * ��Ϊ��ʱ����������Ϊ�ô���(��һ�еĴ���)Ϊ����������,������Ϊ�ڴ������� 
	 * Person p1(); 
	 */ 

	Person p1;	// Ĭ�Ϲ��캯��
	Person p2(10);	//�вι��캯�� 
	Person p3(p2);	//�������캯��
	
	cout << "p2������Ϊ:" << p2.age << endl;
	cout << "p3������Ϊ:" << p3.age << endl; 
#endif	 
	 
#if 1
	// 2����ʾ��
	
	/* ע����� 
	 * 1��Person(10); // ��Person(10)Ϊ�������󣬣��ص㣩��ִ�н�����ϵͳ������������������ 
	 * 2����Ҫ���ÿ���������ʼ���������� ����������Ϊ Person (p2)==Person p2Ϊ��������,��˻��ض��� 
	 * Person p4(p2); 
	 */ 
	
	Person p1;	// Ĭ�Ϲ��캯��
	Person p2 = Person(10);	// �вι��캯��
	Person p3 = Person(p2); // �������캯�� 
	cout << "p2������Ϊ:" << p2.age << endl;
	cout << "p3������Ϊ:" << p3.age << endl;
//	Person (p2);	
#endif
	
#if 0	
	// 3����ʽת���� 
	
	Person p1;	// Ĭ�Ϲ��캯��
	// Person p2 = 10�ȼ���Person p2 = Person(10), 
	Person p2 = 10;	// �вι��캯��
	Person p3 = p2; // �������캯�� 
	
#endif
	
}

int main(){
	
	test01();
	
	return 0;
} 
