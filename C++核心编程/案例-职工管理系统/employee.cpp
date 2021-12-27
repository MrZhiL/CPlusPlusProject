#include "employee.h"

employee::employee(int num, string name, int depa){
	this->m_Num = num;
	this->m_Name = name;
	this->m_Depart = depa;
}

// 重写显示职工信息函数 
void employee::showInfo(){
	cout << "职工编号：" << this->m_Num
	     << "\t职工姓名：" << this->m_Name
	     << "\t岗位：" << this->showDepart()
		 << "\t岗位职责：完成经理交给的任务" << endl; 
}

// 重写显示职工岗位函数 
string employee::showDepart(){
	return string("员工");
}  
