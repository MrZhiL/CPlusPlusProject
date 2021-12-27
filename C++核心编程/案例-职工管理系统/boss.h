#pragma once
#include "worker.h"

#ifndef _BOSS_H
#define _BOSS_H

/*该文件中为l老板的类，用于显示和记录员工信息*/ 

class boss : public Worker{
	public:
		boss(int num, string name, int depa);
		
		// 重写显示职工信息函数 
		virtual void showInfo(); 
		
		// 重写显示职工岗位函数 
		virtual string showDepart(); 
		
		~boss();

}; 

#endif /*_BOSS_H*/
