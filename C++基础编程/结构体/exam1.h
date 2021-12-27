#include <iostream>
#include <string>
#include <stdlib.h>

#ifndef EXAM1_H
#define EXAM1_H

using namespace std;

struct Student{
	
	int num; 		//编号 
	string name;	//姓名 
	int score;		//成绩 
};

struct Teacher{
	
	int id;			// id
	string name;	// 姓名 
	struct Student Stu[5];	//所带学生数据 
};

// 赋值函数 
void scanfTea(struct Teacher *tea); 
// 打印函数
void printTea( const struct Teacher *tea); 

void scanfTea(struct Teacher *tea){
	
	cout << "请给老师赋值：" << endl;
	
	cout << "老师姓名：" ;
	cin  >> tea->name;
	
	cout << "老师id  ：" ;
	cin  >> tea->id;
	
	// 给老师所带学生赋值 
	for(int j=0;j<5;j++){
	
		cout << "老师所带第" << j+1 << "个学生的姓名、学号和分数：" ;
		cin  >> tea->Stu[j].name >> tea->Stu[j].num >> tea->Stu[j].score;
		cout << endl;
	} 
	
}

void printTea(const struct Teacher *tea){
	
	// 打印老师及所带学生数据
	
	cout << "老师姓名：" << tea->name << "  老师id：" << tea->id << endl;
	cout << "老师所带学生：" << endl; 
	
	int len1 = sizeof(tea->Stu)/sizeof(tea->Stu[1]);
	cout << "len1 = " << len1 << endl;
	
	for (int j=0;j<5;j++){
		cout << "第" << j+1 << "名学生数据：" 
			 << "name: " << tea->Stu[j].name
			 << "  num: " << tea->Stu[j].num
			 << "  score: " << tea->Stu[j].score
			 << endl; 
	} 
} 

#endif
