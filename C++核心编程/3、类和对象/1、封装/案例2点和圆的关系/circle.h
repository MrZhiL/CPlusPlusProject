#pragma once 
#include <iostream>
#include "point.h"

using namespace std;

// 设计一个圆类 
class Circle{
	
	public:
		// 设置圆心的坐标 
		void setCenter(Point center);
		// 获取圆心的横坐标 
		Point getCenter();
		
		// 设置半径 
		void setRadius(double r);
		// 获取半径 
		double getRadiur();
		// 获取圆的面积
		double getArea();
		// 获取圆的周长 
		double getCircum();
		
		// 判断点和圆的位置关系 
		int localCP(Point *p);
	
	private:
//		double c_x;			// 圆心的横坐标
//		double c_y;			// 圆心的纵坐标 
		Point c_center; 	// 在一个类中让另一个类作为本类中的成员 
		double c_radius;	// 半径 
		double c_area;		// 面积
		double c_circum;	// 周长 
};
