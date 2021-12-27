#pragma once
#include "worker.h"

#ifndef _MANAGER_H
#define _MANAGER_H

/*该文件中为经理的类，用于显示和记录员工信息*/ 

class manager : public Worker{
	public:
		manager(int num, string name, int depa);
		
		// 重写显示职工信息函数 
		virtual void showInfo(); 
		
		// 重写显示职工岗位函数 
		virtual string showDepart(); 
		
		~manager();

}; 

#endif /*_MANAGER_H*/
