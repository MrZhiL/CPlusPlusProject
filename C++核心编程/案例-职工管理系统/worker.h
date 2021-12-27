#include <iostream>
#include <string>
using namespace std;

#ifndef _WORKER_H
#define _WORKER_H

/***************************
 *  创建职工抽象类
 * 职工的分类为：普通员工、经理、老板
 * 将三种职工抽象到一个类（worker），利用多态管理不同职工种类 
 * 职工的属性为：职工编号、职工姓名、职工所在部门编号 
 * 职工的行为：岗位职责信息描述，获取岗位名称 
 **************************** 
 */ 
 
class Worker{
	
	public:
		
		// 显示职工信息 
		virtual void showInfo() = 0; 
		
		// 显示职工岗位
		virtual string showDepart() = 0; 
		
		int m_Num; 		// 职工编号
		string m_Name;  // 职工姓名
		int m_Depart;   // 职工所在部门编号 
	
}; 

#endif /*_WORKER_H*/
