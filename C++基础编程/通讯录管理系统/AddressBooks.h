#include <iostream>
#include <string>
#include <stdlib.h>

#define m_MAX 1000

#ifndef ADDRESSBOOKS_H
#define ADDRESSBOOKS_H

using namespace std;

// ������ϵ�˽ṹ�� ��Ϣ����(�������Ա����䡢��ϵ�绰����ͥסַ)
struct Person{
	
	string m_Name;	// ���� 
	int m_Sex;		// �Ա� ��1���� 2��Ů ������Ч�� 
	int m_Age;		// ���� 
	string m_Phone;	// ��ϵ�绰 
	string m_Addr;	// ��ͥסַ 
};

// ����ͨѶ¼�ṹ�� (����¼1000��)
struct AddressBooks{
	
	// ͨѶ¼�б������ϵ������ 
	struct Person personArray[m_MAX];
	
	// ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ��� 
	int m_Size;
	
};


// 0���˵����溯�� 
void showMenu();
// 1�������ϵ�� 
void addPerson(struct AddressBooks *); 
// 2����ʾ��ϵ�� 
void showPerson(struct AddressBooks *); 
// 3��ɾ����ϵ��
void delPerson(struct AddressBooks *); 
// 4��������ϵ��
void findPerson(struct AddressBooks *);
// 5���޸���ϵ��
void modifyPerson(struct AddressBooks *);
// 6�������ϵ��
void clearPerson(struct AddressBooks *);

#endif /*ADDRESSBOOKS_H*/ 
