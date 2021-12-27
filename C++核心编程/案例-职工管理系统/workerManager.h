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

/** 1�����������ࣺ*******
  *���û��Ĺ�ͨ�˵����桢
  *��ְ����ɾ�Ĳ�Ĳ�����
  *���ļ��Ķ�д���� 
  *********************
  */

class WorkerManager{
	public:
		// ���캯�� 
		WorkerManager();
		
		// ְ������ϵͳ�������� 
		void showMenu();
		
		// �˳�ְ������ϵͳ 
		void ExitSystem();
		
		// ���ְ������
		void addEmp();
		
		// ְ������ 
		int  m_EmpNum;
		
		// �����ļ�����
		void save(); 
		
		// �ж��ļ��Ƿ���� ��־������trueΪ�����ڣ�falseΪ���� 
		bool m_FileIsEmpty; 
		
		// ͳ���ļ��е�����
		int getEmpNum(); 
		
		// ��ʼ������
		void InitEmpArray(); 
		
		// ��ʾְ��
		void show_Emp(); 
		
		// ɾ��ְ��
		void del_Emp(); 
		
		// �ж�ְ���Ƿ����,������ڷ�������λ�ã�����������򷵻�-1 
		int workerIsExit();
		
		// �޸�ְ����Ϣ 
		void Mod_Emp();
		
		// ����ְ����Ϣ 
		void Find_Emp();
		
		// ��ְ����������
		void Sort_Emp(); 
		
		// ��������
		void Emp_swap(Worker *, Worker *); 
		
		// �����������
		void ClearAll_Emp(); 
		
		// ���ְ����Ϣ������ 
		Worker **m_EmpArray; 
		
		// �������� 
		~WorkerManager();
}; 

#endif /**_WORKERMANAGER_H*/
