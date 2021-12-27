#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "globalFile.h"

using namespace std;

class OrderFileManager {
	public:
		// ���캯����ʵ�ֶ�ȡԤԼ����
		OrderFileManager();

		// ����order.txt�ļ��е�ԤԼ����
		void updateOrderFileFunc();

	public:

		int orderNum;	// ��¼order.txt�ļ��еļ�¼����

		map<int, map<string, string>> orderFileMap;

};