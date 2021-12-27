#include "Manager.h"

// 默认构造函数
Manager::Manager() {

}

// 有参构造函数
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	// 初始化容器，将学生文件和老师文件中的数据读取到两个容器中
	this->initVector();

	// 读取机房信息，并储存到相应的容器中
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	// 创建临时变量，用来记录机房的信息
	ComputerRoom comTemp;

	while (ifs >> comTemp.m_Num && ifs >> comTemp.m_MaxCap) {
		this->vCom.push_back(comTemp);
	}

	cout << "机房数量为：" << this->vCom.size() << endl;

}

// 显示菜单界面函数
void Manager::operMeun() {

	cout << "欢迎管理员：" << this->m_Name << " 登录" << endl;
	cout << "\t\t ------------------------------------ \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         1、添加账号               | \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         2、查看账号               | \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         3、查看机房               | \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         4、清空预约               | \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         0、注销登录               | \n";
	cout << "\t\t ------------------------------------ \n";
	
	cout << "请选择你的操作：";
}

// 添加账号函数
void Manager::addPerson() {
	// 功能描述：添加新账号时，如果是重复的学生编号，或是重复的教职工编号，提出有误
	// 用来记录用户的选择

	int select;

	string fileName;	// 记录要操作的文件
	string tip;			// 通过不同的选择，提出不同的信息
	string errorTip;	// 

	ofstream ofs;		// 创建输入文件流，以用来对教师和学生信息进行操作

	cout << "1、学生" << endl;
	cout << "2、老师" << endl;
	cout << "请选择添加用户类别：" << endl;
	cin >> select;

	while (select != 1 && select != 2) {
		cout << "选择类别错误，请重新输入：";
		cin >> select;
	}

	// 根据用户的选择处理不同的文件
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学生学号：";
		errorTip = "输入学号重复!";
	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入教师职工号：";
		errorTip = "输入职工号重复!";
	}

	// 以追加方式打开文件
	ofs.open(fileName, ios::out | ios::app);

	int id;		//学号或职工号
	string name;//姓名
	string pwd;	//密码

	cout << tip;
	while (true) {
		cin >> id;
		// 检测学号或职工号是否重复
		bool ret = checkRepeat(id, select);

		if (ret == true) {
			cout << errorTip << endl;
			cout << "请重新输入：";
			//cin >> id;

		}else {
			break;
		}

	}
	

	cout << "请输入添加人员的姓名：";
	cin >> name;

	cout << "请输入添加人员的密码：";
	cin >> pwd;

	// 将信息追加到文件末尾
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	
	system("pause");
	system("cls");

	ofs.close();

	/* 此时该函数虽然可以检测重复的账号，但是刚添加的账号由于没有更新到容器中，因此不会做检测
	 * 导致刚加入的账号的学号或职工号，再次添加时仍然可以重复
	 * 解决方案：在每次添加新账号时，重新初始化容器
	 */
	// 需要进行初始化容器，该初始化可以避免插入重复的学号/职工号
	this->initVector();
}

// 查看学生信息
void showStudent(const Student& s) {
	
	cout << "学生的账号为：" << s.m_id << ", 学生的姓名为：" << s.m_Name << endl;

}

// 查看教师信息
void showTeacher(const Teacher& t) {

	cout << "教师的账号为：" << t.m_EmpId << ", 教师的姓名为：" << t.m_Name << endl;

}

// 查看账号函数
void Manager::showPerson() {
	// 在initVector()函数中，将老师和学生的信息已经存放在了vTea和vStu容器中，如果想要查看则只需要查看该容器即可

	cout << "请选择要查看的信息：" << endl;
	cout << "1、查看所有学生信息" << endl;
	cout << "2、查看所有老师信息" << endl;
	cout << "请选择：";

	int select;
	cin >> select;

	while (select != 1 && select != 2) {
		cout << "选择错误，请输入正确的选择(1、学生；2、教师)：";
		cin >> select;
	}

	if (select == 1) {
		for_each(this->vStu.begin(), this->vStu.end(), showStudent);
	}
	else if (select == 2) {
		for_each(this->vTea.begin(), this->vTea.end(), showTeacher);
	}

	system("pause");
	system("cls");

}

// 查看机房信息
void Manager::showComputer() {

	// 打印机房信息
	cout << "机房信息为： " << endl;

	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout << "机房编号为：" << it->m_Num << ", 机房最大容量为：" << it->m_MaxCap << endl;
	}

	system("pause");
	system("cls");

}

// 清空预约记录
void Manager::clearFile() {
	ofstream ofs;
	// 重新创建order.txt文件，从而可以实现清空所有数据
	ofs.open(ORDER_FILE, ios::trunc);

	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");

}

// 初始化教师和学生容器
void Manager::initVector() {
	// 1、先将两个容器清空，用以存储数据
	this->vStu.clear();
	this->vTea.clear();

	// 2、创建读取文件流，无需对文件进行操作
	ifstream ifs;	
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "学生文件读取失败!" << endl;
		return;
	}

	// 3、创建一个Student，用来记录文件中的数据
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		this->vStu.push_back(s);
	}
	ifs.close();
	cout << "共有" << this->vStu.size() << "个学生信息！" << endl;


	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "老师文件读取失败！" << endl;
		return;
	}

	// 4、创建一个老师类，用来临时记录文件中的数据
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		this->vTea.push_back(t);
	}
	ifs.close();

	cout << "共有" << this->vTea.size() << "个老师信息！" << endl;

}

// 检测重复，参数1：学号/职工号； 参数2：检测类型
bool Manager::checkRepeat(int id, int type) {
	
	// 检测输入的学号/职工号是否重复,如果检测到重复，则返回true；

	// 如果输入的是学生的信息
	if (type == 1) {
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++) {
			if (id == it->m_id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}

	// 如果没有检测到重复，则输出false
	return false;
	
}