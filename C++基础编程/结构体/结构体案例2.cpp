#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Hero{
	
	// ���� 
	string name;
	// ���� 
	int age;
	// �Ա� 
	string sex;
	
}; 

void PritfHeroInfo(struct Hero *hero, int len);
void WritHeroInfo(struct Hero *hero, int len);
void BulledSort(struct Hero *hero, int len);

int main(){
	
	// ����������
	// ���һ��Ӣ�۵Ľṹ�壬������Ա���������䡢�Ա𣻴����ṹ�����飬�����д��5��Ӣ��
	// ͨ��ð�����򷨣��������е�Ӣ�۰���������������������մ�ӡ�����Ľ�� 
	
	// �����ṹ�� 
	struct Hero hero[5];
	int len = sizeof(hero)/sizeof(hero[0]);
	
	// ͨ����������Ӣ������ 
	WritHeroInfo(hero,len);
	// ��� 
	cout << "����ǰ��" << endl; 
	PritfHeroInfo(hero,len);
	
	// ʹ��ð�����򷨽�������
	BulledSort(hero,len);
	
	cout << "�����" << endl; 
	PritfHeroInfo(hero,len);
	
	system("pause");
	return 0;
} 

// ���뺯�� 
void WritHeroInfo(struct Hero *hero, int len){
	
	string name[len] = {"����","����","�ŷ�","����","����"};
	int age[len] = {23,22,20,21,19};
	string sex[len] = {"��","��","��","��","Ů",}; 
	
	for (int i=0;i<len;i++){
		hero[i].name = name[i];
		hero[i].age = age[i];
		hero[i].sex = sex[i];
//		hero++;
	} 
	
} 

// ������� 
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

// ð�����򷨽����������� 
void BulledSort(struct Hero *hero, int len){
	
	int i,j;
	// ������ʱ�ṹ�� 
	struct Hero temp;
	
	// ʹ��ð�����򷨽������� 
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
