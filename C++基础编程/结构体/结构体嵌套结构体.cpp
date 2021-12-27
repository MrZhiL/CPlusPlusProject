#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Student {
	string name;	//学生的姓名 
	int age;		//学生的年龄 
	int score;		//学生的成绩 
}; 

struct teacher {
	
	int id;  //老师的id
	string name;//老师的姓名 
	int age;	//老师的年龄 
	
	struct Student *stu; //老师所教学生信息 
//	stu = (struct Student *)malloc(sizeof(struct Student)); //错误的定义方法 
};

// 将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来 
void print(teacher *);

int main(){
	
	// 作用：结构体中的成员可以是另一个结构体
	// 例如：每个老师辅导一个学员，一个老师的结构体中记录一个学生的结构体 
	
	teacher tea1 = {20200730,"Lucy",38},*tea2;		//创建一个老师 
	
	teacher *p1 = &tea1;
	
	/*如果定义的结构体为指针，则需要为其分配内存，要不然会出错*/
	p1 = (struct teacher *)malloc(sizeof(struct teacher));
	p1->stu = (struct Student *)malloc(sizeof(struct Student));
	tea2 = (struct teacher *)malloc(sizeof(struct teacher));
	tea2->stu = (struct Student *)malloc(sizeof(struct Student));
		
	tea2->name = "TeacherMa";
	tea2->id   = 2918230;
	tea2->age  = 40;
//	*(tea2.stu) = {"Intel",21,61};   
	tea2->stu->name = "Intel";
	tea2->stu->age = 21;
	tea2->stu->score = 61;
	
	p1->stu->name = "Jack";
	p1->stu->age  = 19;
	p1->stu->score= 59;
	
	cout << "teacher name: " << tea1.name << endl
		 << "teacher id  : " << tea1.id   << endl
		 << "teacher age : " << tea1.age  << endl
		 << "Student inf : " << " Stu name: " << p1->stu->name
		 					 << " ;Stu age: " << p1->stu->age
		 					 << " ;Stu score: " << p1->stu->score
		 					 << endl;
	print(tea2);
	
	system("pause");
	return 0;
}

void print(teacher *tea2){
	cout << "teacher name: " << tea2->name << endl
		 << "teacher id  : " << tea2->id   << endl
		 << "teacher age : " << tea2->age  << endl
		 << "Student inf : " << " Stu name:  " << tea2->stu->name
		 					 << " Stu age:   " << tea2->stu->age
		 					 << " Stu score: " << tea2->stu->score
		 					 << endl;
}
