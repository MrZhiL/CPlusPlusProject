#include<iostream>
#include<string>
#include<fstream>

#include "globalFile.h"
#include "identity.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"

using namespace std;

// 管理员菜单界面
void managerMenu(Identity* &manager) {
	//system("cls");
	while (true) {
		// 显示管理员菜单界面
		manager->operMeun();

		// 记录管理员的选择操作
		int select;

		// 将父类指针强转为子类指针
		Manager* man = (Manager*)manager;

		cin >> select;
//		while (select < 0 || select >4) {
//			cout << "选择失败！请输入有效选择!" << endl;
//			system("pause");
//			system("cls");
//			man->operMeun();
//			cin >> select;
//		}

		// 判断用户的选择，并进行下一步操作
		switch (select) {
			// 添加用户
		case 1:
			//cout << "添加用户！" << endl;
			man->addPerson();
			break;
			// 查看用户
		case 2:
			//cout << "查看用户！" << endl;
			man->showPerson();
			break;
			// 查看机房信息
		case 3:
			//cout << "查看机房信息！" << endl;
			man->showComputer();
			break;
			// 清空预约
		case 4:
			//cout << "清空所有用户！" << endl;
			man->clearFile();
			break;
			// 注销登录
		case 0:
			//cout << "注销成功" << endl;
			system("pause");
			system("cls");
			delete manager;
			return;
			break;
		default:
			cout << "选择失败！请输入有效选择!" << endl;
			
			system("pause");
			system("cls");
			//man->operMeun();
			break;
		}
	}
}

// 学生菜单界面
void studentMenu(Identity* &student) {
	while (true) {
		// 显示学生界面
		student->operMeun();

		// 将manager强转为student类
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		switch (select) {
			// 1、申请预约
			case 1:
				stu->applyOrder();
				break;
			// 2、查看我的预约
			case 2:
				stu->showMyOrder();
				break;
			// 3、查看所有预约
			case 3:
				stu->showAllOrder();
				break;
			// 4、取消预约
			case 4:
				stu->cancelOrder();
				break;
			// 0、注销登录
			case 0:
				cout << "注销成功！" << endl;
				delete student;
				system("pause");
				system("cls");
				return;
				break;
			default:
				break;	
		}
	}
}


// 教师界面登录
void teacherMenu(Identity*& teacher) {

	while (true) {
		teacher->operMeun();

		// 将Identity类强转为teacher类
		Teacher* tea = (Teacher*)teacher;

		int select = 0;

		cin >> select;

		if (select >= 0 && select <= 2) {
			
			switch (select){
				// 查看所有预约
				case 1:
					tea->showAllOrder();
					break;
				// 审核预约
				case 2:
					tea->validOrder();
					break;
				// 注销登录
				case 0:
					cout << "注销成功！" << endl;
					delete teacher;
					system("pause");
					system("cls");
					return;
					break;
				default:
					break;
			}
		}
		else {
			cout << "输入错误，请重新输入 ：";
		}
	}
}


// 封装登录函数：根据用户的选择，进入不同的身份登录
// fileName:操作的文件名；type:身份类型确认
void LoginIn(string fileName, int type) {

	// 创建父类指针，用来指向子类的对象
	Identity* person = NULL;

	// 创建文件，从而可以操作想要操作的文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// 先判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 对用户数据进行操作
	int id;			// 用户id
	string name;	// 用户姓名
	string pwd;		// 用户登录密码

	// 针对不同的用户来显示不同的信息
	if (type == 1) {
		cout << "请输入学生学号：";
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入教师职工号：";
		cin >> id;
	}

	cout << "请输入用户名：";
	cin >> name;

	cout << "请输入密码：";
	cin >> pwd;

	// 判断用户登录是否成功
	if (type == 1) {
		// 对学生进行登录判断

		// 创建变量用来记录文件读出的数据
		// 验证学生登录信息是否正确
		int fId;
		string fName;
		string fPwd;

		// 读取student.txt文件中的数据，并进行判断
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//cout << fId << "  " << fName << "  " << fPwd << endl;
			if ( id == fId && name == fName && pwd == fPwd) {
				cout << "登录成功！" << endl;
				
				//成功登录之后，进入教师菜单界面
				system("pause");
				system("cls");

				// 验证成功之后，将父类指针指向学生信息
				person = new Student(id, name, pwd);

				//成功登录之后，进入学生菜单界面
				studentMenu(person);
				
				return;
			}
		}

	}
	else if (type == 2) {
		// 对教师进行登录验证
		
		// 创建变量用来记录文件读出的数据
		// 验证教师登录信息是否正确
		int fId;
		string fName;
		string fPwd;

		// 读取teacher.txt文件中的数据，并进行验证
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//cout << fId << "  " << fName << "  " << fPwd << endl;
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "登录成功！" << endl;

				//成功登录之后，进入教师菜单界面
				system("pause");
				system("cls");

				// 验证成功之后，将父类指针指向学生信息
				person = new Teacher(id, name, pwd);
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3) {
		// 对管理员进行登录验证
		// 验证教师登录信息是否正确
		string fName;
		string fPwd;

		// 读取admin.txt文件中的数据，并进行验证
		while (ifs >> fName && ifs >> fPwd) {
			//cout << fId << "  " << fName << "  " << fPwd << endl;
			if ( name == fName && pwd == fPwd) {
				cout << "登录成功！" << endl;
				system("cls");
				// 验证成功之后，将父类指针指向学生指针
				person = new Manager(name, pwd);

				//成功登录之后，进入管理员菜单界面
				managerMenu(person);

				return;
			}
		}
	}

	cout << "登录失败！" << endl;

	system("pause");
	system("cls");

	return;

}


int main() {

	// select用来记录用户的选择
	int select;

	while (true) {

		// 打印窗口界面
		cout << "---------- 欢迎来到小智机房预约系统 -------------" << endl;
		cout << "请输入您的身份" << endl;
		cout << "\t\t -------------------------" << endl;
		cout << "\t\t | \t 1、学生代表 \t | " << endl;
		cout << "\t\t | \t 2、老    师 \t | " << endl;
		cout << "\t\t | \t 3、管 理 员 \t | " << endl;
		cout << "\t\t | \t 0、退    出 \t | " << endl;
		cout << "\t\t -------------------------" << endl;

		// 判断一下输入的为数字还是字符，若为字符，则提示输入错误
		cout << "请输入你的选择：";
		cin >> select;	// 接收用户的选择

		switch (select) {
			// 学生身份
			case 1: 
				LoginIn(STUDENT_FILE, 1);
				break;

			// 老师身份
			case 2:
				LoginIn(TEACHER_FILE, 2);
				break;

			// 管理员身份
			case 3:
				LoginIn(ADMIN_FILE, 3);
				break;
			// 退出系统
			case 0: {
				cout << "--------- 欢迎下次使用！---------" << endl;
				system("pause");
				return 0;
				break;
			}				
			default: {
				cout << "选择输入错误，请重新输入（0-3）!!" << endl;
				system("pause");
				system("cls");
				break;
			}
				
		}
	}

	system("pause");
	
	return 0;
}