#include <iostream>
#include <string>

using namespace std;

/****************************************************** 
 * 设计油罐车立方体类(Cube) 
 * 求出立方体的面积和体积 
 * 分别用全局函数和成员函数判断两个立方体是否相等 
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
		
		// 成员函数 获取面积 
		double getArea(){
			return 2*c_length*c_width + 2*c_width*c_high + 2*c_length*c_high;
		}
		// 成员函数 获取体积 
		double getVol(){
			return c_high*c_width*c_length;
		}
		
		// 成员函数 判断立方体是否相等 
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

// 全局函数判断立方体是否相等 
int judgeCube(Cube &cube1, Cube &cube2){
	
	int judge=0;
	
	// 先通过体积和面积判断两个立方体是否相等 
	if(cube1.getVol() != cube2.getVol()){
		judge=0;
		return judge;
	}else if(cube1.getArea() != cube2.getArea()){
		judge=0;
		return judge;
	}else{
		// 如果体积和面积相等，在通过长宽高判断2个立方体是否相等 
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
	
	// 使用类创建2个立方体 
	Cube cube1,cube2;
	
	// 为cube1立方体的长宽高赋值 
	cube1.setLength(10);
	cube1.setWidth(5);
	cube1.setHigh(2); 
	
	// 为cube2立方体的长宽高赋值 
	cube2.setLength(10);
	cube2.setWidth(5);
	cube2.setHigh(21); 
	
	// 获取立方体的面积和体积
	cout << "cube1的面积为： " << cube1.getArea() << endl;
	cout << "cube1的体积为： " << cube1.getVol() << endl;
	
	cout << "cube2的面积为： " << cube2.getArea() << endl;
	cout << "cube2的体积为： " << cube2.getVol() << endl;
	
	// 使用成员函数判断2个立方体是否相等 
	
	
	// 使用全局函数判断2个立方体是否相等 
	int ret = judgeCube(cube1,cube2);
	if (ret)
		cout << "cube1和cube2两个立方体相等" << endl;
	else
		cout << "cube1和cube2两个立方体不相等" << endl;
		
	// 使用成员函数判断2个立方体是否相等
	ret = cube1.judgeCube(cube2);
	if(ret)
		cout << "cube1和cube2两个立方体相等" << endl;
	else
		cout << "cube1和cube2两个立方体不相等" << endl; 
	return 0;
} 
