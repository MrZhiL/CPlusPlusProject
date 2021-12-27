#include <iostream>
#include <string>
#include <math.h>
#include "point.h"
#include "circle.h" 

using namespace std;

/****************************************************** 
 * ���һ��Բ��(Circle)��һ������(Point),������Բ�Ĺ�ϵ 
 ****************************************************** 
 */


int main(){
	
	Circle c1;	// ����Բ 
	Point p1,center; 	  // �������Բ�� 
	
	center.setPxy(0,0);	  // ����Բ�ĵ�����
	c1.setRadius(1);     // ����Բ�İ뾶
	c1.setCenter(center); // ����Բ������ 
	
	p1.setPxy(1,0);	  // ���õ������
	
	double c_are = c1.getArea(); 
	double c_circrm = c1.getCircum();
	cout << "Բ�����Ϊ�� " << c_are << endl; 
	cout << "Բ���ܳ�Ϊ�� " << c_circrm << endl; 
	
	c1.localCP(&p1);
	
	return 0;
} 
