#pragma once
#include <iostream>

using namespace std;

// ���һ������
class Point{
	
	public:
		// ���õ�ĺ����� 
		void setPxy(double x,double y);

		// ��ȡ��ĺ�����
		double getPx();

		// ��ȡ���������
		double getPy();

		
	private:
		double P_x;	// ��ĺ����� 
		double P_y; // ��������� 
	
}; 
 
