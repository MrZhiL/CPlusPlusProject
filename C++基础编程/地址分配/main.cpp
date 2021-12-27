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
#define m_MAX 1000 

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

void addPerson(struct AddressBooks *AdsBook);
void showMenu(); 

int main() {
	
	// ����ͨѶ¼�ṹ����� 
	struct AddressBooks *AdsBook; 
	
	// ΪͨѶ¼�����ڴ�ռ䣬��ֹ���ֶδ��� 
	AdsBook = (struct AddressBooks *)malloc(sizeof(struct AddressBooks)); 
	AdsBook->personArray = (struct Person *)malloc(sizeof(struct Person)*m_MAX);

	AdsBook->m_Size = 0;
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
				addPerson(AdsBook); // ���õ�ַ���ݿ�������ʵ�� 
				break;
			// 2����ʾ��ϵ��
			case 2:
				//showPerson(&AdsBook);
				break;
			// 3��ɾ����ϵ��
			case 3:
				//delPerson(&AdsBook);
				break;
			// 4��������ϵ��
			case 4:
				//findPerson(&AdsBook);
				break;
			// 5���޸���ϵ��
			case 5:
				//modifyPerson(&AdsBook);
				break;
			// 6�������ϵ��
			case 6:
				//clearPerson(&AdsBook);
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

// 0--��װ������ʾ�ý���
void showMenu(){
	
	cout << "*************************" << endl; 
	cout << "***** 1�������ϵ�� *****" << endl; 
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

// 1--�����ϵ�˺��� 
void addPerson(struct AddressBooks *AdsBook){
	
	if (AdsBook->m_Size > m_MAX){
		cout << "ͨѶ¼����1000���޷����" << endl;
		return ; 
	}else{
		string name;
		cout << "��������ϵ��������" ;
		cin >>  AdsBook->personArray[AdsBook->m_Size].m_Name;
		
		cout << "��������ϵ���Ա�(1����  2��Ů)��" ;
		int sex;
		cin >> sex;
		AdsBook->personArray[AdsBook->m_Size].m_Sex = sex;

		while((sex != 1) && (sex != 2)) {
			cout << "�Ա����������������ϵ���Ա�(1����  2��Ů)��" ;
			cin >> sex;
			AdsBook->personArray[AdsBook->m_Size].m_Sex = sex;
		}
		
		cout << "��������ϵ�����䣺" ;
		cin >> AdsBook->personArray[AdsBook->m_Size].m_Age;
		
		cout << "��������ϵ�˵绰��" ;
		string phone; 
		cin >> phone;
		AdsBook->personArray[AdsBook->m_Size].m_Phone = phone;
		
		cout << "��������ϵ�˼�ͥסַ��" ;
		string addr;
		cin >> addr;
		AdsBook->personArray[AdsBook->m_Size].m_Addr = addr;
		
		// ÿ���һ����ϵ�ˣ�ͨѶ¼�е�������1 
		AdsBook->m_Size++ ;
	//	AdsBook->personArray; 	
	}
	cout << "��ǰͨѶ¼�е���ϵ��������" <<  AdsBook->m_Size << endl;
	
	system("pause"); 
	// �������� 
	system("cls"); 
} 


