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
#include "AddressBooks.h"

using namespace std;

int main() {
	
	// 创建通讯录结构体变量 
	struct AddressBooks AdsBook; 
	
	// 为通讯录分配内存空间，防止出现段错误 
//	AdsBook = (struct AddressBooks *)malloc(sizeof(struct AddressBooks)); 
//	AdsBook->personArray = (struct Person *)malloc(sizeof(struct Person)*m_MAX);

	AdsBook.m_Size = 0;
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
				addPerson(&AdsBook); // 利用地址传递可以修饰实参 
				break;
			// 2、显示联系人
			case 2:
				showPerson(&AdsBook);
				break;
			// 3、删除联系人
			case 3:
				delPerson(&AdsBook);
				break;
			// 4、查找联系人
			case 4:
				findPerson(&AdsBook);
				break;
			// 5、修改联系人
			case 5:
				modifyPerson(&AdsBook);
				break;
			// 6、清空联系人
			case 6:
				clearPerson(&AdsBook);
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

