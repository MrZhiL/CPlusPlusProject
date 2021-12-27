#pragma once
#include<iostream>

using namespace std;

// 功能分析：抽签-开始演讲比赛-显示第一轮比赛结果
//           抽签-开始演讲比赛-显示前三名结果-保存分数 

// 创建选手类
class Speaker{
	public:
		string m_Name;		//选手姓名
		double m_Score[2];	//分数：因为有两轮比赛，所有创建数组 
};


