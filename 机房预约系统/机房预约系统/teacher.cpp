#include "Teacher.h"

// Ĭ�Ϲ��캯��
Teacher::Teacher() {

}

// �вι��캯��
Teacher::Teacher(int id, string name, string pwd){
	this->m_EmpId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

// ��ʾ�˵����溯��
void Teacher::operMeun(){
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------------- \n";
	cout << "\t\t|                                         |\n";
	cout << "\t\t|             1���鿴����ԤԼ             |\n";
	cout << "\t\t|                                         |\n";
	cout << "\t\t|             2�����ԤԼ                 |\n";
	cout << "\t\t|                                         |\n";
	cout << "\t\t|             0��ע����¼                 |\n";
	cout << "\t\t|                                         |\n";
	cout << "\t\t ----------------------------------------- \n";
	cout << "����������ѡ��" << endl;
}

// �鿴����ԤԼ����
void Teacher::showAllOrder() {
	OrderFileManager ofm;

	if (ofm.orderNum == 0) {
		cout << "ԤԼ��¼Ϊ��@" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "ԤԼ��¼���£�" << endl;
	for (int i = 0; i < ofm.orderNum; i++) {
		cout << "ԤԼʱ�䣺��" << ofm.orderFileMap[i]["date"] << " "
			<< "ԤԼʱ��Σ�" << (ofm.orderFileMap[i]["interval"] == "1" ? "����" : "����") << " "
			<< "ѧ��ѧ�ţ�" << ofm.orderFileMap[i]["stuId"] << " "
			<< "ѧ��������" << ofm.orderFileMap[i]["stuName"] << " "
			<< "������ţ�" << ofm.orderFileMap[i]["roomId"] << " ";

		string status = "״̬��";
		if (ofm.orderFileMap[i]["status"] == "1") {
			status += "ԤԼ��";
		}
		else if (ofm.orderFileMap[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (ofm.orderFileMap[i]["status"] == "-1") {
			status += "ԤԼʧ�ܣ����δͨ��@";
		}
		else {
			status += "ȡ��ԤԼ";
		}

		cout << status << endl;
	}

	system("pause");
	system("cls");

}

// ���ԤԼ����
void Teacher::validOrder() {
	OrderFileManager ofm;

	if (ofm.orderNum == 0) {
		cout << "ԤԼ��¼Ϊ��@" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	// ������¼δ��˵�ԤԼ��¼
	int index = 0;

	vector<int> v;

	cout << "�����ԤԼ��¼���£�" << endl;
	for (int i = 0; i < ofm.orderNum; i++) {

		if (ofm.orderFileMap[i]["status"] == "1") {
			cout << ++index << ":";
			v.push_back(i);

			cout << "ԤԼʱ�䣺��" << ofm.orderFileMap[i]["date"] << " "
				 << "ԤԼʱ��Σ�" << (ofm.orderFileMap[i]["interval"] == "1" ? "����" : "����") << " "
				 << "ѧ��ѧ�ţ�" << ofm.orderFileMap[i]["stuId"] << " "
				 << "ѧ��������" << ofm.orderFileMap[i]["stuName"] << " "
				 << "������ţ�" << ofm.orderFileMap[i]["roomId"] << " ";

			// 1��ʾԤԼ�У�2��ʾԤԼ�ɹ���-1��ʾԤԼʧ�ܣ�0��ʾȡ��ԤԼ
			string status = "״̬��";
			if (ofm.orderFileMap[i]["status"] == "1") {
				status += "��� ��";
			}
			else if (ofm.orderFileMap[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (ofm.orderFileMap[i]["status"] == "-1") {
				status += "ԤԼʧ�ܣ����δͨ��@";
			}
			else {
				status += "ȡ��ԤԼ";
			}

			cout << status << endl;
		}

	}
	
	cout << "----------------------------" << endl;
	cout << "������Ҫ��˵ı��(0�˳����)��";
	//cout << "v.size() = " << v.size() << endl;
	int select = 0;	// �����û���ѡ��
	int ret = 0;	// �ж��Ƿ����ͨ��

	while (true) {
		
		cin >> select;
		
		if (select >= 0 && select <= v.size() ) {

			if (select == 0) {
				break;
			}
			else {
				cout << "��ѡ����˽��(1��ͨ����2����ͨ��)��" << endl;
				cin >> ret;

				if (ret == 1) {
					ofm.orderFileMap[v[select-1]]["status"] = "2";
				}
				else if (ret == 2) {
					ofm.orderFileMap[v[select-1]]["status"] = "-1";
					
				}

				ofm.updateOrderFileFunc();
				cout << "�����ɣ�" << endl;
				break;

			}
			
		}
	
		cout << "�����Ŵ������������룺";
	}

	system("pause");
	system("cls");
}