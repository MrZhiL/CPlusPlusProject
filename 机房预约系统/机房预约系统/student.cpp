#include "Student.h"

// 默认构造函数
Student::Student() {

}

// 有参构造函数, 参数：学号、姓名、密码
Student::Student(int id, string name, string pwd) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// 初始化机房信息
	// comRTemp为临时变量，用来记录机房信息
	ComputerRoom comRTemp;
	
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	// 读取机房信息，将信息保存到comRTemp容器中
	while (ifs >> comRTemp.m_Num&& ifs >> comRTemp.m_MaxCap) {
		this->vComDemo.push_back(comRTemp);
	}

	ifs.close();

}

// 创建菜单纯虚函数，子类必须重写该函数，要不然子类也为抽象基类
void Student::operMeun() {
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           1、申请预约             |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           2、查看我的预约         |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           3、查看所有预约         |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           4、取消预约             |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           0、注销登录             |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "请选择您的操作：" << endl;
}

// 预约函数
void Student::applyOrder() {
	cout << "机房预约的时间为周一至周五！" << endl;
	cout << "1、周一  2、周二  3、周三  4、周四  5、周五" << endl;
	cout << "请选择要预约的日期：";

	int dateNum;		// 预约的日期（周一 — 周五）
	int intervalNum;	// 预约的时间段（上午、下午）
	int roomNum;		// 预约的机房编号（1、2、3）

	while (true) {
		cin >> dateNum;
		if (dateNum >= 1 && dateNum <= 5) {
			break;
		}
		cout << "选择日期不在范围内，请重新输入（1-5）：";
	}

	cout << "请选择预约的时间段（1、上午   2、下午）：";
	while (true) {
		cin >> intervalNum;
		if (intervalNum >= 1 && intervalNum <= 2) {
			break;
		}
		cout << "选择时间段不在范围内，请重新输入（1/2）：";
	}

	for (vector<ComputerRoom>::iterator it = this->vComDemo.begin(); it != this->vComDemo.end(); it++) {
		cout << "机房编号为：" << it->m_Num << "， 机房容量为" << it->m_MaxCap << endl;
	}

	cout << "请选择要预约的机房：";
	while (true) {
		cin >> roomNum;
		if (roomNum >= 1 && roomNum <= this->vComDemo.size()) {
			break;
		}
		cout << "选择的机房错误！请重新输入：";
	}

	cout << "预约成功，正在进行审核!" << endl;

	// 将学生预约的结果保存到order.txt中
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << dateNum << " "
		<< "interval:" << intervalNum << " "
		<< "stuId:" << this->m_id << " "
		<< "stuName:" << this->m_Name << " "
		<< "roomId:" << roomNum << " "
		<< "status:" << 1						// 1、表示预约机房审核中
		<< endl;

	ofs.close();

	system("pause");
	system("cls");
}

// 显示自身预约函数
void Student::showMyOrder() {
	OrderFileManager ofm;

	// 先判断机房是否有预约记录
	if (ofm.orderNum == 0) {
		cout << "机房没有预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "您的预约记录为：" <<  endl; 
	for (int i = 0; i < ofm.orderNum; i++) {
		
		// 判断自身id在预约记录中是否存在，如果存在，则返回自身信息
		// 因为ofm.orderFileMap容器中存放的学生id为string类型，因此需要转为int类型
		// string转为int类型的方法：
		// 1、首先使用.c_str()函数将string类型转为C语言中的const char*类型
		// 2、使用atoi(const char*)函数将const char*类型转化为int类型
		if (this->m_id == atoi(ofm.orderFileMap[i]["stuId"].c_str())) {
			cout << "预约日期：周" << ofm.orderFileMap[i]["date"] << endl;
			cout << "预约时间段：" << ( ofm.orderFileMap[i]["interval"] == "1" ? "上午":"下午") << endl;
			cout << "预约的机房编号：" << ofm.orderFileMap[i]["roomId"] << endl;
			
			string status = "状态：";
			// 判断学生预约的状态：1审核中  2预约成功 -1预约失败 0取消预约
			if (ofm.orderFileMap[i]["status"] == "1") {
				status += "审核中";
			}
			else if (ofm.orderFileMap[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (ofm.orderFileMap[i]["status"] == "-1"){
				status += "预约失败，审核未通过";
			}
			else {
				status += "取消预约";
			}

			cout << status << endl;
			cout << "-------------------------------------------" << endl;
		}
	}

	/*
	string dateNum;		// order.txt中学生预约的日期
	string intervalNum; // order.txt中学生预约的时间段
	string stuId;		// order.txt中预约的学生的学号
	string stuName;		// order.txt中学生预约的姓名
	string roomId;		// order.txt中学生预约的机房的编号
	string status;		// order.txt中学生预约的状态
	*/
	system("pause");
	system("cls");
}

// 显示所有预约函数（数据多了需要翻页查询）
void Student::showAllOrder() {
	OrderFileManager ofm;

	// 判断是否有预约记录，如果没有预约记录，则直接退出
	if (ofm.orderNum == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 当预约记录不为空时，将预约信息打印
	for (int i = 0; i < ofm.orderNum; i++) {
		cout << "第" << i + 1 << "条记录为：";
		
		cout << "日期：周" << ofm.orderFileMap[i]["date"] << endl;
		cout << "时间段：" << (ofm.orderFileMap[i]["interval"] = 1 ? "上午":"下午") << endl;
		cout << "学生学号为：" << ofm.orderFileMap[i]["stuId"] << endl;
		cout << "学生姓名为：" << ofm.orderFileMap[i]["stuName"] << endl;
		cout << "预约机房为：" << ofm.orderFileMap[i]["roomId"] << endl;
		string status = "状态为：";
		
		// stauts = 1(预约中)； 2（预约成功）；-1（预约失败)；0（取消预约）
		if ( (ofm.orderFileMap[i]["status"]) == "1") {
			status += "预约中";
		}
		else if ((ofm.orderFileMap[i]["status"]) == "2") {
			status += "预约成功";
		}
		else if ((ofm.orderFileMap[i]["status"]) == "-1") {
			status += "预约失败";
		}
		else {
			status += "取消预约";
		}

		cout << status << endl;
		cout << "------------------------" << endl;
	}
	system("pause");
	system("cls");
}

// 取消预约函数
void Student::cancelOrder() {
	OrderFileManager ofm;

	// 判断是否有预约记录
	if (ofm.orderNum == 0) {
		cout << "预约为空！" << endl;
		system("pause");
		system("cls");
		return ;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v; // 记录学生的预约条数

	int index = 1;

	// 如果预约不为空，则显示自身的预约记录
	for (int i = 0; i < ofm.orderNum; i++) {
		if (this->m_id == atoi(ofm.orderFileMap[i]["stuId"].c_str())) {
			
			// 先筛选状态，审核中或预约成功的可以取消
			if ( ofm.orderFileMap[i]["status"] == "1" || ofm.orderFileMap[i]["status"] == "2" ) {
				
				v.push_back(i);		// 将学生预约的下标存放到vector容器中
				
				// 打印自身预约记录
				cout << "第" << index++ << "条记录："
					<< "日期: 周" << ofm.orderFileMap[i]["date"] << " "
					<< "时间段: " << (ofm.orderFileMap[i]["interval"] = 1 ? "上午" : "下午") << " "
					<< "预约机房号 : " << ofm.orderFileMap[i]["roomId"] << " ";

				string  status = "状态：";

				if (ofm.orderFileMap[i]["status"] == "1") {
					status += "审核中";
				}
				else if (ofm.orderFileMap[i]["status"] == "2") {
					status += "审核成功";
				}
				else if (ofm.orderFileMap[i]["status"] == "-1") {
					status += "预约失败";
				}
				else {
					status += "取消预约";
				}

				cout << status << endl;
			}
		}
	}

	cout << "请输入要取消的编号,0代表取消：";
	int select = 0;

	while (true) {
		cin >> select;

		// 判断输入的编号，并取消该条预约
		// 判断输入的编号是否在合理范围内
		if (select >= 0 && select <= ofm.orderNum) {
			if (select == 0) {
				break;
			}
			else {
				ofm.orderFileMap[v[select - 1]]["status"] = "0";
				ofm.updateOrderFileFunc();
				break;
			}
			
		}

		cout << "输入有误，请重新输入：";
	}
	cout << "取消成功@" << endl;
	system("pause");
	system("cls");
}