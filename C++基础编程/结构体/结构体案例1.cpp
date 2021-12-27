#include <iostream>
#include <string>
#include <stdlib.h>
#include "exam1.h"

using namespace std;

int main(){
	
	/** 案例描述： 
	 *  学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下：
	 *  设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员 
	 *  学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带学生赋值 
	 *  最终打印出老师数据和所带学生数据 
	 */ 
	
	// 创建老师的结构体 
	Teacher tea[3];
	int len = sizeof(tea)/sizeof(tea[1]);

	// 使用函数给每个老师及所带学生赋值 
	for (int i=0;i<len;i++){
		
		cout << "请给第" << i+1 << "名老师和所带学生赋值：" << endl;  
		 
		scanfTea(&tea[i]);
	} 
	
	// 使用函数  打印每个老师及所带学生数据 
	for (int i=0;i<3;i++){
		
		printTea(&tea[i]);
	} 
	
	system("pause");
	return 0;
} 


