#include <iostream>

#define PI 3.14  // �궨���ֵ�������޸� 

using namespace std;

// ���һ��Բ�࣬��Բ���ܳ�
// Բ���ܳ���ʽ�� 2 * PI * �뾶

// class�������һ����
class Circle{
	// ��������Ȩ��
	public:
	 
	// ��������
	double cir_r; // Բ�İ뾶 
	
	// ������Ϊ 
	double cal_vc(){
		return 2*PI*cir_r;	// ����Բ���ܳ��������� 
	} 
}; 

// ���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student{
	
	/* ���е����Ժ���Ϊ������ͳ��Ϊ��Ա
	 * ���ԣ���Ա���ԡ���Ա����
	 * ��Ϊ����Ա��������Ա���� 
	 *
	 */
	
	// ����Ȩ�� 
	public:
		// ���� 
		string name;	// ���� 
		string id;		// ѧ�� 
		
		// ��Ϊ
		void setName(string sut_name){
			name = sut_name;
		}
		
		void setId(string sut_id){
			id = sut_id;
		}
		
		void prinrStu(){
			cout << "ѧ��������Ϊ�� " << name << endl;
			cout << "ѧ����ѧ��Ϊ�� " << id << endl; 
		} 
}; 


int main(){

/*	
	// ͨ��Բ�࣬����һ�������Բ������ 
	Circle  cir1;	// ʵ������ͨ��һ���࣬����һ������Ĺ��� 
	
	// ��Բ��������Խ��и�ֵ 
	cir1.cir_r = 10;
	
	cout << "Բ���ܳ�Ϊ: " << cir1.cal_vc() << endl;
*/
	// ͨ��ѧ���࣬����ѧ��stu1,stu2 
	Student stu1,stu2;
	
	// ��ѧ����ֵ����� 
	stu1.name = "����";
	stu1.id = "20200806";
	stu1.prinrStu();
	
	// 
	stu1.setName("jack");
	stu1.setId("jdck01");
	stu1.prinrStu();
		
	stu2.name = "����";
	stu2.id = "80808080";
	stu2.prinrStu();
	
	return 0;
}
