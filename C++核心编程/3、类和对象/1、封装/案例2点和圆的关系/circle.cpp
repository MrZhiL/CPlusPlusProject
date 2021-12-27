#include "circle.h"
#include <math.h>
#define PI 3.14

// 设置圆心的坐标 
// 使用Circle::setCenter的意思为：告诉setCenter为Circle的成员函数 
void Circle::setCenter(Point center){
	c_center = center;
} 
// 获取圆心的横坐标 
Point Circle::getCenter(){
	return c_center;
}

// 设置半径 
void Circle::setRadius(double r){
	c_radius = r;
} 
// 获取半径 
double Circle::getRadiur(){
	return c_radius;
}
// 获取圆的面积
double Circle::getArea(){
	return c_radius*c_radius*PI;
} 
// 获取圆的周长 
double Circle::getCircum(){
	return 2*PI*c_radius;
}

int Circle::localCP(Point *p){
	// 判断点到圆心的距离
	double l = 0;
	l = pow((p->getPx()-c_center.getPx()), 2) + pow((p->getPy()-c_center.getPy()), 2);
	if (l>c_radius){
		cout << "点在圆外！" << endl;
		return 0;
	}else if (l == c_radius){
		cout << "点在圆上！" << endl;
		return 1;
	}else{
		cout << "点在圆内！" << endl; 
	}
}
