#pragma once
#include "worker.h"

#ifndef _BOSS_H
#define _BOSS_H

/*���ļ���Ϊl�ϰ���࣬������ʾ�ͼ�¼Ա����Ϣ*/ 

class boss : public Worker{
	public:
		boss(int num, string name, int depa);
		
		// ��д��ʾְ����Ϣ���� 
		virtual void showInfo(); 
		
		// ��д��ʾְ����λ���� 
		virtual string showDepart(); 
		
		~boss();

}; 

#endif /*_BOSS_H*/
