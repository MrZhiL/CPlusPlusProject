#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Hero{
	
	// 姓名 
	string name;
	// 年龄 
	int age;
	// 性别 
	string sex;
	
}; 

void PritfHeroInfo(struct Hero *hero, int len);
void WritHeroInfo(struct Hero *hero, int len);
void BulledSort(struct Hero *hero, int len);

int main(){
	
	// 案例描述：
	// 设计一个英雄的结构体，包括成员姓名、年龄、性别；创建结构体数组，数组中存放5名英雄
	// 通过冒泡排序法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果 
	
	// 创建结构体 
	struct Hero hero[5];
	int len = sizeof(hero)/sizeof(hero[0]);
	
	// 通过函数输入英雄数据 
	WritHeroInfo(hero,len);
	// 输出 
	cout << "排序前：" << endl; 
	PritfHeroInfo(hero,len);
	
	// 使用冒泡排序法进行排序
	BulledSort(hero,len);
	
	cout << "排序后：" << endl; 
	PritfHeroInfo(hero,len);
	
	system("pause");
	return 0;
} 

// 输入函数 
void WritHeroInfo(struct Hero *hero, int len){
	
	string name[len] = {"刘备","关羽","张飞","赵云","貂蝉"};
	int age[len] = {23,22,20,21,19};
	string sex[len] = {"男","男","男","男","女",}; 
	
	for (int i=0;i<len;i++){
		hero[i].name = name[i];
		hero[i].age = age[i];
		hero[i].sex = sex[i];
//		hero++;
	} 
	
} 

// 输出函数 
void PritfHeroInfo(struct Hero *hero, int len){
	
	for (int i=0;i<len;i++){
		cout << "hero[" << i+1 << "]: "
			 << " name: "<< hero->name 
			 << " age: " << hero->age 
			 << " sex: " << hero->sex 
			 << endl;
		hero++;
//		cout << endl;
	} 
	
} 

// 冒泡排序法进行升序排序 
void BulledSort(struct Hero *hero, int len){
	
	int i,j;
	// 创建临时结构体 
	struct Hero temp;
	
	// 使用冒泡排序法进行排序 
	for (i=0; i<len-1; i++){
		
		for (j=0;j<len-i-1;j++){
			
			if (hero[j].age > hero[j+1].age){
				
				temp = hero[j];
				hero[j] = hero[j+1];
				hero[j+1] = temp;
				
			} 
			
		}
	} 
	
}
