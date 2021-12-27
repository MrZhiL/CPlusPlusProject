#pragma once
#include "worker.h"

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H 

/*该文件中为员工的类，用于显示和记录员工信息*/ 

class employee : public Worker{
	public:
		employee(int num, string name, int depa);
		
		// 重写显示职工信息函数 
		virtual void showInfo(); 
		
		// 重写显示职工岗位函数 
		virtual string showDepart(); 
		
		~employee();

}; 

#endif /*_EMPLOYEE_H*/
