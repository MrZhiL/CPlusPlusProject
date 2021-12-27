#include "point.h"

// 设置点的横坐标 
void Point::setPxy(double x,double y){
	P_x = x;
	P_y = y;
} 
// 获取点的横坐标
double Point::getPx(){
	return P_x;
} 
// 获取点的纵坐标
double Point::getPy(){
	return P_y;
} 
		
