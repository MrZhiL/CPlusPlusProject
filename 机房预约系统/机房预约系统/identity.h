#pragma once	// 防止头文件重复包含
#include<iostream>
#include<string>

using namespace std;

/******* 身份的基类 *********
 * 在整个系统中，有三种身份，分别为：学生代表、老师以及管理员；
 * 三种身份有其共性也有其特性，因此我们可以将三种身份抽象为一个身份类
 * 在头文件下创建identity.h文件
 */

// 身份抽象基类
class Identity {
	public:

		// 创建菜单纯虚函数，子类必须重写该函数，要不然子类也为抽象基类
		virtual void operMeun() = 0;

	public:
		string m_Name;	// 身份姓名
		//string m_Num;	// 身份编号
		string m_Pwd;	// 密码
};