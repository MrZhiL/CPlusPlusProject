/*********************************************************************************************** 
 *	项目名称 :  通讯录管理系统
 *  copyright:  Mr.Zhi 
 *  date     :  2020-08-02
 *  
 ***********************************************************************************************
 * 通讯录管理系统 - 系统需求 
 * 添加联系人：向通讯录中添加新人，信息包括(姓名、性别、年龄、联系电话、家庭住址)最多记录1000人 
 * 显示联系人：显示通讯录中所有联系人信息 
 * 删除联系人：按照姓名进行删除指定联系人
 * 查找联系人：按照姓名查看指定联系然信息 
 * 修改联系人：按照姓名重新修改指定联系人 
 * 清空联系人：清空通讯录中所有信息 
 * 退出通讯录：退出当前使用的通讯录 
 *************************************************************************************************
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#define m_MAX 1000 

using namespace std;

// 创建联系人结构体 信息包括(姓名、性别、年龄、联系电话、家庭住址)
struct Person{
	
	string m_Name;	// 姓名 
	int m_Sex;		// 性别 （1、男 2、女 其它无效） 
	int m_Age;		// 年龄 
	string m_Phone;	// 联系电话 
	string m_Addr;	// 家庭住址 
};

// 创建通讯录结构体 (最多记录1000人)
struct AddressBooks{
	
	// 通讯录中保存的联系人数组 
	struct Person personArray[m_MAX];
	
	// 通讯录中当前记录联系人的个数 
	int m_Size;
	
};

void addPerson(struct AddressBooks *AdsBook);
void showMenu(); 

int main() {
	
	// 创建通讯录结构体变量 
	struct AddressBooks *AdsBook; 
	
	// 为通讯录分配内存空间，防止出现段错误 
	AdsBook = (struct AddressBooks *)malloc(sizeof(struct AddressBooks)); 
	AdsBook->personArray = (struct Person *)malloc(sizeof(struct Person)*m_MAX);

	AdsBook->m_Size = 0;
	// 创建用户选择变量 
	int select = 0;
	
	while(1){

		// 显示菜单 
		showMenu();
		
		cout << "Please input your action:";
		cin >> select;
		
		// 使用switvh语句来判断用户的动作 
		switch(select){
			
			// 1、添加联系人
			case 1:
				addPerson(AdsBook); // 利用地址传递可以修饰实参 
				break;
			// 2、显示联系人
			case 2:
				//showPerson(&AdsBook);
				break;
			// 3、删除联系人
			case 3:
				//delPerson(&AdsBook);
				break;
			// 4、查找联系人
			case 4:
				//findPerson(&AdsBook);
				break;
			// 5、修改联系人
			case 5:
				//modifyPerson(&AdsBook);
				break;
			// 6、清空联系人
			case 6:
				//clearPerson(&AdsBook);
				break;
			// 0、退出通讯录
			case 0:
				
				system("pause");
				return 0;
				break;
			default:
				break;
		}
		
	} 
	
//	free(AdsBook->personArray);
//	free(AdsBook);
	
	system("pause");
	return 0;
}

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


