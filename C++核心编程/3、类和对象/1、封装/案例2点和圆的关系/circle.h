#pragma once 
#include <iostream>
#include "point.h"

using namespace std;

// ���һ��Բ�� 
class Circle{
	
	public:
		// ����Բ�ĵ����� 
		void setCenter(Point center);
		// ��ȡԲ�ĵĺ����� 
		Point getCenter();
		
		// ���ð뾶 
		void setRadius(double r);
		// ��ȡ�뾶 
		double getRadiur();
		// ��ȡԲ�����
		double getArea();
		// ��ȡԲ���ܳ� 
		double getCircum();
		
		// �жϵ��Բ��λ�ù�ϵ 
		int localCP(Point *p);
	
	private:
//		double c_x;			// Բ�ĵĺ�����
//		double c_y;			// Բ�ĵ������� 
		Point c_center; 	// ��һ����������һ������Ϊ�����еĳ�Ա 
		double c_radius;	// �뾶 
		double c_area;		// ���
		double c_circum;	// �ܳ� 
};
