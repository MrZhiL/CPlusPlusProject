#pragma once	// ��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>

using namespace std;

/******* ��ݵĻ��� *********
 * ������ϵͳ�У���������ݣ��ֱ�Ϊ��ѧ��������ʦ�Լ�����Ա��
 * ����������乲��Ҳ�������ԣ�������ǿ��Խ�������ݳ���Ϊһ�������
 * ��ͷ�ļ��´���identity.h�ļ�
 */

// ��ݳ������
class Identity {
	public:

		// �����˵����麯�������������д�ú�����Ҫ��Ȼ����ҲΪ�������
		virtual void operMeun() = 0;

	public:
		string m_Name;	// �������
		//string m_Num;	// ��ݱ��
		string m_Pwd;	// ����
};