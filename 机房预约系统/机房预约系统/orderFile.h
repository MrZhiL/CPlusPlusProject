#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "globalFile.h"

using namespace std;

class OrderFileManager {
	public:
		// 构造函数，实现读取预约数据
		OrderFileManager();

		// 更新order.txt文件中的预约数据
		void updateOrderFileFunc();

	public:

		int orderNum;	// 记录order.txt文件中的记录条数

		map<int, map<string, string>> orderFileMap;

};