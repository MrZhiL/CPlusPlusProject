#include<iostream>
#include<string>
#include<fstream>

#include "globalFile.h"
#include "identity.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"

using namespace std;

// ����Ա�˵�����
void managerMenu(Identity* &manager) {
	//system("cls");
	while (true) {
		// ��ʾ����Ա�˵�����
		manager->operMeun();

		// ��¼����Ա��ѡ�����
		int select;

		// ������ָ��ǿתΪ����ָ��
		Manager* man = (Manager*)manager;

		cin >> select;
//		while (select < 0 || select >4) {
//			cout << "ѡ��ʧ�ܣ���������Чѡ��!" << endl;
//			system("pause");
//			system("cls");
//			man->operMeun();
//			cin >> select;
//		}

		// �ж��û���ѡ�񣬲�������һ������
		switch (select) {
			// ����û�
		case 1:
			//cout << "����û���" << endl;
			man->addPerson();
			break;
			// �鿴�û�
		case 2:
			//cout << "�鿴�û���" << endl;
			man->showPerson();
			break;
			// �鿴������Ϣ
		case 3:
			//cout << "�鿴������Ϣ��" << endl;
			man->showComputer();
			break;
			// ���ԤԼ
		case 4:
			//cout << "��������û���" << endl;
			man->clearFile();
			break;
			// ע����¼
		case 0:
			//cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			delete manager;
			return;
			break;
		default:
			cout << "ѡ��ʧ�ܣ���������Чѡ��!" << endl;
			
			system("pause");
			system("cls");
			//man->operMeun();
			break;
		}
	}
}

// ѧ���˵�����
void studentMenu(Identity* &student) {
	while (true) {
		// ��ʾѧ������
		student->operMeun();

		// ��managerǿתΪstudent��
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		switch (select) {
			// 1������ԤԼ
			case 1:
				stu->applyOrder();
				break;
			// 2���鿴�ҵ�ԤԼ
			case 2:
				stu->showMyOrder();
				break;
			// 3���鿴����ԤԼ
			case 3:
				stu->showAllOrder();
				break;
			// 4��ȡ��ԤԼ
			case 4:
				stu->cancelOrder();
				break;
			// 0��ע����¼
			case 0:
				cout << "ע���ɹ���" << endl;
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


// ��ʦ�����¼
void teacherMenu(Identity*& teacher) {

	while (true) {
		teacher->operMeun();

		// ��Identity��ǿתΪteacher��
		Teacher* tea = (Teacher*)teacher;

		int select = 0;

		cin >> select;

		if (select >= 0 && select <= 2) {
			
			switch (select){
				// �鿴����ԤԼ
				case 1:
					tea->showAllOrder();
					break;
				// ���ԤԼ
				case 2:
					tea->validOrder();
					break;
				// ע����¼
				case 0:
					cout << "ע���ɹ���" << endl;
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
			cout << "����������������� ��";
		}
	}
}


// ��װ��¼�����������û���ѡ�񣬽��벻ͬ����ݵ�¼
// fileName:�������ļ�����type:�������ȷ��
void LoginIn(string fileName, int type) {

	// ��������ָ�룬����ָ������Ķ���
	Identity* person = NULL;

	// �����ļ����Ӷ����Բ�����Ҫ�������ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// ���ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// ���û����ݽ��в���
	int id;			// �û�id
	string name;	// �û�����
	string pwd;		// �û���¼����

	// ��Բ�ͬ���û�����ʾ��ͬ����Ϣ
	if (type == 1) {
		cout << "������ѧ��ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2) {
		cout << "�������ʦְ���ţ�";
		cin >> id;
	}

	cout << "�������û�����";
	cin >> name;

	cout << "���������룺";
	cin >> pwd;

	// �ж��û���¼�Ƿ�ɹ�
	if (type == 1) {
		// ��ѧ�����е�¼�ж�

		// ��������������¼�ļ�����������
		// ��֤ѧ����¼��Ϣ�Ƿ���ȷ
		int fId;
		string fName;
		string fPwd;

		// ��ȡstudent.txt�ļ��е����ݣ��������ж�
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//cout << fId << "  " << fName << "  " << fPwd << endl;
			if ( id == fId && name == fName && pwd == fPwd) {
				cout << "��¼�ɹ���" << endl;
				
				//�ɹ���¼֮�󣬽����ʦ�˵�����
				system("pause");
				system("cls");

				// ��֤�ɹ�֮�󣬽�����ָ��ָ��ѧ����Ϣ
				person = new Student(id, name, pwd);

				//�ɹ���¼֮�󣬽���ѧ���˵�����
				studentMenu(person);
				
				return;
			}
		}

	}
	else if (type == 2) {
		// �Խ�ʦ���е�¼��֤
		
		// ��������������¼�ļ�����������
		// ��֤��ʦ��¼��Ϣ�Ƿ���ȷ
		int fId;
		string fName;
		string fPwd;

		// ��ȡteacher.txt�ļ��е����ݣ���������֤
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//cout << fId << "  " << fName << "  " << fPwd << endl;
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��¼�ɹ���" << endl;

				//�ɹ���¼֮�󣬽����ʦ�˵�����
				system("pause");
				system("cls");

				// ��֤�ɹ�֮�󣬽�����ָ��ָ��ѧ����Ϣ
				person = new Teacher(id, name, pwd);
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3) {
		// �Թ���Ա���е�¼��֤
		// ��֤��ʦ��¼��Ϣ�Ƿ���ȷ
		string fName;
		string fPwd;

		// ��ȡadmin.txt�ļ��е����ݣ���������֤
		while (ifs >> fName && ifs >> fPwd) {
			//cout << fId << "  " << fName << "  " << fPwd << endl;
			if ( name == fName && pwd == fPwd) {
				cout << "��¼�ɹ���" << endl;
				system("cls");
				// ��֤�ɹ�֮�󣬽�����ָ��ָ��ѧ��ָ��
				person = new Manager(name, pwd);

				//�ɹ���¼֮�󣬽������Ա�˵�����
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��¼ʧ�ܣ�" << endl;

	system("pause");
	system("cls");

	return;

}


int main() {

	// select������¼�û���ѡ��
	int select;

	while (true) {

		// ��ӡ���ڽ���
		cout << "---------- ��ӭ����С�ǻ���ԤԼϵͳ -------------" << endl;
		cout << "�������������" << endl;
		cout << "\t\t -------------------------" << endl;
		cout << "\t\t | \t 1��ѧ������ \t | " << endl;
		cout << "\t\t | \t 2����    ʦ \t | " << endl;
		cout << "\t\t | \t 3���� �� Ա \t | " << endl;
		cout << "\t\t | \t 0����    �� \t | " << endl;
		cout << "\t\t -------------------------" << endl;

		// �ж�һ�������Ϊ���ֻ����ַ�����Ϊ�ַ�������ʾ�������
		cout << "���������ѡ��";
		cin >> select;	// �����û���ѡ��

		switch (select) {
			// ѧ�����
			case 1: 
				LoginIn(STUDENT_FILE, 1);
				break;

			// ��ʦ���
			case 2:
				LoginIn(TEACHER_FILE, 2);
				break;

			// ����Ա���
			case 3:
				LoginIn(ADMIN_FILE, 3);
				break;
			// �˳�ϵͳ
			case 0: {
				cout << "--------- ��ӭ�´�ʹ�ã�---------" << endl;
				system("pause");
				return 0;
				break;
			}				
			default: {
				cout << "ѡ������������������루0-3��!!" << endl;
				system("pause");
				system("cls");
				break;
			}
				
		}
	}

	system("pause");
	
	return 0;
}