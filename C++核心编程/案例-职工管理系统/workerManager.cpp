#include "workerManager.h"

WorkerManager::WorkerManager(){
	
	
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	
	// 1、如果文件不存在 
	if( !ifs.is_open()) {
		//cout << "文件不存在！" << endl;  // 测试代码，无需打印 
		
		// 初始化职工信息 
		this->m_EmpNum = 0;			// 初始化人数 
		this->m_EmpArray = NULL;	// 初始化数组 
		// 标志文件不存在 
		this->m_FileIsEmpty = true;	
		
		ifs.close();
		// 如果文件不存在，则不进行后续操作，直接退出 
		return ;
	}
	
	// 2、文件存在，但数据为空
	char ch;
	
	// 如果文件为空，则该文件中只有一个结尾标志('\0')，此时将结尾标志取出，则只剩EOF标志。 
	ifs >> ch;  
	// 如果此时文件标志为EOF,则文件为空 
	if (ifs.eof()){
		// 如果ifs.eof()函数为真，则文件为空文件 
		cout << "该文件为空!" << endl;	// 测试代码
		
		// 初始化职工信息 
		this->m_EmpNum = 0;			// 初始化人数 
		this->m_EmpArray = NULL;	// 初始化数组 
		// 标志文件不存在 
		this->m_FileIsEmpty = true;	
		
		ifs.close();
		// 如果文件不存在，则不进行后续操作，直接退出 
		return ;
	} 
	
	// 3、文件存在且不为空
	int num = this->getEmpNum();
	
	//cout << "职工人数为：" << num << endl; 
	
	this->m_EmpNum = num; 
	
	// 根据职工数量创建数组 （new *Worker 和 new Worker *的区别是什么） 
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	
	this->InitEmpArray();
}

// 展示菜单 
void WorkerManager::showMenu(){
			
	cout << "*******************************" << endl;
	cout << "****** 0、退出管理系统 ********" << endl;
	cout << "****** 1、增加职工信息 ********" << endl;
	cout << "****** 2、显示职工信息 ********" << endl;
	cout << "****** 3、删除离职职工 ********" << endl;
	cout << "****** 4、修改职工信息 ********" << endl;
	cout << "****** 5、查找职工信息 ********" << endl;
	cout << "****** 6、按照编号排序 ********" << endl;
	cout << "****** 7、清空所有文档 ********" << endl;
	cout << "*******************************" << endl;
	
} 

// 退出职工管理系统 
void WorkerManager::ExitSystem(){
	
	cout << "欢迎下次使用！" << endl;
	system("pause");
	// 如果检测到exit(0)则退出 
	exit(0); 
	
} 


// 添加职工函数
void WorkerManager::addEmp(){
	
	// 添加职工的人数 
	int addNum;
	
	// 提示添加新职工的数量 
	cout << "请输入添加新职工的数量（1-100）:" ;
	cin >> addNum;
	
	// 判断输入的数量是否合理 
	if (addNum > 0){
		
		// 计算新的空间大小：总的职工人数 = 原有的职工人数 + 新的职工人数
		int newArrayNum = this->m_EmpNum + addNum; 
		
		// 开辟新空间：创建新的职工数组
		Worker ** newArray = new Worker*[newArrayNum]; 
		
		// 将原有的职工重新赋值给新数组（需要判断原有职工的数量是否为空) 
		if(this->m_EmpArray != NULL){
			
			for(int i=0; i < this->m_EmpNum; i++){
				newArray[i] = this->m_EmpArray[i];
			}
		}
		
		int id;			//新职工的编号 
		string name;	//新职工的姓名 
		int dNum; 		//新职工的岗位
	
		// 批量添加新数据 
		for(int i=0; i < addNum; i++){
			
			cout << "请输入第" << i+1 << "个新职工的编号:" ;
			cin >> id;
			
			cout << "请输入第" << i+1 << "个新职工的姓名:" ;
			cin >> name; 
			
			cout << "请选择新职工的岗位：1、职工  2、经理  3、老板  ：";
			cin >> dNum;
			cout << endl;
			
			Worker *worker = NULL; 
			 
			// 判断新职工的岗位，并创建不同的数据类型 
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
					cout << "输入岗位错误！请重新输入：" << endl;
					//cin >> dNum;
					//goto loop;
					break; 
			}
			
			newArray[this->m_EmpNum + i] =                                                                                 worker;
//			delete worker; // 不能释放该内存，否则会出现内存错误，导致结果错误！！！ 
		} 
		
		// 释放原有的内存
		delete [] this->m_EmpArray;
		
		// 将this->m_EmpArray 指向新的内存数组
		this->m_EmpArray = newArray;
		
		// 更新新的职工人数
		this->m_EmpNum =  newArrayNum;
		
		// 如果成功添加新职工，则提示成功添加，并保存数据到文本文档中 
		cout << "成功添加" << addNum << "位职工！" << endl;
		// 如果数据添加成功，则将标识符 m_FileIsEmpty 置为flase，表示文件不为空 
		this->m_FileIsEmpty = false; 
		this->save(); 
		
	}else{
		cout << "输入数量不在合理范围内，请输入（1-100）之间的数量!" << endl;
	}
	
	// 添加成功后，将数据保存到文本文件中,按任意键清屏
	system("pause");
	system("cls");
	
}

// 保存文件函数
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

// 统计文件中的人数
int WorkerManager::getEmpNum(){
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	// 创建职工信息
	int num;
	string name;
	int depN; 
	
	int dataNum = 0; //统计职工人数 
		
	// 如果文件存在且不为空，则将标识符置为false 
	this->m_FileIsEmpty = false;		
	
	this->m_EmpNum = 0; // 统计职工人数
	
	while(ifs >> num && ifs >> name && ifs >> depN){
		
		dataNum++; 
	} 
	
	ifs.close();
		
	return dataNum;
}

// 初始化数组
void WorkerManager::InitEmpArray(){
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	// 创建职工信息
	int num;
	string name;
	int depN;
	
	// 如果文件存在且不为空，则将标识符置为false 
	this->m_FileIsEmpty = false;		
	
	int index = 0; // 统计职工人数
	
	while(ifs >> num && ifs >> name && ifs >> depN){
		// 判断新职工的岗位，并创建不同的数据类型 
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
		// 将数据存放在数组中 
		this->m_EmpArray[index] = worker;
		index++;
	} 
	ifs.close(); 
}

// 显示职工
void WorkerManager::show_Emp(){
	
	if(this->m_EmpNum == 0){
		cout << "文件不存在或者文件为空！" << endl; 
	}else{
		cout << "职工人数为：" << this->m_EmpNum << endl;
		// 打印职工信息 
		for(int i=0; i < this->m_EmpNum; i++){
			this->m_EmpArray[i]->showInfo();
		}
	}
	
	system("pause");
	system("cls");
}

// 删除职工
void WorkerManager::del_Emp(){
	
	string name;	// 删除员工的姓名
	int num;		// 删除员工的编号
	
	int index;		// 选择删除方式 
	int delNum=0;	// 记录删除数量 
	cout << "请输入删除方式：1、按姓名删除；2、按编号删除："; 
	cin >> index;
	
	if(index == 1){
		
		// 1、按照姓名删除
		cout << "请输入要删除职工的姓名：" ;
		cin >> name;
		
		for(int i=0; i<this->m_EmpNum; i++){
			if(this->m_EmpArray[i]->m_Name == name){
				delNum++; 
				this->m_EmpArray[i] = NULL;
				
				// 如果删除数据，需要将数据依次递减 
				for(int j=i; j<this->m_EmpNum-1; j++){
					this->m_EmpArray[j] = this->m_EmpArray[j+1];
				}
				
				// 每次删除一人，需要将值减一 
				this->m_EmpNum--;
			}
		} 
		
		if(delNum == 0){
			cout << "没有找到姓名为: " << name << " 的员工！" << endl;
		}
		
	} else if(index == 2){
		// 2、按照编号删除
		cout << "请输入要删除职工的编号：" ;
		cin >> num;
		
		for(int i=0; i<this->m_EmpNum; i++){
			if(this->m_EmpArray[i]->m_Num == num){
				this->m_EmpArray[i] = NULL;
				delNum++;
				
				// 如果删除数据，需要将数据依次递减 
				for(int j=i; j<this->m_EmpNum-1; j++){
					this->m_EmpArray[j] = this->m_EmpArray[j+1];
					this->m_EmpArray[j+1] = NULL;
				}
				
				// 每次删除一人，需要将值减一 
				this->m_EmpNum--;
			}
		}
		
		if(delNum == 0){
			cout << "没有找到编号为: " << num << " 的员工！" << endl;
		}
		
	} else{
		cout << "请输入正确的删除方式!";
		this->del_Emp();
	}
	
	if(delNum != 0){
		cout << "删除成功！共删除 " << delNum << " 位职工" << endl;
		
		this->save();
	}
	system("pause");
	system("cls");
} 

// 判断职工是否存在
int WorkerManager::workerIsExit(){
	
	int index = -1; 
	
	string name;	// 查找员工的姓名
	int num;		// 查找员工的编号
	
	int Numb=0;  	// 记录查找到的数量 
	int Select;		// 选择查找方式 
	cout << "请选择查找方式：1、按员工姓名查找；2、按员工编号查找:"; 
	cin >> Select;
	
	if(Select == 1){
		cout << "请输入要查找员工的姓名:";
		cin >> name; 
		
		for(int i=0; i<this->m_EmpNum; i++){
			if(this->m_EmpArray[i]->m_Name == name){
				Numb++;
				index = i;
			}
		}
		
	}else if(Select == 2){
		cout << "请输入要查找员工的编号:";
		cin >> num; 
		
		for(int i=0; i<this->m_EmpNum; i++){
			if(this->m_EmpArray[i]->m_Num == num){
				Numb++;
				index = i;
			}
		}
		
	}else{
		cout << "请输入正确的查找方式！" << endl;
		return index;
	}
	
	return index;
}

// 修改职工信息 
void WorkerManager::Mod_Emp(){
	
	if(this->m_FileIsEmpty){
		cout << "该职工不存在或没有数据文件！" << endl;
	}else{
		
		int index = this->workerIsExit();
		
		cout << "该职工的现有信息为：" << endl;
		this->m_EmpArray[index]->showInfo(); 
		
		if(index != -1){
			
			string name;
			int num;
			int dNum;
			
			Worker * worker = NULL;
			
			cout << "请输入要修改的员工的姓名：";
			cin >> name;
			
			cout << "请输入修改后的编号：";
			cin >> num;
			
			cout << "请输入修改后的职位(1、员工；2、经理；3、老板)：";
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
			cout << "修改成功!修改后的信息为：" << endl;
//			cout <<  this->m_EmpArray[index]->showInfo();
		}else{
			cout << "该职工不存在！" << endl;
		}
		
		this->save();
		
		system("pause");
		system("cls");
		
	}
	
}

// 查找职工信息 
void WorkerManager::Find_Emp(){
	
	if(this->m_FileIsEmpty){
		cout << "该职工不存在或没有数据文件！" << endl;
	}else{
		
		int Ifo = this->workerIsExit();
		
		if(Ifo == -1){
			cout << "该职工不存在" << endl; 
		} else{
			cout << "该职工存在，其信息为：" << endl;
			this->m_EmpArray[Ifo]->showInfo(); 
		}
	}
	system("pause");
	system("cls");
}

// 交换函数(如果全为指针，则无法进行数据的交换)
void WorkerManager::Emp_swap(Worker *temp1, Worker *temp2){
	Worker *temp;
	
	temp = temp1;
	temp1 = temp2;
	temp2 = temp;
	
}

// 对职工进行排序
void WorkerManager::Sort_Emp(){
	
	if(this->m_FileIsEmpty){
		cout << "文件不存在或文件为空！" << endl;
	}else{
		
		int select;
		
		cout << "请选择排序方式：1、编号从小到大排序；2、编号从大到小排序：" ;
		cin >> select;
		
		if(select == 1){
			// 使用选择排序法进行排序 (从小到大进行排序)
			for(int i=0; i<this->m_EmpNum-1; i++){
				int min = i;
				
				for(int j=i+1; j<this->m_EmpNum; j++){
					// 记录数组中的最小编号的位置 
					if(this->m_EmpArray[min]->m_Num > this->m_EmpArray[j]->m_Num){
						min = j; 
					}
				}
				// 将第i位数据与最小值交换 
				if(min != i){
					//this->Emp_swap(this->m_EmpArray[i],this->m_EmpArray[min]);
					Worker *temp = NULL;
					temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[min];
					this->m_EmpArray[min] = temp;
				}
			}
		}else if(select == 2){
			// 使用冒泡排序法进行排序 (从大到小进行排序)
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
			cout << "输入错误！" << endl;
			return; 
		}
		
		cout << "排序成功！" << endl;
		this->save();
	}
	
	system("pause");
	system("cls");
	
}

// 清空所有数据
void WorkerManager::ClearAll_Emp(){
	
	// 如果文件存在则删除重新创建 
	ofstream ofs(FILENAME, ios::trunc);
	ofs.close();
	
	string str;
	cout << "是否清除所有数据！！！该操作将会删除所有数据！！！" << endl;
	cout << "如果确定清楚所有数据请输入 'clear' :";
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
		
		cout << "所有数据清楚成功！" << endl;
		this->save();
	}else{
		cout << "输入错误！清除失败！" << endl;
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
