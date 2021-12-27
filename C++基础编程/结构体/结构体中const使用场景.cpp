#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Student{
	
	string name; // 姓名 
	int age;	 // 年龄 
	int score;	 // 成绩 
	
}; 

// 使用指针传递，可以减少内存的开销 
// 使用const修饰，防止误操作 ---- const使用场景 
void printS(const Student *Stu){  // 加const防止函数体中的误操作 
	
	//Stu->score = 100; // 操作失败，因子加入了const修饰 
	cout << "name: " << Stu->name << " age: " << Stu->age << " score: " << Stu->score << endl; 
	
}

int main(){
	
	// const来修饰为只读状态，防止误操作 
	
	Student Stu1 = {"Luck", 18, 79};
	
	cout << "打印前score：" << Stu1.score << endl; 
	
	// 使用函数打印stu1的内容 
	printS(&Stu1);
	
	cout << "打印后score：" << Stu1.score << endl; 
	 
	system("pause");
	return 0;
}
