#include "speechManager.h"


// 构造函数
speechManager::speechManager(){
	this->initSpeech();		// 初始化选手容器
	this->createSpeaker();	// 创建选手 
	this->loadRecord();		// 读取文件中的数据 
}


// 菜单功能实现（与用户的沟通界面）
void speechManager::show_Menu(){
	cout << "********************************" << endl;
	cout << "******* 欢迎参加演讲比赛 *******" << endl;
	cout << "******* 1、开始演讲比赛  *******" << endl; 
	cout << "******* 2、查看往届记录  *******" << endl; 
	cout << "******* 3、清空比赛记录  *******" << endl; 
	cout << "******* 0、退出比赛程序  *******" << endl; 
	cout << endl; 
}

// 初始化选手函数 
void speechManager::initSpeech(){
	// 清空容器中的所有数据，确保初始化后容器为空 
	this->v1.clear();
	this->v2.clear();
	this->vVector.clear();
	
	this->m_Speaker.clear();
	
	// 初始化后比赛为第一轮
	this->m_Index = 1; 
	
	// 初始化选手记录容器
	this->record_Speech.clear();
}

// 创建12名选手
void speechManager::createSpeaker(){
	
	string nameSeed = "ABCDEFJHIGKL";	//选手姓名种子
	
	for(int i=0; i<12; i++){
		
		Speaker sp;	// 创建选手类
		string name = "选手";
		sp.m_Name += nameSeed[i];
		
		// 初始化选手的成绩为0 
		for(int j=0; j<2; j++){
			sp.m_Score[j] = 0;
		}		
		
		// 给选手赋予不同的编号
		this->v1.push_back(i+10001);
		
		// 将编号和对应的具体选手联系在一起
		this->m_Speaker.insert(make_pair(i+10001, sp)); 
	} 
	
}

// 开始比赛函数,该函数功能主要为控制比赛的流程
// 比赛的流程为： 
void speechManager::startSpeech(){
	
	/**第一轮比赛*/ 
	
	// 1、抽签
	this->speechDraw(); 
	
	// 2、比赛
	this->speechContest();
	
	// 3、显示晋级结果
	this->showScore();
	
	/**第二轮比赛*/ 
	this->m_Index++;
	
	// 1、抽签
	this->speechDraw();
	
	// 2、比赛
	this->speechContest();
	
	// 3、显示最终结果 
	this->showScore();
	
	// 4、保存分数
	this->saveRecord(); 
	
	// 重置比赛和选手
	this->initSpeech();		// 初始化选手容器
	this->createSpeaker();	// 创建选手 
	this->loadRecord();		// 读取文件中的数据 

	cout << "本届比赛完成@" << endl;
	system("pause");
	system("cls"); 
	
}

// 选手抽签函数
void speechManager::speechDraw(){
	
	//提示用户为第几轮抽签
	cout << "第" << this->m_Index << "轮比赛用户抽签！" << endl;
	cout << "----------------------------------------------" << endl;
	
	if(this->m_Index == 1){
		cout << "第一轮抽签后的顺序为：" << endl; 
		random_shuffle(v1.begin(), v1.end());
		for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
			cout << *it << "   ";
		}
		cout << endl;
	} else{
		cout << "第二轮抽签后的顺序为：" << endl; 
		random_shuffle(v2.begin(), v2.end());
		for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
			cout << *it << "   ";
		}
		cout << endl;
	}
	cout << "----------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

// 比赛函数
void speechManager::speechContest(){
	
	cout << "---------- 第" << this->m_Index << "轮比赛开始！----------" << endl;
	cout << "-------------------------------------------" << endl;
	
	// num用来记录当前选手的数量 
	int num = 0; 
	
	// 创建临时容器，用来保存选手的编号和对应的成绩 
	multimap<double, int, greater<double> > groupvect;
	
	// 创建容vTmep器，用来记录比赛选手的信息 
	vector<int> vTmep; 
	
	if(this->m_Index == 1){
		vTmep = v1;
	} else {
		vTmep = v2;
	}
	
	// 该for循环用来判断选手的成绩,遍历所有参赛选手 
	for(vector<int>::iterator it = vTmep.begin(); it != vTmep.end(); it++){
		
		// deqScore用来记录选手的成绩 
		deque<double> deqScore;
		
		num++; 
		
		// 判断选手的成绩，共有10位评委，评委打分为60.0-100.0分 
		for(int i=0; i<10; i++){
			double score = (rand()%400+600)/10.f;
			deqScore.push_back(score);		//评委打分成绩 
			//cout << score << endl;
		} 
		// 对10位评委的打分进行降序排序 
		sort(deqScore.begin(), deqScore.end(), greater<double>());
		
		// 去除最高分和最低分
		deqScore.pop_back();
		deqScore.pop_front();
		
		// 计算去除最高分和最低分后的平均分
		double aveScore = accumulate(deqScore.begin(), deqScore.end(), 0.0f) / (double)deqScore.size();	//accumulate函数在numeric头文件中 
		//cout << "选手" << *it << " 的平均成绩为：" << aveScore << endl;
		
		this->m_Speaker[*it].m_Score[this->m_Index-1] = aveScore;
		
		// 将选手的成绩存入到groupScore容器中
		groupvect.insert(make_pair(aveScore, *it)); 
		
		//cout << "选手编号：" << *it << "， 姓名为： " << this->m_Speaker[*it].m_Name << ", 成绩为：" << aveScore << endl; 
		
		// 每6名选手一组,取出每组成绩中的前三名
		if(num % 6 == 0){
			
			cout << "第" << num/6 << "小组比赛名次为：" << endl;
			
			for(multimap<double, int,  greater<double> >::iterator it2 = groupvect.begin(); it2 != groupvect.end(); it2++){
				cout << "选手编号：" << it2->second << "， 姓名为： " << this->m_Speaker[it2->second].m_Name << ", 成绩为：" << it2->first << endl; 
			} 
			
			// 取出前三名选手的成绩
			int count = 0;
			for(multimap<double, int, greater<double> >::iterator it2 = groupvect.begin(); it2 != groupvect.end() && count < 3; it2++, count++){
				if(this->m_Index == 1){
					this->v2.push_back(it2->second);
				}else{
					this->vVector.push_back(it2->second);
				}
			}
			 
			// 每次去除成绩后，清空容器中的元素 
			groupvect.clear();
			
			cout << endl;
		} 
	}
	
	cout << "------------ 第" << this->m_Index << "轮比赛结束 --------------" << endl;
	system("pause"); 
	
	//this->m_Index++;
	
//	system("cls");
//	this->show_Menu();
}

// 显示比赛分数 
void speechManager::showScore(){
	cout << "---------- 第" << this->m_Index << "轮比赛结果为：----------" << endl;
	
	vector<int> vTemp;
	
	if(this->m_Index == 1){
		vTemp = this->v2;
	}else{
		vTemp = this->vVector;
	}
	
	for(vector<int>::iterator it = vTemp.begin(); it != vTemp.end(); it++){
		cout << "选手编号为：" << *it
			 << ", 选手姓名为：" << this->m_Speaker[*it].m_Name
			 << ", 选手的平均成绩为： " << this->m_Speaker[*it].m_Score[this->m_Index-1] 
			 << endl;
	}
	
	cout << "---------- 选手成绩显示结束！----------" << endl;
	cout << endl;
	
	system("pause");
	system("cls");
	//this->show_Menu();
	 
} 

// 保存分数
void speechManager::saveRecord(){
	ofstream ofs;
	// 以追加方式打开文件 
	ofs.open("speech.csv", ios::out | ios::app);
	
	for(vector<int>::iterator it = this->vVector.begin(); it != this->vVector.end(); it++){
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << "\n";
	
	ofs.close();
	cout << "---------- 前三名成绩保存完成！----------" << endl;
	this->fileIsEmpty = false;
}

// 获取往届记录
void speechManager::loadRecord(){
	
	// 读取文件中的数据
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	
	// 判断文件是否存在,如果文件不存在则退出该函数 
	if(!ifs.is_open()){
		//cout << "文件不存在！" << endl;
		this->fileIsEmpty = true; 
		return ;
	}
	
	// 该char字符用来判断文件是否为空 
	char ch; 
	ifs >> ch;
	
	// 判断文件是否为空，如果为空，则退出 
	if(ifs.eof()){
		//cout << "文件为空！" << endl;
		this->fileIsEmpty = true;
		return ;
	} 
	
	// 如果文件不为空，则需要将ch字符重新放回到容器中
	ifs.putback(ch);
	
	// 读取文件中的数据 
	string data;
	int index = 0;	// 该下标用来记录第几组数据
	while(ifs >> data){
		// 打印测试 
		//cout << data << endl; 
		//cout << "------------" << endl; 
		
		// 该vTemp容器用来记录data中的元素 
		vector<string> vTemp; 
		
		// 该pos用来记录","的位置 ,start用来记录查找的位置，默认从0开始 
		int pos = -1;
		int start = 0;
		// temp用来记录每个元素 
		string temp;
		
		while(true){
			
			pos = data.find(",", start);
			
			// 判断data中是否存查找到data末尾，如果到末尾则退出循环 
			if(pos == -1){
				break;
			} 
			
			// 获取逗号分隔之前的元素 
			temp = data.substr(start, pos-start); 
			//cout << temp << endl; 
			 
			start = pos + 1;
			
			// 将temp中的元素插入到vTemp容器中 
			vTemp.push_back(temp); 
		} 
		this->fileIsEmpty = false;
		// 将ifs文件中的数据存放到 record_Speech容器中
		this->record_Speech.insert(make_pair(index, vTemp));
		index++;
	}
	
//	// 打印测试
//	for(map<int, vector<string> >::iterator it = this->record_Speech.begin(); it != this->record_Speech.end(); it++){
//		cout << "第 " << it->first << " 届比赛的冠军为：" << it->second[0] << "， 成绩为：" << it->second[1] << endl;
//		cout << "第 " << it->first << " 届比赛的亚军为：" << it->second[2] << "， 成绩为：" << it->second[3] << endl;
//		cout << "第 " << it->first << " 届比赛的季军为：" << it->second[4] << "， 成绩为：" << it->second[5] << endl;
//		cout << "-------------------------------" << endl; 
//	} 
	
	ifs.close();
	
} 

// 查看往届记录
void speechManager::showRecord(){
	// 获取往届记录，并打印 
	this->loadRecord();
	if(this->fileIsEmpty){
		cout << "文件为空或不存在！" << endl;
		this->record_Speech.clear();
	}
	
	for(int i = 0; i < this->record_Speech.size(); i++){
		cout << "第" << i+1 << "届的比赛成绩为：" << endl;
		cout << "冠军编号：" << this->record_Speech[i][0] << ", 成绩：" << this->record_Speech[i][1] << endl; 
		cout << "亚军编号：" << this->record_Speech[i][2] << ", 成绩：" << this->record_Speech[i][3] << endl; 
		cout << "季军编号：" << this->record_Speech[i][4] << ", 成绩：" << this->record_Speech[i][5] << endl; 
		cout << "----------------------------" << endl; 
	}
	system("pause");
	system("cls");
}

// 清空文件中的所有数据
void speechManager::clearRecore(){
	
	cout << "请确认是否清空所有数据：确定Y，退出N::::";
	char temp;
	cin >> temp;
	
	if(temp == 'Y'){
		ofstream ofs;
		// 打开模式，ios::trunc  如果文件存在则删除文件并重新创建 
		ofs.open("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		
		cout << "清空成功@" << endl; 
	}else{
		return;
	}
	
	system("pause");
	system("cls");
	
} 

// 退出功能（实现退出程序） 
void speechManager::exitSystem(){
	
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);	
}
		
// 析构函数 
speechManager::~speechManager(){
	
}

