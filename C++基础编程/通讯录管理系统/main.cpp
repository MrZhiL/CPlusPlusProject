/*********************************************************************************************** 
 *	��Ŀ���� :  ͨѶ¼����ϵͳ
 *  copyright:  Mr.Zhi 
 *  date     :  2020-08-02
 *  
 ***********************************************************************************************
 * ͨѶ¼����ϵͳ - ϵͳ���� 
 * �����ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ����(�������Ա����䡢��ϵ�绰����ͥסַ)����¼1000�� 
 * ��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ 
 * ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
 * ������ϵ�ˣ����������鿴ָ����ϵȻ��Ϣ 
 * �޸���ϵ�ˣ��������������޸�ָ����ϵ�� 
 * �����ϵ�ˣ����ͨѶ¼��������Ϣ 
 * �˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼ 
 *************************************************************************************************
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "AddressBooks.h"

using namespace std;

int main() {
	
	// ����ͨѶ¼�ṹ����� 
	struct AddressBooks AdsBook; 
	
	// ΪͨѶ¼�����ڴ�ռ䣬��ֹ���ֶδ��� 
//	AdsBook = (struct AddressBooks *)malloc(sizeof(struct AddressBooks)); 
//	AdsBook->personArray = (struct Person *)malloc(sizeof(struct Person)*m_MAX);

	AdsBook.m_Size = 0;
	// �����û�ѡ����� 
	int select = 0;
	
	while(1){

		// ��ʾ�˵� 
		showMenu();
		
		cout << "Please input your action:";
		cin >> select;
		
		// ʹ��switvh������ж��û��Ķ��� 
		switch(select){
			
			// 1�������ϵ��
			case 1:
				addPerson(&AdsBook); // ���õ�ַ���ݿ�������ʵ�� 
				break;
			// 2����ʾ��ϵ��
			case 2:
				showPerson(&AdsBook);
				break;
			// 3��ɾ����ϵ��
			case 3:
				delPerson(&AdsBook);
				break;
			// 4��������ϵ��
			case 4:
				findPerson(&AdsBook);
				break;
			// 5���޸���ϵ��
			case 5:
				modifyPerson(&AdsBook);
				break;
			// 6�������ϵ��
			case 6:
				clearPerson(&AdsBook);
				break;
			// 0���˳�ͨѶ¼
			case 0:
				
				system("pause");
				return 0;
				break;
			default:
				break;
		}
		
	} 
	
//	free(AdsBook->personArray);
//	free(AdsBook);
	
	system("pause");
	return 0;
}

