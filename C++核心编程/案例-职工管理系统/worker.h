#include <iostream>
#include <string>
using namespace std;

#ifndef _WORKER_H
#define _WORKER_H

/***************************
 *  ����ְ��������
 * ְ���ķ���Ϊ����ͨԱ���������ϰ�
 * ������ְ������һ���ࣨworker�������ö�̬����ְͬ������ 
 * ְ��������Ϊ��ְ����š�ְ��������ְ�����ڲ��ű�� 
 * ְ������Ϊ����λְ����Ϣ��������ȡ��λ���� 
 **************************** 
 */ 
 
class Worker{
	
	public:
		
		// ��ʾְ����Ϣ 
		virtual void showInfo() = 0; 
		
		// ��ʾְ����λ
		virtual string showDepart() = 0; 
		
		int m_Num; 		// ְ�����
		string m_Name;  // ְ������
		int m_Depart;   // ְ�����ڲ��ű�� 
	
}; 

#endif /*_WORKER_H*/
