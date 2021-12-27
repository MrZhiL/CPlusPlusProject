#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// ��ģ����̳У�
// ����ģ�� ʹ�� �̳�ʱ����Ҫע�����¼��㣺
// 1��������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
// 2�������ָ�����������޷�����������ڴ�
// 3����������ָ��������T�����ͣ�����Ҳ���Ϊ��ģ��

template<class T1, class T2>
class Base{
	public:
		T1 m_Name;
		T2 m_Age;
}; 

// ����̳еĸ�����һ����ģ��ʱ��
//class Son1 :: public Base{ // ���󣬵�����̳еĸ���Ϊ��ģ��ʱ��������������������������,�����ָ�������޷������ڴ� 
class Son1:public Base<string, int>{
	public:
		Son1(){
			cout << "Son1����������Ϊ��" << typeid(Son1).name() << endl;
			cout << "Base����������Ϊ��" << typeid(Base).name() << endl; 
		} 
		int m_Num; 
}; 

// ���� �����Ҫ ���ָ�������е�T������Ҫ����ģ�廯
template<class T1, class T2, class T3>
class Son2:public Base<T2, T3>{
	public:
		Son2(){
			cout << "Son2����������Ϊ��" << typeid(Son2).name() << endl;
			cout << "T1����������Ϊ��" << typeid(T1).name() << endl; 
			cout << "T2����������Ϊ��" << typeid(T2).name() << endl; 
			cout << "T3����������Ϊ��" << typeid(T3).name() << endl; 
		}
}; 

void test01(){
	
	Son1 s1;
	Son2<int, string, char> s2;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
