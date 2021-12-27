#include <iostream>
#include <stdlib.h>
using namespace std;

/**************************************
 * C++������new�������ڶ����������� 
 * �������ٵ����ݣ��ɳ���Ա�ֶ����٣��ֶ��ͷţ�ʲ�������ò�����delete 
 * ����new���������ݣ��᷵�ظ����ݶ�Ӧ�����͵�ָ�� 
 *************************************** 
 */

// 1������new�ؼ��ַ����ڴ� 
int *func1(){
	
	int *p = new int(10); 
	return p;
}

// 2������new�ؼ���Ϊ��������ڴ�
int *func2(){
	
	// ����new�ؼ��ָ�һ��10��Ԫ�ص���������ڴ棬��ʱnew���ص���������׵�ַ 
	int *arr = new int[10];

	return arr; 
} 


int main(){
	
	int *test01 = func1();
	int *test02 = func2();
	int i; 
	
	cout << "test01:" << endl;
	cout << "1:*test01 = " << *test01 << endl;
	cout << "2:*test01 = " << *test01 << endl;
	cout << "3:*test01 = " << *test01 << endl;
	cout << "4:*test01 = " << *test01 << endl;
	
	// �ͷ�test01���ڴ棬��ʱ������test01�ͻᱨ��
	delete test01; 
	
	cout << "5:*test01 = " << *test01 << endl;
	cout << "6:*test01 = " << *test01 << endl;
	
	cout << "test02:" << endl;
	// ����forѭ����test02�����鸳ֵ 
	for(i=0; i<10; i++){
		test02[i] = i; 
	}
	
	for(i=0; i<10; i++){
		cout << "test02[" << i << "] = " << *(test02+i) << endl; 
	}
	
	delete[] test02; // �ͷ�test02���ڴ棬ע�⣺�ͷ�������ڴ�ʱ����Ҫ��delete�������[] 
	
	//��ʱ������test02�ͻᱨ��
	cout << endl;
	for(i=0; i<10; i++){
		cout << "test02[" << i << "] = " << *(test02+i) << endl; 
	}

	return 0;
	
}
