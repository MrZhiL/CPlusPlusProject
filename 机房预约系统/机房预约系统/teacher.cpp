#include "Teacher.h"

// 默认构造函数
Teacher::Teacher() {

}

// 有参构造函数
Teacher::Teacher(int id, string name, string pwd){
	this->m_EmpId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

// 显示菜单界面函数
void Teacher::operMeun(){
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------------- \n";
	cout << "\t\t|                                         |\n";
	cout << "\t\t|             1、查看所有预约             |\n";
	cout << "\t\t|                                         |\n";
	cout << "\t\t|             2、审核预约                 |\n";
	cout << "\t\t|                                         |\n";
	cout << "\t\t|             0、注销登录                 |\n";
	cout << "\t\t|                                         |\n";
	cout << "\t\t ----------------------------------------- \n";
	cout << "请输入您的选择：" << endl;
}

// 查看所有预约函数
void Teacher::showAllOrder() {
	OrderFileManager ofm;

	if (ofm.orderNum == 0) {
		cout << "预约记录为空@" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "预约记录如下：" << endl;
	for (int i = 0; i < ofm.orderNum; i++) {
		cout << "预约时间：周" << ofm.orderFileMap[i]["date"] << " "
			<< "预约时间段：" << (ofm.orderFileMap[i]["interval"] == "1" ? "上午" : "下午") << " "
			<< "学生学号：" << ofm.orderFileMap[i]["stuId"] << " "
			<< "学生姓名：" << ofm.orderFileMap[i]["stuName"] << " "
			<< "机房编号：" << ofm.orderFileMap[i]["roomId"] << " ";

		string status = "状态：";
		if (ofm.orderFileMap[i]["status"] == "1") {
			status += "预约中";
		}
		else if (ofm.orderFileMap[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (ofm.orderFileMap[i]["status"] == "-1") {
			status += "预约失败：审核未通过@";
		}
		else {
			status += "取消预约";
		}

		cout << status << endl;
	}

	system("pause");
	system("cls");

}

// 审核预约函数
void Teacher::validOrder() {
	OrderFileManager ofm;

	if (ofm.orderNum == 0) {
		cout << "预约记录为空@" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	// 用来记录未审核的预约记录
	int index = 0;

	vector<int> v;

	cout << "待审核预约记录如下：" << endl;
	for (int i = 0; i < ofm.orderNum; i++) {

		if (ofm.orderFileMap[i]["status"] == "1") {
			cout << ++index << ":";
			v.push_back(i);

			cout << "预约时间：周" << ofm.orderFileMap[i]["date"] << " "
				 << "预约时间段：" << (ofm.orderFileMap[i]["interval"] == "1" ? "上午" : "下午") << " "
				 << "学生学号：" << ofm.orderFileMap[i]["stuId"] << " "
				 << "学生姓名：" << ofm.orderFileMap[i]["stuName"] << " "
				 << "机房编号：" << ofm.orderFileMap[i]["roomId"] << " ";

			// 1表示预约中，2表示预约成功，-1表示预约失败，0表示取消预约
			string status = "状态：";
			if (ofm.orderFileMap[i]["status"] == "1") {
				status += "审核 中";
			}
			else if (ofm.orderFileMap[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (ofm.orderFileMap[i]["status"] == "-1") {
				status += "预约失败：审核未通过@";
			}
			else {
				status += "取消预约";
			}

			cout << status << endl;
		}

	}
	
	cout << "----------------------------" << endl;
	cout << "请输入要审核的编号(0退出审核)：";
	//cout << "v.size() = " << v.size() << endl;
	int select = 0;	// 接收用户的选择
	int ret = 0;	// 判断是否审核通过

	while (true) {
		
		cin >> select;
		
		if (select >= 0 && select <= v.size() ) {

			if (select == 0) {
				break;
			}
			else {
				cout << "请选择审核结果(1、通过；2、不通过)：" << endl;
				cin >> ret;

				if (ret == 1) {
					ofm.orderFileMap[v[select-1]]["status"] = "2";
				}
				else if (ret == 2) {
					ofm.orderFileMap[v[select-1]]["status"] = "-1";
					
				}

				ofm.updateOrderFileFunc();
				cout << "审核完成！" << endl;
				break;

			}
			
		}
	
		cout << "输入编号错误，请重新输入：";
	}

	system("pause");
	system("cls");
}