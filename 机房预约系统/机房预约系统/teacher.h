#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "orderFile.h"
#include "identity.h"

using namespace std;

/* * * * * ��ʦ��Ĵ��� * * * * *
 * ��ʦ����Ҫ�����ǲ鿴ѧ����ԤԼ�����������
 * ��ʦ������Ҫ�����У�
 * ��ʾ��ʦ�����Ĳ˵�����
 * �鿴����ԤԼ
 * ���ԤԼ
 * * * * * * * * * * * * * * * * * * *
 */

class Teacher : public Identity {
	public:

		// Ĭ�Ϲ��캯��
		Teacher();

		// �вι��캯��
		Teacher(int id, string name, string pwd);

		// ��ʾ�˵����溯��
		virtual void operMeun();

		// �鿴����ԤԼ����
		void showAllOrder();

		// ���ԤԼ����
		void validOrder();

	public:
		int m_EmpId;	// ��ʦְ�����
};