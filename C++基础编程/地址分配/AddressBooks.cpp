#include "AddressBooks.h"

// 0--封装函数显示该界面
void showMenu(){
	
	cout << "*************************" << endl; 
	cout << "***** 1、添加联系人 *****" << endl; 
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

// 1--添加联系人函数 
void addPerson(struct AddressBooks *AdsBook){
	
	if (AdsBook->m_Size > m_MAX){
		cout << "通讯录已满1000，无法添加" << endl;
		return ; 
	}else{
		string name;
		cout << "请输入联系人姓名：" ;
		cin >>  AdsBook->personArray[AdsBook->m_Size].m_Name;
		
		cout << "请输入联系人性别(1、男  2、女)：" ;
		int sex;
		cin >> sex;
		AdsBook->personArray[AdsBook->m_Size].m_Sex = sex;

		while((sex != 1) && (sex != 2)) {
			cout << "性别错误，请重新输入联系人性别(1、男  2、女)：" ;
			cin >> sex;
			AdsBook->personArray[AdsBook->m_Size].m_Sex = sex;
		}
		
		cout << "请输入联系人年龄：" ;
		cin >> AdsBook->personArray[AdsBook->m_Size].m_Age;
		
		cout << "请输入联系人电话：" ;
		string phone; 
		cin >> phone;
		AdsBook->personArray[AdsBook->m_Size].m_Phone = phone;
		
		cout << "请输入联系人家庭住址：" ;
		string addr;
		cin >> addr;
		AdsBook->personArray[AdsBook->m_Size].m_Addr = addr;
		
		// 每添加一个联系人，通讯录中的数量加1 
		AdsBook->m_Size++ ;
	//	AdsBook->personArray; 	
	}
	cout << "当前通讯录中的联系人数量：" <<  AdsBook->m_Size << endl;
	
	system("pause"); 
	// 清屏操作 
	system("cls"); 
} 

// 2、显示联系人 
void showPerson(struct AddressBooks *AdsBook){
	
	if(AdsBook->m_Size == 0){
		cout << "通讯录中没有联系人" << endl; 
	}else{
		cout << "联系人共有" <<  AdsBook->m_Size << "人: " << endl; 
		cout << "姓名" << "\t年龄" << "\t性别" << "\t电话" << "\t地址" << endl; 
		for(int i=0; i< AdsBook->m_Size ; i++){
			cout << AdsBook->personArray[i].m_Name  << "\t"
				 << AdsBook->personArray[i].m_Age   << "\t"
				 << AdsBook->personArray[i].m_Sex   << "\t"
				 << AdsBook->personArray[i].m_Phone << "\t"
				 << AdsBook->personArray[i].m_Addr  << "\t"
				 << endl;
			
		} 
	}
}

// 3、删除联系人 
void delPerson(struct AddressBooks *AdsBook){
	if(AdsBook->m_Size == 0){
		cout << "当前联系人为空，无联系人可删" << endl; 
	} else {
		
		int num1 = 0;
		string name;
		cout << "请输入删除联系人姓名：";
		cin >> name;  
		
		for(int i=0;i<AdsBook->m_Size;i++){
			if (AdsBook->personArray[i].m_Name == name){
				num1++; 
				for (int j=i; j<AdsBook->m_Size-1; j++){
					AdsBook->personArray[j] = AdsBook->personArray[j+1];
				}
			}
		}

		if (num1==0){
			cout << "无当前联系人！删除失败" << endl;  
		}else{
			AdsBook->m_Size = AdsBook->m_Size-num1;
			cout << "删除成功，共删除" << num1 << "个联系人！当前联系人数量为：" <<  AdsBook->m_Size << endl;
		}
		
	}
}

// 4、查找联系人
void findPerson(struct AddressBooks *AdsBook){
	if(AdsBook->m_Size == 0){
		cout << "当前联系人为空，无联系人可查找" << endl; 
	} else {
		
		int num1=0; 
		string name;
		cout << "请输入查找的联系人姓名：";
		cin >> name;  
		
		cout << "姓名" << "\t年龄" << "\t性别" << "\t电话" << "\t地址" << endl; 
		for(int i=0;i<AdsBook->m_Size;i++){
			if (AdsBook->personArray[i].m_Name == name){
				num1++;
				cout << AdsBook->personArray[i].m_Name  << "\t"
					 << AdsBook->personArray[i].m_Age   << "\t"
					 << AdsBook->personArray[i].m_Sex   << "\t"
					 << AdsBook->personArray[i].m_Phone << "\t"
					 << AdsBook->personArray[i].m_Addr  << "\t"
					 << endl;
			}
		}
		cout << "查找成功，该联系人共有" << num1 << "人。" << endl; 
		cout << "当前通讯录中的联系人数量：" <<  AdsBook->m_Size << endl;
		
	}
}
// 5、修改联系人
void modifyPerson(struct AddressBooks *AdsBook){
	if(AdsBook->m_Size == 0){
		cout << "当前联系人为空，无联系人可修改" << endl; 
	} else {
		int i,num=0;
		string name;
		cout << "请输入需要修改的联系人姓名：" << endl;
		cin >> name;
		
		for(int i=0;i<AdsBook->m_Size;i++){
			if(name == AdsBook->personArray[i].m_Name){
				num++; 
				cout << "修改后的姓名：" ;
				cin >> AdsBook->personArray[i].m_Name;
				
				cout << "修改后的性别(1、男  2、女)：" ;
				int sex;
				cin >> sex;
				AdsBook->personArray[i].m_Sex = sex;
		
				while((sex != 1) && (sex != 2)) {
					cout << "性别错误，请重新输入联系人性别(1、男  2、女)：" ;
					cin >> sex;
					AdsBook->personArray[i].m_Sex = sex;
				}
				
				cout << "修改后的年龄：" ;
				cin >> AdsBook->personArray[i].m_Age;
				
				cout << "修改后的电话：" ;
				cin >> AdsBook->personArray[i].m_Phone ;
				
				cout << "修改后的庭住址：" ;
				cin >> AdsBook->personArray[i].m_Addr;
			}
			
			if (num==0)
				cout << "通讯录中没有此人，无法修改！" << endl; 
			else
				cout << "修改成功" << endl;
		}
	}
}
// 6、清空联系人
void clearPerson(struct AddressBooks *AdsBook){
	if(AdsBook->m_Size == 0){
		cout << "当前联系人为空，无联系人可删" << endl; 
	} else {
		AdsBook->m_Size = 0;
	}
}
