#include <iostream>
#include <string>
#include <stdlib.h>

#ifndef EXAM1_H
#define EXAM1_H

using namespace std;

struct Student{
	
	int num; 		//��� 
	string name;	//���� 
	int score;		//�ɼ� 
};

struct Teacher{
	
	int id;			// id
	string name;	// ���� 
	struct Student Stu[5];	//����ѧ������ 
};

// ��ֵ���� 
void scanfTea(struct Teacher *tea); 
// ��ӡ����
void printTea( const struct Teacher *tea); 

void scanfTea(struct Teacher *tea){
	
	cout << "�����ʦ��ֵ��" << endl;
	
	cout << "��ʦ������" ;
	cin  >> tea->name;
	
	cout << "��ʦid  ��" ;
	cin  >> tea->id;
	
	// ����ʦ����ѧ����ֵ 
	for(int j=0;j<5;j++){
	
		cout << "��ʦ������" << j+1 << "��ѧ����������ѧ�źͷ�����" ;
		cin  >> tea->Stu[j].name >> tea->Stu[j].num >> tea->Stu[j].score;
		cout << endl;
	} 
	
}

void printTea(const struct Teacher *tea){
	
	// ��ӡ��ʦ������ѧ������
	
	cout << "��ʦ������" << tea->name << "  ��ʦid��" << tea->id << endl;
	cout << "��ʦ����ѧ����" << endl; 
	
	int len1 = sizeof(tea->Stu)/sizeof(tea->Stu[1]);
	cout << "len1 = " << len1 << endl;
	
	for (int j=0;j<5;j++){
		cout << "��" << j+1 << "��ѧ�����ݣ�" 
			 << "name: " << tea->Stu[j].name
			 << "  num: " << tea->Stu[j].num
			 << "  score: " << tea->Stu[j].score
			 << endl; 
	} 
} 

#endif
