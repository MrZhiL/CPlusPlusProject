#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#ifndef _WORKERMANAGER_H
#define _WORKERMANAGER_H

#define FILENAME "empFile.txt"

using namespace std;

/** 1、创建管理类：*******
  *与用户的沟通菜单界面、
  *对职工增删改查的操作、
  *与文件的读写交互 
  *********************
  */

class WorkerManager{
	public:
		// 构造函数 
		WorkerManager();
		
		// 职工管理系统操作界面 
		void showMenu();
		
		// 退出职工管理系统 
		void ExitSystem();
		
		// 添加职工函数
		void addEmp();
		
		// 职工人数 
		int  m_EmpNum;
		
		// 保存文件函数
		void save(); 
		
		// 判断文件是否存在 标志变量：true为不存在，false为存在 
		bool m_FileIsEmpty; 
		
		// 统计文件中的人数
		int getEmpNum(); 
		
		// 初始化数组
		void InitEmpArray(); 
		
		// 显示职工
		void show_Emp(); 
		
		// 删除职工
		void del_Emp(); 
		
		// 判断职工是否存在,如果存在返回所在位置，如果不存在则返回-1 
		int workerIsExit();
		
		// 修改职工信息 
		void Mod_Emp();
		
		// 查找职工信息 
		void Find_Emp();
		
		// 对职工进行排序
		void Sort_Emp(); 
		
		// 交换函数
		void Emp_swap(Worker *, Worker *); 
		
		// 清空所有数据
		void ClearAll_Emp(); 
		
		// 存放职工信息的数组 
		Worker **m_EmpArray; 
		
		// 析构函数 
		~WorkerManager();
}; 

#endif /**_WORKERMANAGER_H*/
