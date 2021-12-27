#include <iostream>

#define PI 3.14  // 宏定义的值不可以修改 

using namespace std;

// 设计一个圆类，求圆的周长
// 圆类周长公式： 2 * PI * 半径

// class代表设计一个类
class Circle{
	// 创建访问权限
	public:
	 
	// 创建属性
	double cir_r; // 圆的半径 
	
	// 创建行为 
	double cal_vc(){
		return 2*PI*cir_r;	// 计算圆的周长，并返回 
	} 
}; 

// 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student{
	
	/* 类中的属性和行为，我们统称为成员
	 * 属性：成员属性、成员变量
	 * 行为：成员函数、成员方法 
	 *
	 */
	
	// 访问权限 
	public:
		// 属性 
		string name;	// 姓名 
		string id;		// 学号 
		
		// 行为
		void setName(string sut_name){
			name = sut_name;
		}
		
		void setId(string sut_id){
			id = sut_id;
		}
		
		void prinrStu(){
			cout << "学生的姓名为： " << name << endl;
			cout << "学生的学号为： " << id << endl; 
		} 
}; 


int main(){

/*	
	// 通过圆类，创建一个具体的圆（对象） 
	Circle  cir1;	// 实例化：通过一个类，创建一个对象的过程 
	
	// 给圆对象的属性进行赋值 
	cir1.cir_r = 10;
	
	cout << "圆的周长为: " << cir1.cal_vc() << endl;
*/
	// 通过学生类，创建学生stu1,stu2 
	Student stu1,stu2;
	
	// 给学生赋值并输出 
	stu1.name = "张三";
	stu1.id = "20200806";
	stu1.prinrStu();
	
	// 
	stu1.setName("jack");
	stu1.setId("jdck01");
	stu1.prinrStu();
		
	stu2.name = "李四";
	stu2.id = "80808080";
	stu2.prinrStu();
	
	return 0;
}
