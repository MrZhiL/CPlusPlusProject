#include "manager.h"

manager::manager(int num, string name, int depa){
	this->m_Num = num;
	this->m_Name = name;
	this->m_Depart = depa;
}

// ��д��ʾְ����Ϣ���� 
void manager::showInfo(){
	cout << "ְ����ţ�" << this->m_Num
	     << "\tְ��������" << this->m_Name
	     << "\t��λ��" << this->showDepart()
		 << "\t��λְ������ϰ彻��������" << endl; 
}

// ��д��ʾְ����λ���� 
string manager::showDepart(){
	return string("����");
}  
