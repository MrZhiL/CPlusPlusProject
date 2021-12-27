#include <iostream>
#include <fstream>
#include "speechManager.h" 
#include <string>
#include <ctime> 

using namespace std;

// 演讲比赛流程管理系统 

void testCreatreSpeaker(const speechManager &sp){
	// 打印选手信息 
	for(map<int, Speaker>::const_iterator it = sp.m_Speaker.begin(); it != sp.m_Speaker.end(); it++){
		cout << "选手的编号为：" << it->first
			 << ",  选手的姓名为：" << it->second.m_Name 
			 << ",  选手的成绩为：" << it->second.m_Score[0]
			 << endl;
	}
}

int main(int argc, char** argv) {
	
	srand((unsigned int)time(NULL));
	
	speechManager speechMan;
	
	//// 测试选手是否创建成功 
	//testCreatreSpeaker(speechMan);
	
	// 案件选择	
	int swit_num;
	
	while (true){
		
		// 显示菜单界面 
		speechMan.show_Menu();
		
		// 判断用户的输入，并作出相应的操作 
		cout << "请输入要操作的选项：";
		cin >> swit_num;
		
		while(swit_num > 3 || swit_num < 0){
			cout << "输入错误!请重新输入(0-3):";
			cin >> swit_num; 
		} 
		 
		switch(swit_num){
			// 1：开始比赛 
			case 1:
				speechMan.startSpeech();
				break;
			// 2：查看往届比赛记录 
			case 2:
				speechMan.showRecord();
				break;
			// 3：清空比赛记录 
			case 3:
				speechMan.clearRecore();
				break;
			// 0：退出比赛系统 
			case 0: 
				speechMan.exitSystem();
				break;
			// 其余操作清屏 
			default:
				system("cls");
				break;	
		}
	}
	
	
	system("pause");
	return 0;
}
