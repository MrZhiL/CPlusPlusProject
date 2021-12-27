#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "computerRoom.h"
#include "globalFile.h"
#include "identity.h"
#include "orderFile.h"

using namespace std;

/* * * * * ѧ����Ĵ��� * * * * *
 * ѧ������Ҫ�����ǿ���ͨ�����г�Ա������ʵ��ԤԼʵ���ҵĲ���
 * ѧ��������Ҫ�����У�
 * ��ʾѧ�������Ĳ˵�����
 * ����ԤԼ
 * �鿴����ԤԼ
 * �鿴����ԤԼ
 * ȡ��ԤԼ
 * * * * * * * * * * * * * * * * * * * 
 */

//����ѧ����
class Student : public Identity {

	public:
		// Ĭ�Ϲ��캯��
		Student();
		
		// �вι��캯��, ������ѧ�š�����������
		Student(int id, string name, string pwd);

		// �����˵����麯�������������д�ú�����Ҫ��Ȼ����ҲΪ�������
		virtual void operMeun();

		// ԤԼ����
		void applyOrder();

		// ��ʾ����ԤԼ����
		void showMyOrder();

		// ��ʾ����ԤԼ����
		void showAllOrder();

		// ȡ��ԤԼ����
		void cancelOrder();


	public:
		int m_id;	// ѧ����id��

		// vComDemo������¼��������Ϣ
		vector<ComputerRoom> vComDemo;

};