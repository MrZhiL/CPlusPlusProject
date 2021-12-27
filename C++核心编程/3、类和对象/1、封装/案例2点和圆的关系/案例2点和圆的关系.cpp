#include <iostream>
#include <string>
#include <math.h>
#include "point.h"
#include "circle.h" 

using namespace std;

/****************************************************** 
 * 设计一个圆类(Circle)和一个点类(Point),计算点和圆的关系 
 ****************************************************** 
 */


int main(){
	
	Circle c1;	// 创建圆 
	Point p1,center; 	  // 创建点和圆心 
	
	center.setPxy(0,0);	  // 设置圆心的坐标
	c1.setRadius(1);     // 输入圆的半径
	c1.setCenter(center); // 设置圆心坐标 
	
	p1.setPxy(1,0);	  // 设置点的坐标
	
	double c_are = c1.getArea(); 
	double c_circrm = c1.getCircum();
	cout << "圆的面积为： " << c_are << endl; 
	cout << "圆的周长为： " << c_circrm << endl; 
	
	c1.localCP(&p1);
	
	return 0;
} 
