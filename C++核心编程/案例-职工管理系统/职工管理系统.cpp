#include <iostream>
#include <fstream>
#include <string>
#include "workerManager.h" 
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h" 

using namespace std; 

// 职工管理系统
/** 
	管理系统中需要实现的功能如下：
	1、退出管理程序：退出当前管理系统
	2、增加职工信息：实现批量添加职工功能
	3、显示职工信息：显示公司内部所有职工的信息
	4、删除离职职工：按照编号删除指定的员工
	5、修改职工信息：按照编号修改指定职工的信息
	6、查找职工信息：按照职工的编号或者职工的姓名进行查找相关员工的信息 
	7、按照编号排序：按照职工编号，进行排序，排序规则由用户指定 
	8、清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删） 
*/	

void test01(){
	Worker *emp = new employee(110, "张三", 3);
	Worker *mag = new manager(1, "赵四", 2);
	Worker *bos = new boss(0, "王五", 1);
	
	emp->showInfo();
	cout << emp->m_Name << "的职位为：" << emp->showDepart() << endl;
	delete emp;
	
	mag->showInfo();
	cout << mag->m_Name << "的职位为：" << mag->showDepart() << endl;
	delete mag;
	
	bos->showInfo();
	cout << bos->m_Name << "的职位为：" << bos->showDepart() << endl;
	delete bos;
}

void test02(WorkerManager &workerM){
	
	workerM.InitEmpArray();
	
	for(int i=0; i < workerM.m_EmpNum; i++){
		workerM.m_EmpArray[i]->showInfo();
	}
}

int main() {
	
	// 创建管理类 
	WorkerManager workerM;
	//test01();
	//test02(workerM);
	
	// choice为记录用户的选择 
	int choice;
	
	while(true){
		// 显示交互界面 
		workerM.showMenu();

		cout << "请输入您的选择："; 
		
		// 获取用户的选择
		cin >> choice;
		
		switch(choice){
			
			// 退出管理系统 
			case 0:
				workerM.ExitSystem(); 
				break;
			// 添加职工 
			case 1:
				workerM.addEmp();
				break;
			// 显示职工信息 
			case 2:
				workerM.show_Emp();
				break;
			// 删除职工 
			case 3:
				workerM.del_Emp();
				break;
			// 修改职工信息 
			case 4:
				workerM.Mod_Emp();
				break;
			// 查找职工 
			case 5:
				workerM.Find_Emp();
				break;
			// 给职工排序 
			case 6:
				workerM.Sort_Emp();
				break;
			// 清空所有职工信息（需二次确认） 
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

