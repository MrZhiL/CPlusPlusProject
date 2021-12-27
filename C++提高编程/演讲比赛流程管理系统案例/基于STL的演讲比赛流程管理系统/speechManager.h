#pragma once	//防止头文件重复编译和重复包含 
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


// 创建管理类：
// 1、提供菜单界面与用户交互
// 2、对演讲比赛流程进行控制
// 3、与文件的读写操作 

// 功能分析：抽签-开始演讲比赛-显示第一轮比赛结果
//           抽签-开始演讲比赛-显示前三名结果-保存分数 

class speechManager{
	
	// 函数的声明 
	public:
		
		// 构造函数声明，实现在.cpp文件中 
		speechManager();
		
		
		// 菜单功能实现（与用户的沟通界面）
		void show_Menu(); 
		
		/** 测试菜单功能 */ 
		
		// 初始化选手函数 
		void initSpeech();
		
		// 创建选手
		void createSpeaker();
		
		// 开始比赛函数,该函数功能主要为控制比赛的流程 
		void startSpeech(); 
		
		// 选手抽签函数
		void speechDraw();
		
		// 比赛函数
		void speechContest();
		
		// 显示比赛分数 
		void showScore(); 
		
		// 保存分数
		void saveRecord();
		
		// 获取往届记录
		void loadRecord(); 
		
		// 查看往届记录
		void showRecord(); 
		
		// 清空文件中的所有数据
		void clearRecore(); 
		
		// 退出功能（实现退出程序） 
		void exitSystem(); 
		
		// 析构函数 
		~speechManager();
	
	// 变量和选手的创建 
	public:
		// 成员属性添加
		
		vector<int> v1;  	//比赛选手-容器-12人 
		vector<int> v2; 	//第一轮晋级选手-容器-6人 
		vector<int> vVector;//第二轮晋级选手-容器-3人
		
		// 该容器用来存放编号和对应的具体选手
		map<int, Speaker> m_Speaker;
		
		// 该值用来记录比赛轮数
		int m_Index; 
		
		// 判断为文件是否为空标准
		bool fileIsEmpty; 
		
		// record_Speech用来保存往届的记录 
		map<int, vector<string> > record_Speech; 
		 
		
}; 

