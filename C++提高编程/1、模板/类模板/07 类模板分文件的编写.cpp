#include <iostream>
#include <string>

//#include "Person.h" // ֱ�ӵ���.h��ͷ�ļ����ᵼ�º���ʵ�ֵ�.cpp�ļ����Ӳ��� 

using namespace std;

// �������ļ��ı�д����ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ��� 
// ���������1��ֱ�ӵ���.cpp�ļ� (���÷���ʹ�ý���)
//#include "Person.cpp"

// ���������2����������ʵ��д��һ���ļ��У�����׺����Ϊ.hpp(�÷����Ƚϳ���)
#include "Person.hpp" 

void test01(){
	
	Person<string, int> p1("jack", 23);
	
	p1.showPerson();
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}

