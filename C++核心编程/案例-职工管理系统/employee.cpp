#include "employee.h"

employee::employee(int num, string name, int depa){
	this->m_Num = num;
	this->m_Name = name;
	this->m_Depart = depa;
}

// ��д��ʾְ����Ϣ���� 
void employee::showInfo(){
	cout << "ְ����ţ�" << this->m_Num
	     << "\tְ��������" << this->m_Name
	     << "\t��λ��" << this->showDepart()
		 << "\t��λְ����ɾ�����������" << endl; 
}

// ��д��ʾְ����λ���� 
string employee::showDepart(){
	return string("Ա��");
}  
