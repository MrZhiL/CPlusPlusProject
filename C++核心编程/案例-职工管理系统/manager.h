#pragma once
#include "worker.h"

#ifndef _MANAGER_H
#define _MANAGER_H

/*���ļ���Ϊ������࣬������ʾ�ͼ�¼Ա����Ϣ*/ 

class manager : public Worker{
	public:
		manager(int num, string name, int depa);
		
		// ��д��ʾְ����Ϣ���� 
		virtual void showInfo(); 
		
		// ��д��ʾְ����λ���� 
		virtual string showDepart(); 
		
		~manager();

}; 

#endif /*_MANAGER_H*/
