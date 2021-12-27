#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "orderFile.h"
#include "identity.h"

using namespace std;

/* * * * * 老师类的创建 * * * * *
 * 教师类主要功能是查看学生的预约，并进行审核
 * 教师类中主要功能有：
 * 显示教师操作的菜单界面
 * 查看所有预约
 * 审核预约
 * * * * * * * * * * * * * * * * * * *
 */

class Teacher : public Identity {
	public:

		// 默认构造函数
		Teacher();

		// 有参构造函数
		Teacher(int id, string name, string pwd);

		// 显示菜单界面函数
		virtual void operMeun();

		// 查看所有预约函数
		void showAllOrder();

		// 审核预约函数
		void validOrder();

	public:
		int m_EmpId;	// 教师职工编号
};