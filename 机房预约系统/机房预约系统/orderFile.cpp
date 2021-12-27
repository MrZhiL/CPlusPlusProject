#include "orderFile.h"

// ���캯����ʵ�ֶ�ȡԤԼ����
OrderFileManager::OrderFileManager() {

	// �ڹ��캯����ʵ�ֶ�ȡԤԼ��¼���ñ�ѧ����ѯ
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string dateNum;		// order.txt��ѧ��ԤԼ������
	string intervalNum; // order.txt��ѧ��ԤԼ��ʱ���
	string stuId;		// order.txt��ԤԼ��ѧ����ѧ��
	string stuName;		// order.txt��ѧ��ԤԼ������
	string roomId;		// order.txt��ѧ��ԤԼ�Ļ����ı��
	string status;		// order.txt��ѧ��ԤԼ��״̬
	
	this->orderNum = 0;

	// ����whileѭ����order.txt�е����ݶ�ȡ����
	while (ifs >> dateNum && ifs >> intervalNum && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		
		/* // ��ӡ����
		cout << dateNum << endl;
		cout << intervalNum << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << comNum << endl;
		cout << status << endl;
		cout << endl;  */

		// ����ȡ���������ݴ�ŵ�map������
		map<string, string> mTemp;

		string key;		// ������ż�ֵ
		string value;	// �������value

		// ��dateNum�е�keyֵ��valueֵ�ֿ�
		int pos = dateNum.find(":");

		if (pos != -1) {
			key = dateNum.substr(0,pos);
			value = dateNum.substr(pos+1, dateNum.size()-pos-1);

			// ��dateNum��Ԫ�ز��뵽mTemp������
			mTemp.insert(make_pair(key,value));
						
		}

		// ��intervalNum�е�keyֵ��valueֵ�ֿ�
		pos = intervalNum.find(":");

		if (pos != -1) {
			key = intervalNum.substr(0, pos);
			value = intervalNum.substr(pos + 1, intervalNum.size() - pos - 1);

			// ��dateNum��Ԫ�ز��뵽mTemp������
			mTemp.insert(make_pair(key, value));
						
		}

		// ��stuId�е�keyֵ��valueֵ�ֿ�
		pos = stuId.find(":");

		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);

			// ��dateNum��Ԫ�ز��뵽mTemp������
			mTemp.insert(make_pair(key, value));

		}

		// ��stuName�е�keyֵ��valueֵ�ֿ�
		pos = stuName.find(":");

		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);

			// ��dateNum��Ԫ�ز��뵽mTemp������
			mTemp.insert(make_pair(key, value));

		}

		// ��comNum�е�keyֵ��valueֵ�ֿ�
		pos = roomId.find(":");

		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);

			// ��dateNum��Ԫ�ز��뵽mTemp������
			mTemp.insert(make_pair(key, value));

		}

		// ��status�е�keyֵ��valueֵ�ֿ�
		pos = status.find(":");

		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			// ��dateNum��Ԫ�ز��뵽mTemp������
			mTemp.insert(make_pair(key, value));

		}

		// ��dateNum�����ݲ��뵽��������
		this->orderFileMap.insert(make_pair(this->orderNum, mTemp));
		this->orderNum++;

	}

	cout << "orderFile�й������ݣ�" << this->orderFileMap.size() << endl;
	// ���Դ��������Ƿ�ɹ���������
	/*
	for (map<int, map<string, string>>::iterator it = this->orderFileMap.begin(); it != this->orderFileMap.end(); it++) {
		cout << "ԤԼ��ţ�" << it->first << "ԤԼ��ϢΪ��" << endl;
		for (map<string, string>::iterator stuIt = (*it).second.begin(); stuIt != it->second.end(); stuIt++) {
			cout << stuIt->first << " " << stuIt->second << endl;
		}
		cout << "---------------------------------------------" << endl;
	}
	*/
	// cout << "��ȡ���" << endl;
	//system("pause");
	//system("cls");

	ifs.close();

}

// ����order.txt�ļ��е�ԤԼ����
void OrderFileManager::updateOrderFileFunc() {
	/*
	string dateNum;		// order.txt��ѧ��ԤԼ������
	string intervalNum; // order.txt��ѧ��ԤԼ��ʱ���
	string stuId;		// order.txt��ԤԼ��ѧ����ѧ��
	string stuName;		// order.txt��ѧ��ԤԼ������
	string roomId;		// order.txt��ѧ��ԤԼ�Ļ����ı��
	string status;		// order.txt��ѧ��ԤԼ��״̬
	*/
	
	// ���ж�ԤԼ��Ŀ�Ƿ�Ϊ0�����Ϊ0���˳�
	if (this->orderNum == 0) {
		return;
	}

	// ���ԤԼ������Ϊ�գ������ԤԼ����
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	
	// ��ӡ����
	for (int i = 0; i < this->orderNum; i++) {
		ofs << "date:" << this->orderFileMap[i]["date"] << " ";
		ofs << "interval:" << this->orderFileMap[i]["interval"] << " ";
		ofs << "stuId:" << this->orderFileMap[i]["stuId"] << " ";
		ofs << "stuName:" << this->orderFileMap[i]["stuName"] << " ";
		ofs << "roomId:" << this->orderFileMap[i]["roomId"] << " ";
		ofs << "status:" << this->orderFileMap[i]["status"] << endl;
	}

}