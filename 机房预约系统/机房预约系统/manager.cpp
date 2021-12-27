#include "Manager.h"

// Ĭ�Ϲ��캯��
Manager::Manager() {

}

// �вι��캯��
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ʼ����������ѧ���ļ�����ʦ�ļ��е����ݶ�ȡ������������
	this->initVector();

	// ��ȡ������Ϣ�������浽��Ӧ��������
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	// ������ʱ������������¼��������Ϣ
	ComputerRoom comTemp;

	while (ifs >> comTemp.m_Num && ifs >> comTemp.m_MaxCap) {
		this->vCom.push_back(comTemp);
	}

	cout << "��������Ϊ��" << this->vCom.size() << endl;

}

// ��ʾ�˵����溯��
void Manager::operMeun() {

	cout << "��ӭ����Ա��" << this->m_Name << " ��¼" << endl;
	cout << "\t\t ------------------------------------ \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         1������˺�               | \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         2���鿴�˺�               | \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         3���鿴����               | \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         4�����ԤԼ               | \n";
	cout << "\t\t |                                   | \n";
	cout << "\t\t |         0��ע����¼               | \n";
	cout << "\t\t ------------------------------------ \n";
	
	cout << "��ѡ����Ĳ�����";
}

// ����˺ź���
void Manager::addPerson() {
	// ����������������˺�ʱ��������ظ���ѧ����ţ������ظ��Ľ�ְ����ţ��������
	// ������¼�û���ѡ��

	int select;

	string fileName;	// ��¼Ҫ�������ļ�
	string tip;			// ͨ����ͬ��ѡ�������ͬ����Ϣ
	string errorTip;	// 

	ofstream ofs;		// ���������ļ������������Խ�ʦ��ѧ����Ϣ���в���

	cout << "1��ѧ��" << endl;
	cout << "2����ʦ" << endl;
	cout << "��ѡ������û����" << endl;
	cin >> select;

	while (select != 1 && select != 2) {
		cout << "ѡ�����������������룺";
		cin >> select;
	}

	// �����û���ѡ����ͬ���ļ�
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ��ѧ�ţ�";
		errorTip = "����ѧ���ظ�!";
	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "�������ʦְ���ţ�";
		errorTip = "����ְ�����ظ�!";
	}

	// ��׷�ӷ�ʽ���ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;		//ѧ�Ż�ְ����
	string name;//����
	string pwd;	//����

	cout << tip;
	while (true) {
		cin >> id;
		// ���ѧ�Ż�ְ�����Ƿ��ظ�
		bool ret = checkRepeat(id, select);

		if (ret == true) {
			cout << errorTip << endl;
			cout << "���������룺";
			//cin >> id;

		}else {
			break;
		}

	}
	

	cout << "�����������Ա��������";
	cin >> name;

	cout << "�����������Ա�����룺";
	cin >> pwd;

	// ����Ϣ׷�ӵ��ļ�ĩβ
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	
	system("pause");
	system("cls");

	ofs.close();

	/* ��ʱ�ú�����Ȼ���Լ���ظ����˺ţ����Ǹ���ӵ��˺�����û�и��µ������У���˲��������
	 * ���¸ռ�����˺ŵ�ѧ�Ż�ְ���ţ��ٴ����ʱ��Ȼ�����ظ�
	 * �����������ÿ��������˺�ʱ�����³�ʼ������
	 */
	// ��Ҫ���г�ʼ���������ó�ʼ�����Ա�������ظ���ѧ��/ְ����
	this->initVector();
}

// �鿴ѧ����Ϣ
void showStudent(const Student& s) {
	
	cout << "ѧ�����˺�Ϊ��" << s.m_id << ", ѧ��������Ϊ��" << s.m_Name << endl;

}

// �鿴��ʦ��Ϣ
void showTeacher(const Teacher& t) {

	cout << "��ʦ���˺�Ϊ��" << t.m_EmpId << ", ��ʦ������Ϊ��" << t.m_Name << endl;

}

// �鿴�˺ź���
void Manager::showPerson() {
	// ��initVector()�����У�����ʦ��ѧ������Ϣ�Ѿ��������vTea��vStu�����У������Ҫ�鿴��ֻ��Ҫ�鿴����������

	cout << "��ѡ��Ҫ�鿴����Ϣ��" << endl;
	cout << "1���鿴����ѧ����Ϣ" << endl;
	cout << "2���鿴������ʦ��Ϣ" << endl;
	cout << "��ѡ��";

	int select;
	cin >> select;

	while (select != 1 && select != 2) {
		cout << "ѡ�������������ȷ��ѡ��(1��ѧ����2����ʦ)��";
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

// �鿴������Ϣ
void Manager::showComputer() {

	// ��ӡ������Ϣ
	cout << "������ϢΪ�� " << endl;

	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout << "�������Ϊ��" << it->m_Num << ", �����������Ϊ��" << it->m_MaxCap << endl;
	}

	system("pause");
	system("cls");

}

// ���ԤԼ��¼
void Manager::clearFile() {
	ofstream ofs;
	// ���´���order.txt�ļ����Ӷ�����ʵ�������������
	ofs.open(ORDER_FILE, ios::trunc);

	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");

}

// ��ʼ����ʦ��ѧ������
void Manager::initVector() {
	// 1���Ƚ�����������գ����Դ洢����
	this->vStu.clear();
	this->vTea.clear();

	// 2��������ȡ�ļ�����������ļ����в���
	ifstream ifs;	
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "ѧ���ļ���ȡʧ��!" << endl;
		return;
	}

	// 3������һ��Student��������¼�ļ��е�����
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		this->vStu.push_back(s);
	}
	ifs.close();
	cout << "����" << this->vStu.size() << "��ѧ����Ϣ��" << endl;


	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ʦ�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	// 4������һ����ʦ�࣬������ʱ��¼�ļ��е�����
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		this->vTea.push_back(t);
	}
	ifs.close();

	cout << "����" << this->vTea.size() << "����ʦ��Ϣ��" << endl;

}

// ����ظ�������1��ѧ��/ְ���ţ� ����2���������
bool Manager::checkRepeat(int id, int type) {
	
	// ��������ѧ��/ְ�����Ƿ��ظ�,�����⵽�ظ����򷵻�true��

	// ����������ѧ������Ϣ
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

	// ���û�м�⵽�ظ��������false
	return false;
	
}