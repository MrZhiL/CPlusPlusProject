#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Student {
	string name;	//ѧ�������� 
	int age;		//ѧ�������� 
	int score;		//ѧ���ĳɼ� 
}; 

struct teacher {
	
	int id;  //��ʦ��id
	string name;//��ʦ������ 
	int age;	//��ʦ������ 
	
	struct Student *stu; //��ʦ����ѧ����Ϣ 
//	stu = (struct Student *)malloc(sizeof(struct Student)); //����Ķ��巽�� 
};

// �������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ������� 
void print(teacher *);

int main(){
	
	// ���ã��ṹ���еĳ�Ա��������һ���ṹ��
	// ���磺ÿ����ʦ����һ��ѧԱ��һ����ʦ�Ľṹ���м�¼һ��ѧ���Ľṹ�� 
	
	teacher tea1 = {20200730,"Lucy",38},*tea2;		//����һ����ʦ 
	
	teacher *p1 = &tea1;
	
	/*�������Ľṹ��Ϊָ�룬����ҪΪ������ڴ棬Ҫ��Ȼ�����*/
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
