#pragma once
#include "worker.h"

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H 

/*���ļ���ΪԱ�����࣬������ʾ�ͼ�¼Ա����Ϣ*/ 

class employee : public Worker{
	public:
		employee(int num, string name, int depa);
		
		// ��д��ʾְ����Ϣ���� 
		virtual void showInfo(); 
		
		// ��д��ʾְ����λ���� 
		virtual string showDepart(); 
		
		~employee();

}; 

#endif /*_EMPLOYEE_H*/
