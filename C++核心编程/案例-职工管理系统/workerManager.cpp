#include "workerManager.h"

WorkerManager::WorkerManager(){
	
	
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	
	// 1������ļ������� 
	if( !ifs.is_open()) {
		//cout << "�ļ������ڣ�" << endl;  // ���Դ��룬�����ӡ 
		
		// ��ʼ��ְ����Ϣ 
		this->m_EmpNum = 0;			// ��ʼ������ 
		this->m_EmpArray = NULL;	// ��ʼ������ 
		// ��־�ļ������� 
		this->m_FileIsEmpty = true;	
		
		ifs.close();
		// ����ļ������ڣ��򲻽��к���������ֱ���˳� 
		return ;
	}
	
	// 2���ļ����ڣ�������Ϊ��
	char ch;
	
	// ����ļ�Ϊ�գ�����ļ���ֻ��һ����β��־('\0')����ʱ����β��־ȡ������ֻʣEOF��־�� 
	ifs >> ch;  
	// �����ʱ�ļ���־ΪEOF,���ļ�Ϊ�� 
	if (ifs.eof()){
		// ���ifs.eof()����Ϊ�棬���ļ�Ϊ���ļ� 
		cout << "���ļ�Ϊ��!" << endl;	// ���Դ���
		
		// ��ʼ��ְ����Ϣ 
		this->m_EmpNum = 0;			// ��ʼ������ 
		this->m_EmpArray = NULL;	// ��ʼ������ 
		// ��־�ļ������� 
		this->m_FileIsEmpty = true;	
		
		ifs.close();
		// ����ļ������ڣ��򲻽��к���������ֱ���˳� 
		return ;
	} 
	
	// 3���ļ������Ҳ�Ϊ��
	int num = this->getEmpNum();
	
	//cout << "ְ������Ϊ��" << num << endl; 
	
	this->m_EmpNum = num; 
	
	// ����ְ�������������� ��new *Worker �� new Worker *��������ʲô�� 
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	
	this->InitEmpArray();
}

// չʾ�˵� 
void WorkerManager::showMenu(){
			
	cout << "*******************************" << endl;
	cout << "****** 0���˳�����ϵͳ ********" << endl;
	cout << "****** 1������ְ����Ϣ ********" << endl;
	cout << "****** 2����ʾְ����Ϣ ********" << endl;
	cout << "****** 3��ɾ����ְְ�� ********" << endl;
	cout << "****** 4���޸�ְ����Ϣ ********" << endl;
	cout << "****** 5������ְ����Ϣ ********" << endl;
	cout << "****** 6�����ձ������ ********" << endl;
	cout << "****** 7����������ĵ� ********" << endl;
	cout << "*******************************" << endl;
	
} 

// �˳�ְ������ϵͳ 
void WorkerManager::ExitSystem(){
	
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	// �����⵽exit(0)���˳� 
	exit(0); 
	
} 


// ���ְ������
void WorkerManager::addEmp(){
	
	// ���ְ�������� 
	int addNum;
	
	// ��ʾ�����ְ�������� 
	cout << "�����������ְ����������1-100��:" ;
	cin >> addNum;
	
	// �ж�����������Ƿ���� 
	if (addNum > 0){
		
		// �����µĿռ��С���ܵ�ְ������ = ԭ�е�ְ������ + �µ�ְ������
		int newArrayNum = this->m_EmpNum + addNum; 
		
		// �����¿ռ䣺�����µ�ְ������
		Worker ** newArray = new Worker*[newArrayNum]; 
		
		// ��ԭ�е�ְ�����¸�ֵ�������飨��Ҫ�ж�ԭ��ְ���������Ƿ�Ϊ��) 
		if(this->m_EmpArray != NULL){
			
			for(int i=0; i < this->m_EmpNum; i++){
				newArray[i] = this->m_EmpArray[i];
			}
		}
		
		int id;			//��ְ���ı�� 
		string name;	//��ְ�������� 
		int dNum; 		//��ְ���ĸ�λ
	
		// ������������� 
		for(int i=0; i < addNum; i++){
			
			cout << "�������" << i+1 << "����ְ���ı��:" ;
			cin >> id;
			
			cout << "�������" << i+1 << "����ְ��������:" ;
			cin >> name; 
			
			cout << "��ѡ����ְ���ĸ�λ��1��ְ��  2������  3���ϰ�  ��";
			cin >> dNum;
			cout << endl;
			
			Worker *worker = NULL; 
			 
			// �ж���ְ���ĸ�λ����������ͬ���������� 
			switch (dNum){
				case 1:
					worker= new employee(id,name,1);
					break;
					
				case 2:
					worker = new manager(id,name,2);
					break;
				
				case 3:
					worker = new boss(id,name,3);
					break;
				
				default:
					cout << "�����λ�������������룺" << endl;
					//cin >> dNum;
					//goto loop;
					break; 
			}
			
			newArray[this->m_EmpNum + i] =                                                                                 worker;
//			delete worker; // �����ͷŸ��ڴ棬���������ڴ���󣬵��½�����󣡣��� 
		} 
		
		// �ͷ�ԭ�е��ڴ�
		delete [] this->m_EmpArray;
		
		// ��this->m_EmpArray ָ���µ��ڴ�����
		this->m_EmpArray = newArray;
		
		// �����µ�ְ������
		this->m_EmpNum =  newArrayNum;
		
		// ����ɹ������ְ��������ʾ�ɹ���ӣ����������ݵ��ı��ĵ��� 
		cout << "�ɹ����" << addNum << "λְ����" << endl;
		// ���������ӳɹ����򽫱�ʶ�� m_FileIsEmpty ��Ϊflase����ʾ�ļ���Ϊ�� 
		this->m_FileIsEmpty = false; 
		this->save(); 
		
	}else{
		cout << "�����������ں���Χ�ڣ������루1-100��֮�������!" << endl;
	}
	
	// ��ӳɹ��󣬽����ݱ��浽�ı��ļ���,�����������
	system("pause");
	system("cls");
	
}

// �����ļ�����
void WorkerManager::save(){
	
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	
	for(int i=0; i<this->m_EmpNum; i++){
		ofs << this->m_EmpArray[i]->m_Num
			<< " " << this->m_EmpArray[i]->m_Name
			<< " " << this->m_EmpArray[i]->m_Depart 
			<< endl; 
	} 
	
	ofs.close();
}

// ͳ���ļ��е�����
int WorkerManager::getEmpNum(){
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	// ����ְ����Ϣ
	int num;
	string name;
	int depN; 
	
	int dataNum = 0; //ͳ��ְ������ 
		
	// ����ļ������Ҳ�Ϊ�գ��򽫱�ʶ����Ϊfalse 
	this->m_FileIsEmpty = false;		
	
	this->m_EmpNum = 0; // ͳ��ְ������
	
	while(ifs >> num && ifs >> name && ifs >> depN){
		
		dataNum++; 
	} 
	
	ifs.close();
		
	return dataNum;
}

// ��ʼ������
void WorkerManager::InitEmpArray(){
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	// ����ְ����Ϣ
	int num;
	string name;
	int depN;
	
	// ����ļ������Ҳ�Ϊ�գ��򽫱�ʶ����Ϊfalse 
	this->m_FileIsEmpty = false;		
	
	int index = 0; // ͳ��ְ������
	
	while(ifs >> num && ifs >> name && ifs >> depN){
		// �ж���ְ���ĸ�λ����������ͬ���������� 
		Worker *worker = NULL;
		
		switch (depN){
			case 1:
				worker= new employee(num,name,depN);
				break;
				
			case 2:
				worker = new manager(num,name,depN);
				break;
			
			case 3:
				worker = new boss(num,name,depN);
				break;
			
			default:
				break; 
		}
		// �����ݴ���������� 
		this->m_EmpArray[index] = worker;
		index++;
	} 
	ifs.close(); 
}

// ��ʾְ��
void WorkerManager::show_Emp(){
	
	if(this->m_EmpNum == 0){
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl; 
	}else{
		cout << "ְ������Ϊ��" << this->m_EmpNum << endl;
		// ��ӡְ����Ϣ 
		for(int i=0; i < this->m_EmpNum; i++){
			this->m_EmpArray[i]->showInfo();
		}
	}
	
	system("pause");
	system("cls");
}

// ɾ��ְ��
void WorkerManager::del_Emp(){
	
	string name;	// ɾ��Ա��������
	int num;		// ɾ��Ա���ı��
	
	int index;		// ѡ��ɾ����ʽ 
	int delNum=0;	// ��¼ɾ������ 
	cout << "������ɾ����ʽ��1��������ɾ����2�������ɾ����"; 
	cin >> index;
	
	if(index == 1){
		
		// 1����������ɾ��
		cout << "������Ҫɾ��ְ����������" ;
		cin >> name;
		
		for(int i=0; i<this->m_EmpNum; i++){
			if(this->m_EmpArray[i]->m_Name == name){
				delNum++; 
				this->m_EmpArray[i] = NULL;
				
				// ���ɾ�����ݣ���Ҫ���������εݼ� 
				for(int j=i; j<this->m_EmpNum-1; j++){
					this->m_EmpArray[j] = this->m_EmpArray[j+1];
				}
				
				// ÿ��ɾ��һ�ˣ���Ҫ��ֵ��һ 
				this->m_EmpNum--;
			}
		} 
		
		if(delNum == 0){
			cout << "û���ҵ�����Ϊ: " << name << " ��Ա����" << endl;
		}
		
	} else if(index == 2){
		// 2�����ձ��ɾ��
		cout << "������Ҫɾ��ְ���ı�ţ�" ;
		cin >> num;
		
		for(int i=0; i<this->m_EmpNum; i++){
			if(this->m_EmpArray[i]->m_Num == num){
				this->m_EmpArray[i] = NULL;
				delNum++;
				
				// ���ɾ�����ݣ���Ҫ���������εݼ� 
				for(int j=i; j<this->m_EmpNum-1; j++){
					this->m_EmpArray[j] = this->m_EmpArray[j+1];
					this->m_EmpArray[j+1] = NULL;
				}
				
				// ÿ��ɾ��һ�ˣ���Ҫ��ֵ��һ 
				this->m_EmpNum--;
			}
		}
		
		if(delNum == 0){
			cout << "û���ҵ����Ϊ: " << num << " ��Ա����" << endl;
		}
		
	} else{
		cout << "��������ȷ��ɾ����ʽ!";
		this->del_Emp();
	}
	
	if(delNum != 0){
		cout << "ɾ���ɹ�����ɾ�� " << delNum << " λְ��" << endl;
		
		this->save();
	}
	system("pause");
	system("cls");
} 

// �ж�ְ���Ƿ����
int WorkerManager::workerIsExit(){
	
	int index = -1; 
	
	string name;	// ����Ա��������
	int num;		// ����Ա���ı��
	
	int Numb=0;  	// ��¼���ҵ������� 
	int Select;		// ѡ����ҷ�ʽ 
	cout << "��ѡ����ҷ�ʽ��1����Ա���������ң�2����Ա����Ų���:"; 
	cin >> Select;
	
	if(Select == 1){
		cout << "������Ҫ����Ա��������:";
		cin >> name; 
		
		for(int i=0; i<this->m_EmpNum; i++){
			if(this->m_EmpArray[i]->m_Name == name){
				Numb++;
				index = i;
			}
		}
		
	}else if(Select == 2){
		cout << "������Ҫ����Ա���ı��:";
		cin >> num; 
		
		for(int i=0; i<this->m_EmpNum; i++){
			if(this->m_EmpArray[i]->m_Num == num){
				Numb++;
				index = i;
			}
		}
		
	}else{
		cout << "��������ȷ�Ĳ��ҷ�ʽ��" << endl;
		return index;
	}
	
	return index;
}

// �޸�ְ����Ϣ 
void WorkerManager::Mod_Emp(){
	
	if(this->m_FileIsEmpty){
		cout << "��ְ�������ڻ�û�������ļ���" << endl;
	}else{
		
		int index = this->workerIsExit();
		
		cout << "��ְ����������ϢΪ��" << endl;
		this->m_EmpArray[index]->showInfo(); 
		
		if(index != -1){
			
			string name;
			int num;
			int dNum;
			
			Worker * worker = NULL;
			
			cout << "������Ҫ�޸ĵ�Ա����������";
			cin >> name;
			
			cout << "�������޸ĺ�ı�ţ�";
			cin >> num;
			
			cout << "�������޸ĺ��ְλ(1��Ա����2������3���ϰ�)��";
			cin >> dNum; 
			
			switch (dNum){
			case 1:
				worker= new employee(num,name,dNum);
				break;
				
			case 2:
				worker = new manager(num,name,dNum);
				break;
			
			case 3:
				worker = new boss(num,name,dNum);
				break;
			
			default:
				break; 
		}
			
			this->m_EmpArray[index] = worker; 
			cout << "�޸ĳɹ�!�޸ĺ����ϢΪ��" << endl;
//			cout <<  this->m_EmpArray[index]->showInfo();
		}else{
			cout << "��ְ�������ڣ�" << endl;
		}
		
		this->save();
		
		system("pause");
		system("cls");
		
	}
	
}

// ����ְ����Ϣ 
void WorkerManager::Find_Emp(){
	
	if(this->m_FileIsEmpty){
		cout << "��ְ�������ڻ�û�������ļ���" << endl;
	}else{
		
		int Ifo = this->workerIsExit();
		
		if(Ifo == -1){
			cout << "��ְ��������" << endl; 
		} else{
			cout << "��ְ�����ڣ�����ϢΪ��" << endl;
			this->m_EmpArray[Ifo]->showInfo(); 
		}
	}
	system("pause");
	system("cls");
}

// ��������(���ȫΪָ�룬���޷��������ݵĽ���)
void WorkerManager::Emp_swap(Worker *temp1, Worker *temp2){
	Worker *temp;
	
	temp = temp1;
	temp1 = temp2;
	temp2 = temp;
	
}

// ��ְ����������
void WorkerManager::Sort_Emp(){
	
	if(this->m_FileIsEmpty){
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}else{
		
		int select;
		
		cout << "��ѡ������ʽ��1����Ŵ�С��������2����ŴӴ�С����" ;
		cin >> select;
		
		if(select == 1){
			// ʹ��ѡ�����򷨽������� (��С�����������)
			for(int i=0; i<this->m_EmpNum-1; i++){
				int min = i;
				
				for(int j=i+1; j<this->m_EmpNum; j++){
					// ��¼�����е���С��ŵ�λ�� 
					if(this->m_EmpArray[min]->m_Num > this->m_EmpArray[j]->m_Num){
						min = j; 
					}
				}
				// ����iλ��������Сֵ���� 
				if(min != i){
					//this->Emp_swap(this->m_EmpArray[i],this->m_EmpArray[min]);
					Worker *temp = NULL;
					temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[min];
					this->m_EmpArray[min] = temp;
				}
			}
		}else if(select == 2){
			// ʹ��ð�����򷨽������� (�Ӵ�С��������)
			for(int i=this->m_EmpNum; i>0; i--){
				
				for(int j=0; j<i-1; j++){
					
					if(this->m_EmpArray[j]->m_Num < this->m_EmpArray[j+1]->m_Num){
						this->Emp_swap(this->m_EmpArray[j],this->m_EmpArray[j+1]);
//						Worker *temp = NULL;
//						temp = this->m_EmpArray[j];
//						this->m_EmpArray[j] = this->m_EmpArray[j+1];
//						this->m_EmpArray[j+1] = temp;
					}
				}
			}
		}else{
			cout << "�������" << endl;
			return; 
		}
		
		cout << "����ɹ���" << endl;
		this->save();
	}
	
	system("pause");
	system("cls");
	
}

// �����������
void WorkerManager::ClearAll_Emp(){
	
	// ����ļ�������ɾ�����´��� 
	ofstream ofs(FILENAME, ios::trunc);
	ofs.close();
	
	string str;
	cout << "�Ƿ�����������ݣ������ò�������ɾ���������ݣ�����" << endl;
	cout << "���ȷ������������������� 'clear' :";
	cin >> str; 
		
	if(str == "clear"){
		
		if(this->m_EmpArray != NULL){
			for(int i=0;i<this->m_EmpNum;i++){
				this->m_EmpArray[i] = NULL;
				delete this->m_EmpArray[i];
			}
		} 
		delete [] this->m_EmpArray;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		
		cout << "������������ɹ���" << endl;
		this->save();
	}else{
		cout << "����������ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
		
	system("pause");
	system("cls");
} 

WorkerManager::~WorkerManager(){
	if(this->m_EmpArray != NULL){
		delete [] this->m_EmpArray;
		this->m_EmpArray = NULL;
	} 
}
