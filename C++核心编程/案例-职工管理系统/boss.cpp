#include "boss.h"

boss::boss(int num, string name, int depa){
	this->m_Num = num;
	this->m_Name = name;
	this->m_Depart = depa;
}

// ��д��ʾְ����Ϣ���� 
void boss::showInfo(){
	cout << "ְ����ţ�" << this->m_Num
	     << "\tְ��������" << this->m_Name
	     << "\t��λ��" << this->showDepart()
		 << "\t��λְ�𣺹���˾��ְ��" << endl; 
}

// ��д��ʾְ����λ���� 
string boss::showDepart(){
	return string("�ϰ�");
}  
