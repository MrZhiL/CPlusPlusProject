#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Student{
	
	string name; // ���� 
	int age;	 // ���� 
	int score;	 // �ɼ� 
	
}; 

// ʹ��ָ�봫�ݣ����Լ����ڴ�Ŀ��� 
// ʹ��const���Σ���ֹ����� ---- constʹ�ó��� 
void printS(const Student *Stu){  // ��const��ֹ�������е������ 
	
	//Stu->score = 100; // ����ʧ�ܣ����Ӽ�����const���� 
	cout << "name: " << Stu->name << " age: " << Stu->age << " score: " << Stu->score << endl; 
	
}

int main(){
	
	// const������Ϊֻ��״̬����ֹ����� 
	
	Student Stu1 = {"Luck", 18, 79};
	
	cout << "��ӡǰscore��" << Stu1.score << endl; 
	
	// ʹ�ú�����ӡstu1������ 
	printS(&Stu1);
	
	cout << "��ӡ��score��" << Stu1.score << endl; 
	 
	system("pause");
	return 0;
}
