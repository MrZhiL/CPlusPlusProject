#include "Student.h"

// Ĭ�Ϲ��캯��
Student::Student() {

}

// �вι��캯��, ������ѧ�š�����������
Student::Student(int id, string name, string pwd) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ʼ��������Ϣ
	// comRTempΪ��ʱ������������¼������Ϣ
	ComputerRoom comRTemp;
	
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	// ��ȡ������Ϣ������Ϣ���浽comRTemp������
	while (ifs >> comRTemp.m_Num&& ifs >> comRTemp.m_MaxCap) {
		this->vComDemo.push_back(comRTemp);
	}

	ifs.close();

}

// �����˵����麯�������������д�ú�����Ҫ��Ȼ����ҲΪ�������
void Student::operMeun() {
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           1������ԤԼ             |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           2���鿴�ҵ�ԤԼ         |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           3���鿴����ԤԼ         |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           4��ȡ��ԤԼ             |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|           0��ע����¼             |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;
}

// ԤԼ����
void Student::applyOrder() {
	cout << "����ԤԼ��ʱ��Ϊ��һ�����壡" << endl;
	cout << "1����һ  2���ܶ�  3������  4������  5������" << endl;
	cout << "��ѡ��ҪԤԼ�����ڣ�";

	int dateNum;		// ԤԼ�����ڣ���һ �� ���壩
	int intervalNum;	// ԤԼ��ʱ��Σ����硢���磩
	int roomNum;		// ԤԼ�Ļ�����ţ�1��2��3��

	while (true) {
		cin >> dateNum;
		if (dateNum >= 1 && dateNum <= 5) {
			break;
		}
		cout << "ѡ�����ڲ��ڷ�Χ�ڣ����������루1-5����";
	}

	cout << "��ѡ��ԤԼ��ʱ��Σ�1������   2�����磩��";
	while (true) {
		cin >> intervalNum;
		if (intervalNum >= 1 && intervalNum <= 2) {
			break;
		}
		cout << "ѡ��ʱ��β��ڷ�Χ�ڣ����������루1/2����";
	}

	for (vector<ComputerRoom>::iterator it = this->vComDemo.begin(); it != this->vComDemo.end(); it++) {
		cout << "�������Ϊ��" << it->m_Num << "�� ��������Ϊ" << it->m_MaxCap << endl;
	}

	cout << "��ѡ��ҪԤԼ�Ļ�����";
	while (true) {
		cin >> roomNum;
		if (roomNum >= 1 && roomNum <= this->vComDemo.size()) {
			break;
		}
		cout << "ѡ��Ļ����������������룺";
	}

	cout << "ԤԼ�ɹ������ڽ������!" << endl;

	// ��ѧ��ԤԼ�Ľ�����浽order.txt��
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << dateNum << " "
		<< "interval:" << intervalNum << " "
		<< "stuId:" << this->m_id << " "
		<< "stuName:" << this->m_Name << " "
		<< "roomId:" << roomNum << " "
		<< "status:" << 1						// 1����ʾԤԼ���������
		<< endl;

	ofs.close();

	system("pause");
	system("cls");
}

// ��ʾ����ԤԼ����
void Student::showMyOrder() {
	OrderFileManager ofm;

	// ���жϻ����Ƿ���ԤԼ��¼
	if (ofm.orderNum == 0) {
		cout << "����û��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����ԤԼ��¼Ϊ��" <<  endl; 
	for (int i = 0; i < ofm.orderNum; i++) {
		
		// �ж�����id��ԤԼ��¼���Ƿ���ڣ�������ڣ��򷵻�������Ϣ
		// ��Ϊofm.orderFileMap�����д�ŵ�ѧ��idΪstring���ͣ������ҪתΪint����
		// stringתΪint���͵ķ�����
		// 1������ʹ��.c_str()������string����תΪC�����е�const char*����
		// 2��ʹ��atoi(const char*)������const char*����ת��Ϊint����
		if (this->m_id == atoi(ofm.orderFileMap[i]["stuId"].c_str())) {
			cout << "ԤԼ���ڣ���" << ofm.orderFileMap[i]["date"] << endl;
			cout << "ԤԼʱ��Σ�" << ( ofm.orderFileMap[i]["interval"] == "1" ? "����":"����") << endl;
			cout << "ԤԼ�Ļ�����ţ�" << ofm.orderFileMap[i]["roomId"] << endl;
			
			string status = "״̬��";
			// �ж�ѧ��ԤԼ��״̬��1�����  2ԤԼ�ɹ� -1ԤԼʧ�� 0ȡ��ԤԼ
			if (ofm.orderFileMap[i]["status"] == "1") {
				status += "�����";
			}
			else if (ofm.orderFileMap[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (ofm.orderFileMap[i]["status"] == "-1"){
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else {
				status += "ȡ��ԤԼ";
			}

			cout << status << endl;
			cout << "-------------------------------------------" << endl;
		}
	}

	/*
	string dateNum;		// order.txt��ѧ��ԤԼ������
	string intervalNum; // order.txt��ѧ��ԤԼ��ʱ���
	string stuId;		// order.txt��ԤԼ��ѧ����ѧ��
	string stuName;		// order.txt��ѧ��ԤԼ������
	string roomId;		// order.txt��ѧ��ԤԼ�Ļ����ı��
	string status;		// order.txt��ѧ��ԤԼ��״̬
	*/
	system("pause");
	system("cls");
}

// ��ʾ����ԤԼ���������ݶ�����Ҫ��ҳ��ѯ��
void Student::showAllOrder() {
	OrderFileManager ofm;

	// �ж��Ƿ���ԤԼ��¼�����û��ԤԼ��¼����ֱ���˳�
	if (ofm.orderNum == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ��ԤԼ��¼��Ϊ��ʱ����ԤԼ��Ϣ��ӡ
	for (int i = 0; i < ofm.orderNum; i++) {
		cout << "��" << i + 1 << "����¼Ϊ��";
		
		cout << "���ڣ���" << ofm.orderFileMap[i]["date"] << endl;
		cout << "ʱ��Σ�" << (ofm.orderFileMap[i]["interval"] = 1 ? "����":"����") << endl;
		cout << "ѧ��ѧ��Ϊ��" << ofm.orderFileMap[i]["stuId"] << endl;
		cout << "ѧ������Ϊ��" << ofm.orderFileMap[i]["stuName"] << endl;
		cout << "ԤԼ����Ϊ��" << ofm.orderFileMap[i]["roomId"] << endl;
		string status = "״̬Ϊ��";
		
		// stauts = 1(ԤԼ��)�� 2��ԤԼ�ɹ�����-1��ԤԼʧ��)��0��ȡ��ԤԼ��
		if ( (ofm.orderFileMap[i]["status"]) == "1") {
			status += "ԤԼ��";
		}
		else if ((ofm.orderFileMap[i]["status"]) == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if ((ofm.orderFileMap[i]["status"]) == "-1") {
			status += "ԤԼʧ��";
		}
		else {
			status += "ȡ��ԤԼ";
		}

		cout << status << endl;
		cout << "------------------------" << endl;
	}
	system("pause");
	system("cls");
}

// ȡ��ԤԼ����
void Student::cancelOrder() {
	OrderFileManager ofm;

	// �ж��Ƿ���ԤԼ��¼
	if (ofm.orderNum == 0) {
		cout << "ԤԼΪ�գ�" << endl;
		system("pause");
		system("cls");
		return ;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v; // ��¼ѧ����ԤԼ����

	int index = 1;

	// ���ԤԼ��Ϊ�գ�����ʾ�����ԤԼ��¼
	for (int i = 0; i < ofm.orderNum; i++) {
		if (this->m_id == atoi(ofm.orderFileMap[i]["stuId"].c_str())) {
			
			// ��ɸѡ״̬������л�ԤԼ�ɹ��Ŀ���ȡ��
			if ( ofm.orderFileMap[i]["status"] == "1" || ofm.orderFileMap[i]["status"] == "2" ) {
				
				v.push_back(i);		// ��ѧ��ԤԼ���±��ŵ�vector������
				
				// ��ӡ����ԤԼ��¼
				cout << "��" << index++ << "����¼��"
					<< "����: ��" << ofm.orderFileMap[i]["date"] << " "
					<< "ʱ���: " << (ofm.orderFileMap[i]["interval"] = 1 ? "����" : "����") << " "
					<< "ԤԼ������ : " << ofm.orderFileMap[i]["roomId"] << " ";

				string  status = "״̬��";

				if (ofm.orderFileMap[i]["status"] == "1") {
					status += "�����";
				}
				else if (ofm.orderFileMap[i]["status"] == "2") {
					status += "��˳ɹ�";
				}
				else if (ofm.orderFileMap[i]["status"] == "-1") {
					status += "ԤԼʧ��";
				}
				else {
					status += "ȡ��ԤԼ";
				}

				cout << status << endl;
			}
		}
	}

	cout << "������Ҫȡ���ı��,0����ȡ����";
	int select = 0;

	while (true) {
		cin >> select;

		// �ж�����ı�ţ���ȡ������ԤԼ
		// �ж�����ı���Ƿ��ں���Χ��
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

		cout << "�����������������룺";
	}
	cout << "ȡ���ɹ�@" << endl;
	system("pause");
	system("cls");
}