#include <iostream>
#include <string>
#include "stdlib.h"

using namespace std;

struct Student {
	
	string name;
	int age;
	int score;
	
}; 

int main() {
	
	// 1、定义结构体
	// 2、创建结构体数组，并赋值 
	// 3、遍历结构体数组 
	
	struct Student StuArray[3] = {
		
		{"张三", 18, 99},
		{"李四", 20, 90},
		{"王五", 17, 80}
	};
	
	Student *Stu;
	
	Stu = (struct Student *)malloc(sizeof(struct Student));
	
	Stu->name = "luck";
	Stu->age = 19;
	Stu->score = 78;
	
	StuArray[1].name = "Jack";
	StuArray[1].age = 21;
	StuArray[1].score = 89;
	
	
	for (int i=0;i<3;i++){
		cout << " name: " << StuArray[i].name 
			 << " age: "  << StuArray[i].age 
			 << " score: " << StuArray[i].score << endl;
	}
	
	cout << "name : " << Stu->age << endl;
	
	system("pause");
	return 0;
	
}
