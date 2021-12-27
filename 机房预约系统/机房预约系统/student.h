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

/* * * * * 学生类的创建 * * * * *
 * 学生类主要功能是可以通过类中成员函数，实现预约实验室的操作
 * 学生类中主要功能有：
 * 显示学生操作的菜单界面
 * 申请预约
 * 查看自身预约
 * 查看所有预约
 * 取消预约
 * * * * * * * * * * * * * * * * * * * 
 */

//创建学生类
class Student : public Identity {

	public:
		// 默认构造函数
		Student();
		
		// 有参构造函数, 参数：学号、姓名、密码
		Student(int id, string name, string pwd);

		// 创建菜单纯虚函数，子类必须重写该函数，要不然子类也为抽象基类
		virtual void operMeun();

		// 预约函数
		void applyOrder();

		// 显示自身预约函数
		void showMyOrder();

		// 显示所有预约函数
		void showAllOrder();

		// 取消预约函数
		void cancelOrder();


	public:
		int m_id;	// 学生的id号

		// vComDemo用来记录机房的信息
		vector<ComputerRoom> vComDemo;

};