#pragma once	//��ֹͷ�ļ��ظ�������ظ����� 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <map>
#include <numeric> 

#include "speaker.h"

using namespace std;


// ���������ࣺ
// 1���ṩ�˵��������û�����
// 2�����ݽ��������̽��п���
// 3�����ļ��Ķ�д���� 

// ���ܷ�������ǩ-��ʼ�ݽ�����-��ʾ��һ�ֱ������
//           ��ǩ-��ʼ�ݽ�����-��ʾǰ�������-������� 

class speechManager{
	
	// ���������� 
	public:
		
		// ���캯��������ʵ����.cpp�ļ��� 
		speechManager();
		
		
		// �˵�����ʵ�֣����û��Ĺ�ͨ���棩
		void show_Menu(); 
		
		/** ���Բ˵����� */ 
		
		// ��ʼ��ѡ�ֺ��� 
		void initSpeech();
		
		// ����ѡ��
		void createSpeaker();
		
		// ��ʼ��������,�ú���������ҪΪ���Ʊ��������� 
		void startSpeech(); 
		
		// ѡ�ֳ�ǩ����
		void speechDraw();
		
		// ��������
		void speechContest();
		
		// ��ʾ�������� 
		void showScore(); 
		
		// �������
		void saveRecord();
		
		// ��ȡ�����¼
		void loadRecord(); 
		
		// �鿴�����¼
		void showRecord(); 
		
		// ����ļ��е���������
		void clearRecore(); 
		
		// �˳����ܣ�ʵ���˳����� 
		void exitSystem(); 
		
		// �������� 
		~speechManager();
	
	// ������ѡ�ֵĴ��� 
	public:
		// ��Ա�������
		
		vector<int> v1;  	//����ѡ��-����-12�� 
		vector<int> v2; 	//��һ�ֽ���ѡ��-����-6�� 
		vector<int> vVector;//�ڶ��ֽ���ѡ��-����-3��
		
		// ������������ű�źͶ�Ӧ�ľ���ѡ��
		map<int, Speaker> m_Speaker;
		
		// ��ֵ������¼��������
		int m_Index; 
		
		// �ж�Ϊ�ļ��Ƿ�Ϊ�ձ�׼
		bool fileIsEmpty; 
		
		// record_Speech������������ļ�¼ 
		map<int, vector<string> > record_Speech; 
		 
		
}; 

