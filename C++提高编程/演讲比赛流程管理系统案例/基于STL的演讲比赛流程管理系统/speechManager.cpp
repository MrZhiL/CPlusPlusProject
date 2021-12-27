#include "speechManager.h"


// ���캯��
speechManager::speechManager(){
	this->initSpeech();		// ��ʼ��ѡ������
	this->createSpeaker();	// ����ѡ�� 
	this->loadRecord();		// ��ȡ�ļ��е����� 
}


// �˵�����ʵ�֣����û��Ĺ�ͨ���棩
void speechManager::show_Menu(){
	cout << "********************************" << endl;
	cout << "******* ��ӭ�μ��ݽ����� *******" << endl;
	cout << "******* 1����ʼ�ݽ�����  *******" << endl; 
	cout << "******* 2���鿴�����¼  *******" << endl; 
	cout << "******* 3����ձ�����¼  *******" << endl; 
	cout << "******* 0���˳���������  *******" << endl; 
	cout << endl; 
}

// ��ʼ��ѡ�ֺ��� 
void speechManager::initSpeech(){
	// ��������е��������ݣ�ȷ����ʼ��������Ϊ�� 
	this->v1.clear();
	this->v2.clear();
	this->vVector.clear();
	
	this->m_Speaker.clear();
	
	// ��ʼ�������Ϊ��һ��
	this->m_Index = 1; 
	
	// ��ʼ��ѡ�ּ�¼����
	this->record_Speech.clear();
}

// ����12��ѡ��
void speechManager::createSpeaker(){
	
	string nameSeed = "ABCDEFJHIGKL";	//ѡ����������
	
	for(int i=0; i<12; i++){
		
		Speaker sp;	// ����ѡ����
		string name = "ѡ��";
		sp.m_Name += nameSeed[i];
		
		// ��ʼ��ѡ�ֵĳɼ�Ϊ0 
		for(int j=0; j<2; j++){
			sp.m_Score[j] = 0;
		}		
		
		// ��ѡ�ָ��費ͬ�ı��
		this->v1.push_back(i+10001);
		
		// ����źͶ�Ӧ�ľ���ѡ����ϵ��һ��
		this->m_Speaker.insert(make_pair(i+10001, sp)); 
	} 
	
}

// ��ʼ��������,�ú���������ҪΪ���Ʊ���������
// ����������Ϊ�� 
void speechManager::startSpeech(){
	
	/**��һ�ֱ���*/ 
	
	// 1����ǩ
	this->speechDraw(); 
	
	// 2������
	this->speechContest();
	
	// 3����ʾ�������
	this->showScore();
	
	/**�ڶ��ֱ���*/ 
	this->m_Index++;
	
	// 1����ǩ
	this->speechDraw();
	
	// 2������
	this->speechContest();
	
	// 3����ʾ���ս�� 
	this->showScore();
	
	// 4���������
	this->saveRecord(); 
	
	// ���ñ�����ѡ��
	this->initSpeech();		// ��ʼ��ѡ������
	this->createSpeaker();	// ����ѡ�� 
	this->loadRecord();		// ��ȡ�ļ��е����� 

	cout << "����������@" << endl;
	system("pause");
	system("cls"); 
	
}

// ѡ�ֳ�ǩ����
void speechManager::speechDraw(){
	
	//��ʾ�û�Ϊ�ڼ��ֳ�ǩ
	cout << "��" << this->m_Index << "�ֱ����û���ǩ��" << endl;
	cout << "----------------------------------------------" << endl;
	
	if(this->m_Index == 1){
		cout << "��һ�ֳ�ǩ���˳��Ϊ��" << endl; 
		random_shuffle(v1.begin(), v1.end());
		for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
			cout << *it << "   ";
		}
		cout << endl;
	} else{
		cout << "�ڶ��ֳ�ǩ���˳��Ϊ��" << endl; 
		random_shuffle(v2.begin(), v2.end());
		for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
			cout << *it << "   ";
		}
		cout << endl;
	}
	cout << "----------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

// ��������
void speechManager::speechContest(){
	
	cout << "---------- ��" << this->m_Index << "�ֱ�����ʼ��----------" << endl;
	cout << "-------------------------------------------" << endl;
	
	// num������¼��ǰѡ�ֵ����� 
	int num = 0; 
	
	// ������ʱ��������������ѡ�ֵı�źͶ�Ӧ�ĳɼ� 
	multimap<double, int, greater<double> > groupvect;
	
	// ������vTmep����������¼����ѡ�ֵ���Ϣ 
	vector<int> vTmep; 
	
	if(this->m_Index == 1){
		vTmep = v1;
	} else {
		vTmep = v2;
	}
	
	// ��forѭ�������ж�ѡ�ֵĳɼ�,�������в���ѡ�� 
	for(vector<int>::iterator it = vTmep.begin(); it != vTmep.end(); it++){
		
		// deqScore������¼ѡ�ֵĳɼ� 
		deque<double> deqScore;
		
		num++; 
		
		// �ж�ѡ�ֵĳɼ�������10λ��ί����ί���Ϊ60.0-100.0�� 
		for(int i=0; i<10; i++){
			double score = (rand()%400+600)/10.f;
			deqScore.push_back(score);		//��ί��ֳɼ� 
			//cout << score << endl;
		} 
		// ��10λ��ί�Ĵ�ֽ��н������� 
		sort(deqScore.begin(), deqScore.end(), greater<double>());
		
		// ȥ����߷ֺ���ͷ�
		deqScore.pop_back();
		deqScore.pop_front();
		
		// ����ȥ����߷ֺ���ͷֺ��ƽ����
		double aveScore = accumulate(deqScore.begin(), deqScore.end(), 0.0f) / (double)deqScore.size();	//accumulate������numericͷ�ļ��� 
		//cout << "ѡ��" << *it << " ��ƽ���ɼ�Ϊ��" << aveScore << endl;
		
		this->m_Speaker[*it].m_Score[this->m_Index-1] = aveScore;
		
		// ��ѡ�ֵĳɼ����뵽groupScore������
		groupvect.insert(make_pair(aveScore, *it)); 
		
		//cout << "ѡ�ֱ�ţ�" << *it << "�� ����Ϊ�� " << this->m_Speaker[*it].m_Name << ", �ɼ�Ϊ��" << aveScore << endl; 
		
		// ÿ6��ѡ��һ��,ȡ��ÿ��ɼ��е�ǰ����
		if(num % 6 == 0){
			
			cout << "��" << num/6 << "С���������Ϊ��" << endl;
			
			for(multimap<double, int,  greater<double> >::iterator it2 = groupvect.begin(); it2 != groupvect.end(); it2++){
				cout << "ѡ�ֱ�ţ�" << it2->second << "�� ����Ϊ�� " << this->m_Speaker[it2->second].m_Name << ", �ɼ�Ϊ��" << it2->first << endl; 
			} 
			
			// ȡ��ǰ����ѡ�ֵĳɼ�
			int count = 0;
			for(multimap<double, int, greater<double> >::iterator it2 = groupvect.begin(); it2 != groupvect.end() && count < 3; it2++, count++){
				if(this->m_Index == 1){
					this->v2.push_back(it2->second);
				}else{
					this->vVector.push_back(it2->second);
				}
			}
			 
			// ÿ��ȥ���ɼ�����������е�Ԫ�� 
			groupvect.clear();
			
			cout << endl;
		} 
	}
	
	cout << "------------ ��" << this->m_Index << "�ֱ������� --------------" << endl;
	system("pause"); 
	
	//this->m_Index++;
	
//	system("cls");
//	this->show_Menu();
}

// ��ʾ�������� 
void speechManager::showScore(){
	cout << "---------- ��" << this->m_Index << "�ֱ������Ϊ��----------" << endl;
	
	vector<int> vTemp;
	
	if(this->m_Index == 1){
		vTemp = this->v2;
	}else{
		vTemp = this->vVector;
	}
	
	for(vector<int>::iterator it = vTemp.begin(); it != vTemp.end(); it++){
		cout << "ѡ�ֱ��Ϊ��" << *it
			 << ", ѡ������Ϊ��" << this->m_Speaker[*it].m_Name
			 << ", ѡ�ֵ�ƽ���ɼ�Ϊ�� " << this->m_Speaker[*it].m_Score[this->m_Index-1] 
			 << endl;
	}
	
	cout << "---------- ѡ�ֳɼ���ʾ������----------" << endl;
	cout << endl;
	
	system("pause");
	system("cls");
	//this->show_Menu();
	 
} 

// �������
void speechManager::saveRecord(){
	ofstream ofs;
	// ��׷�ӷ�ʽ���ļ� 
	ofs.open("speech.csv", ios::out | ios::app);
	
	for(vector<int>::iterator it = this->vVector.begin(); it != this->vVector.end(); it++){
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << "\n";
	
	ofs.close();
	cout << "---------- ǰ�����ɼ�������ɣ�----------" << endl;
	this->fileIsEmpty = false;
}

// ��ȡ�����¼
void speechManager::loadRecord(){
	
	// ��ȡ�ļ��е�����
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	
	// �ж��ļ��Ƿ����,����ļ����������˳��ú��� 
	if(!ifs.is_open()){
		//cout << "�ļ������ڣ�" << endl;
		this->fileIsEmpty = true; 
		return ;
	}
	
	// ��char�ַ������ж��ļ��Ƿ�Ϊ�� 
	char ch; 
	ifs >> ch;
	
	// �ж��ļ��Ƿ�Ϊ�գ����Ϊ�գ����˳� 
	if(ifs.eof()){
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		return ;
	} 
	
	// ����ļ���Ϊ�գ�����Ҫ��ch�ַ����·Żص�������
	ifs.putback(ch);
	
	// ��ȡ�ļ��е����� 
	string data;
	int index = 0;	// ���±�������¼�ڼ�������
	while(ifs >> data){
		// ��ӡ���� 
		//cout << data << endl; 
		//cout << "------------" << endl; 
		
		// ��vTemp����������¼data�е�Ԫ�� 
		vector<string> vTemp; 
		
		// ��pos������¼","��λ�� ,start������¼���ҵ�λ�ã�Ĭ�ϴ�0��ʼ 
		int pos = -1;
		int start = 0;
		// temp������¼ÿ��Ԫ�� 
		string temp;
		
		while(true){
			
			pos = data.find(",", start);
			
			// �ж�data���Ƿ����ҵ�dataĩβ�������ĩβ���˳�ѭ�� 
			if(pos == -1){
				break;
			} 
			
			// ��ȡ���ŷָ�֮ǰ��Ԫ�� 
			temp = data.substr(start, pos-start); 
			//cout << temp << endl; 
			 
			start = pos + 1;
			
			// ��temp�е�Ԫ�ز��뵽vTemp������ 
			vTemp.push_back(temp); 
		} 
		this->fileIsEmpty = false;
		// ��ifs�ļ��е����ݴ�ŵ� record_Speech������
		this->record_Speech.insert(make_pair(index, vTemp));
		index++;
	}
	
//	// ��ӡ����
//	for(map<int, vector<string> >::iterator it = this->record_Speech.begin(); it != this->record_Speech.end(); it++){
//		cout << "�� " << it->first << " ������Ĺھ�Ϊ��" << it->second[0] << "�� �ɼ�Ϊ��" << it->second[1] << endl;
//		cout << "�� " << it->first << " ��������Ǿ�Ϊ��" << it->second[2] << "�� �ɼ�Ϊ��" << it->second[3] << endl;
//		cout << "�� " << it->first << " ������ļ���Ϊ��" << it->second[4] << "�� �ɼ�Ϊ��" << it->second[5] << endl;
//		cout << "-------------------------------" << endl; 
//	} 
	
	ifs.close();
	
} 

// �鿴�����¼
void speechManager::showRecord(){
	// ��ȡ�����¼������ӡ 
	this->loadRecord();
	if(this->fileIsEmpty){
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
		this->record_Speech.clear();
	}
	
	for(int i = 0; i < this->record_Speech.size(); i++){
		cout << "��" << i+1 << "��ı����ɼ�Ϊ��" << endl;
		cout << "�ھ���ţ�" << this->record_Speech[i][0] << ", �ɼ���" << this->record_Speech[i][1] << endl; 
		cout << "�Ǿ���ţ�" << this->record_Speech[i][2] << ", �ɼ���" << this->record_Speech[i][3] << endl; 
		cout << "������ţ�" << this->record_Speech[i][4] << ", �ɼ���" << this->record_Speech[i][5] << endl; 
		cout << "----------------------------" << endl; 
	}
	system("pause");
	system("cls");
}

// ����ļ��е���������
void speechManager::clearRecore(){
	
	cout << "��ȷ���Ƿ�����������ݣ�ȷ��Y���˳�N::::";
	char temp;
	cin >> temp;
	
	if(temp == 'Y'){
		ofstream ofs;
		// ��ģʽ��ios::trunc  ����ļ�������ɾ���ļ������´��� 
		ofs.open("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		
		cout << "��ճɹ�@" << endl; 
	}else{
		return;
	}
	
	system("pause");
	system("cls");
	
} 

// �˳����ܣ�ʵ���˳����� 
void speechManager::exitSystem(){
	
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);	
}
		
// �������� 
speechManager::~speechManager(){
	
}

