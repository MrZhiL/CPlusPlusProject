#include <iostream>
#include <string>
#include <stdlib.h>

#define m_MAX 1000

#ifndef ADDRESSBOOKS_H
#define ADDRESSBOOKS_H

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


// 0、菜单界面函数 
void showMenu();
// 1、添加联系人 
void addPerson(struct AddressBooks *); 
// 2、显示联系人 
void showPerson(struct AddressBooks *); 
// 3、删除联系人
void delPerson(struct AddressBooks *); 
// 4、查找联系人
void findPerson(struct AddressBooks *);
// 5、修改联系人
void modifyPerson(struct AddressBooks *);
// 6、清空联系人
void clearPerson(struct AddressBooks *);

#endif /*ADDRESSBOOKS_H*/ 
