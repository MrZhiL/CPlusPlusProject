#include <iostream>

using namespace std;
 
int main() {
	
	// break��ʹ��ʱ��
	
	// 1��������switch�����
	
//	int select; // ����ѡ�����ı���
//	select = 0;
//	
//	cout << "��ѡ��Ҫ���еĶ���" << endl;
//	cout << "1��Sleep" << endl;
//	cout << "2��Study" << endl;
//	cout << "3��Exercise" << endl; 
//	
//	cin >> select;
//	
//	switch(select){
//		
//		case 1: 
//			cout << "��ѡ��Ķ�����Sleep" << endl;   
//			break; // �Ƴ�switch��䣬�����дbreak���ִ������������� 
//		case 2:
//			 cout << "��ѡ��Ķ�����Study" << endl;
//			 break;
//		case 3:
//			cout << "��ѡ��Ķ�����Exercise" << endl;
//			break;
//		default: 
//		
//		break;
//	}
//	
//	 
	// 2��������ѭ�������
//	
//	for(int i=0;i<10;i++){
//		
//		if(i>5){
//			break;
//		}
//		
//		cout << i << endl;
//	}

	
//	// 3��������Ƕ��ѭ�������
//	
//	for(int i=0;i<10;i++){
//		
//		for(int j=0; j<10; j++){
//			if(j>5)	break;
//			cout << "* " ;
//		}
//
//		cout << endl;
//	}

	// 4��continue�÷�
	int i;
	
	for (i=1; i<=10; i++){
		if(i%2 == 0){
			continue;
		}
		cout << i << endl;
	} 
	
	system("pause");
	return 0; 
}
