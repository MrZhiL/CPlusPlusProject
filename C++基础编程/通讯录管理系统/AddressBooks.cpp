#include "AddressBooks.h"

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

// 2����ʾ��ϵ�� 
void showPerson(struct AddressBooks *AdsBook){
	
	if(AdsBook->m_Size == 0){
		cout << "ͨѶ¼��û����ϵ��" << endl; 
	}else{
		cout << "��ϵ�˹���" <<  AdsBook->m_Size << "��: " << endl; 
		cout << "����" << "\t����" << "\t�Ա�" << "\t�绰" << "\t��ַ" << endl; 
		for(int i=0; i< AdsBook->m_Size ; i++){
			cout << AdsBook->personArray[i].m_Name  << "\t"
				 << AdsBook->personArray[i].m_Age   << "\t"
				 << AdsBook->personArray[i].m_Sex   << "\t"
				 << AdsBook->personArray[i].m_Phone << "\t"
				 << AdsBook->personArray[i].m_Addr  << "\t"
				 << endl;
			
		} 
	}
}

// 3��ɾ����ϵ�� 
void delPerson(struct AddressBooks *AdsBook){
	if(AdsBook->m_Size == 0){
		cout << "��ǰ��ϵ��Ϊ�գ�����ϵ�˿�ɾ" << endl; 
	} else {
		
		int num1 = 0;
		string name;
		cout << "������ɾ����ϵ��������";
		cin >> name;  
		
		for(int i=0;i<AdsBook->m_Size;i++){
			if (AdsBook->personArray[i].m_Name == name){
				num1++; 
				for (int j=i; j<AdsBook->m_Size-1; j++){
					AdsBook->personArray[j] = AdsBook->personArray[j+1];
				}
			}
		}

		if (num1==0){
			cout << "�޵�ǰ��ϵ�ˣ�ɾ��ʧ��" << endl;  
		}else{
			AdsBook->m_Size = AdsBook->m_Size-num1;
			cout << "ɾ���ɹ�����ɾ��" << num1 << "����ϵ�ˣ���ǰ��ϵ������Ϊ��" <<  AdsBook->m_Size << endl;
		}
		
	}
}

// 4��������ϵ��
void findPerson(struct AddressBooks *AdsBook){
	if(AdsBook->m_Size == 0){
		cout << "��ǰ��ϵ��Ϊ�գ�����ϵ�˿ɲ���" << endl; 
	} else {
		
		int num1=0; 
		string name;
		cout << "��������ҵ���ϵ��������";
		cin >> name;  
		
		cout << "����" << "\t����" << "\t�Ա�" << "\t�绰" << "\t��ַ" << endl; 
		for(int i=0;i<AdsBook->m_Size;i++){
			if (AdsBook->personArray[i].m_Name == name){
				num1++;
				cout << AdsBook->personArray[i].m_Name  << "\t"
					 << AdsBook->personArray[i].m_Age   << "\t"
					 << AdsBook->personArray[i].m_Sex   << "\t"
					 << AdsBook->personArray[i].m_Phone << "\t"
					 << AdsBook->personArray[i].m_Addr  << "\t"
					 << endl;
			}
		}
		cout << "���ҳɹ�������ϵ�˹���" << num1 << "�ˡ�" << endl; 
		cout << "��ǰͨѶ¼�е���ϵ��������" <<  AdsBook->m_Size << endl;
		
	}
}
// 5���޸���ϵ��
void modifyPerson(struct AddressBooks *AdsBook){
	if(AdsBook->m_Size == 0){
		cout << "��ǰ��ϵ��Ϊ�գ�����ϵ�˿��޸�" << endl; 
	} else {
		int i,num=0;
		string name;
		cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
		cin >> name;
		
		for(int i=0;i<AdsBook->m_Size;i++){
			if(name == AdsBook->personArray[i].m_Name){
				num++; 
				cout << "�޸ĺ��������" ;
				cin >> AdsBook->personArray[i].m_Name;
				
				cout << "�޸ĺ���Ա�(1����  2��Ů)��" ;
				int sex;
				cin >> sex;
				AdsBook->personArray[i].m_Sex = sex;
		
				while((sex != 1) && (sex != 2)) {
					cout << "�Ա����������������ϵ���Ա�(1����  2��Ů)��" ;
					cin >> sex;
					AdsBook->personArray[i].m_Sex = sex;
				}
				
				cout << "�޸ĺ�����䣺" ;
				cin >> AdsBook->personArray[i].m_Age;
				
				cout << "�޸ĺ�ĵ绰��" ;
				cin >> AdsBook->personArray[i].m_Phone ;
				
				cout << "�޸ĺ��ͥסַ��" ;
				cin >> AdsBook->personArray[i].m_Addr;
			}
			
			if (num==0)
				cout << "ͨѶ¼��û�д��ˣ��޷��޸ģ�" << endl; 
			else
				cout << "�޸ĳɹ�" << endl;
		}
	}
}
// 6�������ϵ��
void clearPerson(struct AddressBooks *AdsBook){
	if(AdsBook->m_Size == 0){
		cout << "��ǰ��ϵ��Ϊ�գ�����ϵ�˿�ɾ" << endl; 
	} else {
		AdsBook->m_Size = 0;
	}
}
