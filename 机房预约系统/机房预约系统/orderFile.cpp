#include "orderFile.h"

// 构造函数，实现读取预约数据
OrderFileManager::OrderFileManager() {

	// 在构造函数中实现读取预约记录，用便学生查询
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string dateNum;		// order.txt中学生预约的日期
	string intervalNum; // order.txt中学生预约的时间段
	string stuId;		// order.txt中预约的学生的学号
	string stuName;		// order.txt中学生预约的姓名
	string roomId;		// order.txt中学生预约的机房的编号
	string status;		// order.txt中学生预约的状态
	
	this->orderNum = 0;

	// 利用while循环将order.txt中的数据读取出来
	while (ifs >> dateNum && ifs >> intervalNum && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		
		/* // 打印测试
		cout << dateNum << endl;
		cout << intervalNum << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << comNum << endl;
		cout << status << endl;
		cout << endl;  */

		// 将读取出来的数据存放到map容器中
		map<string, string> mTemp;

		string key;		// 用来存放键值
		string value;	// 用来存放value

		// 将dateNum中的key值和value值分开
		int pos = dateNum.find(":");

		if (pos != -1) {
			key = dateNum.substr(0,pos);
			value = dateNum.substr(pos+1, dateNum.size()-pos-1);

			// 将dateNum的元素插入到mTemp容器中
			mTemp.insert(make_pair(key,value));
						
		}

		// 将intervalNum中的key值和value值分开
		pos = intervalNum.find(":");

		if (pos != -1) {
			key = intervalNum.substr(0, pos);
			value = intervalNum.substr(pos + 1, intervalNum.size() - pos - 1);

			// 将dateNum的元素插入到mTemp容器中
			mTemp.insert(make_pair(key, value));
						
		}

		// 将stuId中的key值和value值分开
		pos = stuId.find(":");

		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);

			// 将dateNum的元素插入到mTemp容器中
			mTemp.insert(make_pair(key, value));

		}

		// 将stuName中的key值和value值分开
		pos = stuName.find(":");

		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);

			// 将dateNum的元素插入到mTemp容器中
			mTemp.insert(make_pair(key, value));

		}

		// 将comNum中的key值和value值分开
		pos = roomId.find(":");

		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);

			// 将dateNum的元素插入到mTemp容器中
			mTemp.insert(make_pair(key, value));

		}

		// 将status中的key值和value值分开
		pos = status.find(":");

		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			// 将dateNum的元素插入到mTemp容器中
			mTemp.insert(make_pair(key, value));

		}

		// 将dateNum的数据插入到大容器中
		this->orderFileMap.insert(make_pair(this->orderNum, mTemp));
		this->orderNum++;

	}

	cout << "orderFile中共有数据：" << this->orderFileMap.size() << endl;
	// 测试大容器中是否成功插入数据
	/*
	for (map<int, map<string, string>>::iterator it = this->orderFileMap.begin(); it != this->orderFileMap.end(); it++) {
		cout << "预约编号：" << it->first << "预约信息为：" << endl;
		for (map<string, string>::iterator stuIt = (*it).second.begin(); stuIt != it->second.end(); stuIt++) {
			cout << stuIt->first << " " << stuIt->second << endl;
		}
		cout << "---------------------------------------------" << endl;
	}
	*/
	// cout << "读取完成" << endl;
	//system("pause");
	//system("cls");

	ifs.close();

}

// 更新order.txt文件中的预约数据
void OrderFileManager::updateOrderFileFunc() {
	/*
	string dateNum;		// order.txt中学生预约的日期
	string intervalNum; // order.txt中学生预约的时间段
	string stuId;		// order.txt中预约的学生的学号
	string stuName;		// order.txt中学生预约的姓名
	string roomId;		// order.txt中学生预约的机房的编号
	string status;		// order.txt中学生预约的状态
	*/
	
	// 先判断预约数目是否为0，如果为0则退出
	if (this->orderNum == 0) {
		return;
	}

	// 如果预约数量不为空，则更新预约数据
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	
	// 打印测试
	for (int i = 0; i < this->orderNum; i++) {
		ofs << "date:" << this->orderFileMap[i]["date"] << " ";
		ofs << "interval:" << this->orderFileMap[i]["interval"] << " ";
		ofs << "stuId:" << this->orderFileMap[i]["stuId"] << " ";
		ofs << "stuName:" << this->orderFileMap[i]["stuName"] << " ";
		ofs << "roomId:" << this->orderFileMap[i]["roomId"] << " ";
		ofs << "status:" << this->orderFileMap[i]["status"] << endl;
	}

}