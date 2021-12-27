#pragma once
#include <iostream>

using namespace std;

// 设计一个点类
class Point{
	
	public:
		// 设置点的横坐标 
		void setPxy(double x,double y);

		// 获取点的横坐标
		double getPx();

		// 获取点的纵坐标
		double getPy();

		
	private:
		double P_x;	// 点的横坐标 
		double P_y; // 点的纵坐标 
	
}; 
 
