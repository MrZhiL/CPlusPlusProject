#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "identity.h"
#include "globalFile.h"
#include "teacher.h"
#include "student.h"
#include "computerRoom.h"

using namespace std;

/******* ����Ա��Ĵ��� *********
 * ����Ա����Ҫ�����Ƕ�ѧ������ʦ�˻����й����鿴������Ϣ�Լ����ԤԼ��¼
 * ����Ա���е���Ҫ�����У�
 * ��ʾ����Ա�����Ĳ˵�����
 * ����˺�
 * �鿴�˺�
 * �鿴������Ϣ
 * ���ԤԼ��¼
 */

class Manager : public Identity {
	public:
		// Ĭ�Ϲ��캯��
		Manager();

		// �вι��캯��
		Manager(string name, string pwd);

		// ��ʾ�˵����溯��
		virtual void operMeun();

		// ����˺ź���
		void addPerson();

		// �鿴�˺ź���
		void showPerson();

		// �鿴������Ϣ
		void showComputer();

		// ���ԤԼ��¼
		void clearFile();

		// ��ʼ����ʦ��ѧ������
		void initVector();

		// ����ظ�������1��ѧ��/ְ���ţ� ����2���������
		bool checkRepeat(int id, int type);

	public:

		// ѧ������
		vector<Student> vStu;
		// ��ʦ����
		vector<Teacher> vTea;

		// ������Ż�������Ϣ
		vector<ComputerRoom> vCom;
		
};