#include "circle.h"
#include <math.h>
#define PI 3.14

// ����Բ�ĵ����� 
// ʹ��Circle::setCenter����˼Ϊ������setCenterΪCircle�ĳ�Ա���� 
void Circle::setCenter(Point center){
	c_center = center;
} 
// ��ȡԲ�ĵĺ����� 
Point Circle::getCenter(){
	return c_center;
}

// ���ð뾶 
void Circle::setRadius(double r){
	c_radius = r;
} 
// ��ȡ�뾶 
double Circle::getRadiur(){
	return c_radius;
}
// ��ȡԲ�����
double Circle::getArea(){
	return c_radius*c_radius*PI;
} 
// ��ȡԲ���ܳ� 
double Circle::getCircum(){
	return 2*PI*c_radius;
}

int Circle::localCP(Point *p){
	// �жϵ㵽Բ�ĵľ���
	double l = 0;
	l = pow((p->getPx()-c_center.getPx()), 2) + pow((p->getPy()-c_center.getPy()), 2);
	if (l>c_radius){
		cout << "����Բ�⣡" << endl;
		return 0;
	}else if (l == c_radius){
		cout << "����Բ�ϣ�" << endl;
		return 1;
	}else{
		cout << "����Բ�ڣ�" << endl; 
	}
}
