#include <iostream>
#include <string>

using namespace std;

/****************************************************** 
 * ����͹޳���������(Cube) 
 * ������������������ 
 * �ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���� 
 ****************************************************** 
 */

class Cube{
	
	public:
		
		void setLength(double length){
			c_length = length;
		}
		double getLength(){
			return c_length;
		}
		
		void setWidth(double width){
			c_width = width;
		}
		double getWidth(){
			return c_width;
		}
		
		void setHigh(double high){
			c_high = high;
		}
		double getHigh(){
			return c_high;
		}
		
		// ��Ա���� ��ȡ��� 
		double getArea(){
			return 2*c_length*c_width + 2*c_width*c_high + 2*c_length*c_high;
		}
		// ��Ա���� ��ȡ��� 
		double getVol(){
			return c_high*c_width*c_length;
		}
		
		// ��Ա���� �ж��������Ƿ���� 
		bool judgeCube(Cube &cube){
			if((c_length == cube.getLength()) && (c_width == cube.getWidth()) && (c_high == cube.getHigh())){
				return true;
			}else
				return false;
		} 
	private:
		double c_length;
		double c_width;
		double c_high;
	
}; 

// ȫ�ֺ����ж��������Ƿ���� 
int judgeCube(Cube &cube1, Cube &cube2){
	
	int judge=0;
	
	// ��ͨ�����������ж������������Ƿ���� 
	if(cube1.getVol() != cube2.getVol()){
		judge=0;
		return judge;
	}else if(cube1.getArea() != cube2.getArea()){
		judge=0;
		return judge;
	}else{
		// �������������ȣ���ͨ��������ж�2���������Ƿ���� 
		if(cube1.getLength() != cube2.getLength()){
			judge=0;
			return judge;
		}else if(cube1.getWidth() != cube2.getWidth()){
			judge=0;
			return judge;
		}else if(cube1.getHigh() != cube2.getHigh()){
			judge=0;
			return judge;
		}else
			judge = 1;
//		judge = 1;
	}
	return judge;
} 

int main(){
	
	// ʹ���ഴ��2�������� 
	Cube cube1,cube2;
	
	// Ϊcube1������ĳ���߸�ֵ 
	cube1.setLength(10);
	cube1.setWidth(5);
	cube1.setHigh(2); 
	
	// Ϊcube2������ĳ���߸�ֵ 
	cube2.setLength(10);
	cube2.setWidth(5);
	cube2.setHigh(21); 
	
	// ��ȡ���������������
	cout << "cube1�����Ϊ�� " << cube1.getArea() << endl;
	cout << "cube1�����Ϊ�� " << cube1.getVol() << endl;
	
	cout << "cube2�����Ϊ�� " << cube2.getArea() << endl;
	cout << "cube2�����Ϊ�� " << cube2.getVol() << endl;
	
	// ʹ�ó�Ա�����ж�2���������Ƿ���� 
	
	
	// ʹ��ȫ�ֺ����ж�2���������Ƿ���� 
	int ret = judgeCube(cube1,cube2);
	if (ret)
		cout << "cube1��cube2�������������" << endl;
	else
		cout << "cube1��cube2���������岻���" << endl;
		
	// ʹ�ó�Ա�����ж�2���������Ƿ����
	ret = cube1.judgeCube(cube2);
	if(ret)
		cout << "cube1��cube2�������������" << endl;
	else
		cout << "cube1��cube2���������岻���" << endl; 
	return 0;
} 
