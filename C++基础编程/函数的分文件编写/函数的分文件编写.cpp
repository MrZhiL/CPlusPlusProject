#include<iostream>
#include "swap_zhi.h"

using namespace std; 

/********************************* 
 * �����ķ��ļ���д��
 * ���ã��ô���ṹ��Ϊ����
 * �����ļ���дһ����4�����裺
 * 1.������׺��Ϊ.h��ͷ�ļ� 
 * 2.������׺��Ϊ.cpp��Դ�ļ� 
 * 3.��ͷ�ļ���д���������� 
 * 4.��Դ�ļ���д�����Ķ��� 
 **************************************** 
 */
 
// �����ķ��ļ���д
// ʵ���������ֽ��н����ĺ���

/**
// ���������� 
void swap(int a, int b); */

int main(){
	
	int a = 10;
	int b = 20;
	
	cout << "����ǰ��" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; 
	
	aaa(a,b);
	
	system("pause");
	
	return 0;
	
} 

/**
// �����Ķ��� 
int swap(int a, int b){
	
	// ������ʱ���� 
	int temp;
	
	temp = a;
	a = b;
	b = temp;
	
	cout << "������" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; 
		
} */ 

