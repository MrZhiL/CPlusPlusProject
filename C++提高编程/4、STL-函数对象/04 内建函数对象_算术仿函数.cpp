#include<iostream>
#include<functional> 
using namespace std;

// �ڽ��������������º���
// ʹ���ڽ�����������Ҫʹ��#include<functional>ͷ�ļ� 

void test01(){
	
	// negate�º�����ȡ����������ΪһԪν��
	negate<int> n;
	cout << "ȡ���º����ĵ��ã�50ȡ����Ϊ��"; 
	cout << n(50) << endl; 
	
	// plus�ӷ��º�����Ϊ��Ԫν�ʣ�ֻ��negateΪһԪν�ʣ����඼�Ƕ�Ԫν�ʣ� 
	plus<int> p;
	cout << "�ӷ��º����ĵ��ã�10+11 = " << p(10,11) << endl; 
	
	// minus�����º���
	minus<int> m;
	cout << "�����º����ĵ��ã�100-23 = " << m(100,23) << endl;
	
	// multiples�˷��º���
	multiplies<int> ml;
	cout << "�˷��º����ĵ��ã�10*23 = " << ml(10,23) << endl;
	
	// divides�����º���
	divides<int> div;
	cout << "�����º����ĵ��ã�100/25 = " << div(100,25) << endl;
	
	// modulusȡģ�º��� 
	modulus<int> mod;
	cout << "ȡģ�º����ĵ��ã�100%8 = " << mod(100, 8) << endl; 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
