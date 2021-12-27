#include <iostream>
#include <fstream>
#include <string>
#include "workerManager.h" 
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h" 

using namespace std; 

// ְ������ϵͳ
/** 
	����ϵͳ����Ҫʵ�ֵĹ������£�
	1���˳���������˳���ǰ����ϵͳ
	2������ְ����Ϣ��ʵ���������ְ������
	3����ʾְ����Ϣ����ʾ��˾�ڲ�����ְ������Ϣ
	4��ɾ����ְְ�������ձ��ɾ��ָ����Ա��
	5���޸�ְ����Ϣ�����ձ���޸�ָ��ְ������Ϣ
	6������ְ����Ϣ������ְ���ı�Ż���ְ�����������в������Ա������Ϣ 
	7�����ձ�����򣺰���ְ����ţ�������������������û�ָ�� 
	8����������ĵ�������ļ��м�¼������ְ����Ϣ�����ǰ��Ҫ�ٴ�ȷ�ϣ���ֹ��ɾ�� 
*/	

void test01(){
	Worker *emp = new employee(110, "����", 3);
	Worker *mag = new manager(1, "����", 2);
	Worker *bos = new boss(0, "����", 1);
	
	emp->showInfo();
	cout << emp->m_Name << "��ְλΪ��" << emp->showDepart() << endl;
	delete emp;
	
	mag->showInfo();
	cout << mag->m_Name << "��ְλΪ��" << mag->showDepart() << endl;
	delete mag;
	
	bos->showInfo();
	cout << bos->m_Name << "��ְλΪ��" << bos->showDepart() << endl;
	delete bos;
}

void test02(WorkerManager &workerM){
	
	workerM.InitEmpArray();
	
	for(int i=0; i < workerM.m_EmpNum; i++){
		workerM.m_EmpArray[i]->showInfo();
	}
}

int main() {
	
	// ���������� 
	WorkerManager workerM;
	//test01();
	//test02(workerM);
	
	// choiceΪ��¼�û���ѡ�� 
	int choice;
	
	while(true){
		// ��ʾ�������� 
		workerM.showMenu();

		cout << "����������ѡ��"; 
		
		// ��ȡ�û���ѡ��
		cin >> choice;
		
		switch(choice){
			
			// �˳�����ϵͳ 
			case 0:
				workerM.ExitSystem(); 
				break;
			// ���ְ�� 
			case 1:
				workerM.addEmp();
				break;
			// ��ʾְ����Ϣ 
			case 2:
				workerM.show_Emp();
				break;
			// ɾ��ְ�� 
			case 3:
				workerM.del_Emp();
				break;
			// �޸�ְ����Ϣ 
			case 4:
				workerM.Mod_Emp();
				break;
			// ����ְ�� 
			case 5:
				workerM.Find_Emp();
				break;
			// ��ְ������ 
			case 6:
				workerM.Sort_Emp();
				break;
			// �������ְ����Ϣ�������ȷ�ϣ� 
			case 7:
				workerM.ClearAll_Emp();
				break;
			
			default:
				system("cls");
				break;
		} 
		
	} 
	
	
	system("pause"); 
	return 0;
}

