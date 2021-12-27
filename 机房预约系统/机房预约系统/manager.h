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

/******* 管理员类的创建 *********
 * 管理员类主要功能是对学生和老师账户进行管理，查看机房信息以及清空预约记录
 * 管理员类中的主要功能有：
 * 显示管理员操作的菜单界面
 * 添加账号
 * 查看账号
 * 查看机房信息
 * 清空预约记录
 */

class Manager : public Identity {
	public:
		// 默认构造函数
		Manager();

		// 有参构造函数
		Manager(string name, string pwd);

		// 显示菜单界面函数
		virtual void operMeun();

		// 添加账号函数
		void addPerson();

		// 查看账号函数
		void showPerson();

		// 查看机房信息
		void showComputer();

		// 清空预约记录
		void clearFile();

		// 初始化教师和学生容器
		void initVector();

		// 检测重复，参数1：学号/职工号； 参数2：检测类型
		bool checkRepeat(int id, int type);

	public:

		// 学生容器
		vector<Student> vStu;
		// 老师容器
		vector<Teacher> vTea;

		// 用来存放机房的信息
		vector<ComputerRoom> vCom;
		
};