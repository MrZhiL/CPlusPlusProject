#include <iostream>
#include <fstream>
#include "speechManager.h" 
#include <string>
#include <ctime> 

using namespace std;

// �ݽ��������̹���ϵͳ 

void testCreatreSpeaker(const speechManager &sp){
	// ��ӡѡ����Ϣ 
	for(map<int, Speaker>::const_iterator it = sp.m_Speaker.begin(); it != sp.m_Speaker.end(); it++){
		cout << "ѡ�ֵı��Ϊ��" << it->first
			 << ",  ѡ�ֵ�����Ϊ��" << it->second.m_Name 
			 << ",  ѡ�ֵĳɼ�Ϊ��" << it->second.m_Score[0]
			 << endl;
	}
}

int main(int argc, char** argv) {
	
	srand((unsigned int)time(NULL));
	
	speechManager speechMan;
	
	//// ����ѡ���Ƿ񴴽��ɹ� 
	//testCreatreSpeaker(speechMan);
	
	// ����ѡ��	
	int swit_num;
	
	while (true){
		
		// ��ʾ�˵����� 
		speechMan.show_Menu();
		
		// �ж��û������룬��������Ӧ�Ĳ��� 
		cout << "������Ҫ������ѡ�";
		cin >> swit_num;
		
		while(swit_num > 3 || swit_num < 0){
			cout << "�������!����������(0-3):";
			cin >> swit_num; 
		} 
		 
		switch(swit_num){
			// 1����ʼ���� 
			case 1:
				speechMan.startSpeech();
				break;
			// 2���鿴���������¼ 
			case 2:
				speechMan.showRecord();
				break;
			// 3����ձ�����¼ 
			case 3:
				speechMan.clearRecore();
				break;
			// 0���˳�����ϵͳ 
			case 0: 
				speechMan.exitSystem();
				break;
			// ����������� 
			default:
				system("cls");
				break;	
		}
	}
	
	
	system("pause");
	return 0;
}
