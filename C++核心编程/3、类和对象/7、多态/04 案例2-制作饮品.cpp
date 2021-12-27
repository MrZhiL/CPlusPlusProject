#include <iostream>

using namespace std;

/*********案例描述：**********************
 *制作饮品的大致流程为：煮水-冲泡-倒入杯中-加入辅料 
 *
 *利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶 
 *
 *data:			2020-08-16
 *
 *copyright:	Mr.Zhi
 *****************************************
 */

// 基类：煮水-冲泡-倒入杯中-加入辅料  
class Base{
	public:
		// 煮水 
		virtual void BoilWater() = 0;
		// 冲泡
		virtual void Brew() = 0;
		// 倒入杯中
		virtual void PourCup() = 0;
		// 加入辅料
		virtual void addAccessories() = 0; 
		
		// 制作饮品操作 
		void showStep(){
			this->BoilWater();
			this->Brew();
			this->PourCup();
			this->addAccessories();
		}
};

// 咖啡子类 
class  Coffee : public Base{
	public:
		// 煮水 
		virtual void BoilWater(){
			cout << "第一步：此时进行煮水操作！" << endl; 
		}
		// 冲泡
		virtual void Brew(){
			cout << "第二步：此时进行冲泡咖啡操作！" << endl;
		}
		// 倒入杯中
		virtual void PourCup(){
			cout << "第三步：此时将冲泡好的咖啡倒入杯中！" << endl; 
		}
		// 加入辅料
		virtual void addAccessories(){
			cout << "第四步：加入牛奶和糖！" << endl;
		} 
		
};

// 茶叶子类 
class  Tea : public Base{
	
	public:
		// 煮水 
		virtual void BoilWater(){
			cout << "第一步：此时进行煮水操作！" << endl; 
		}
		// 冲泡
		virtual void Brew(){
			cout << "第二步：此时进行冲泡茶叶操作！" << endl;
		}
		// 倒入杯中
		virtual void PourCup(){
			cout << "第三步：此时将冲泡好的茶叶倒入杯中！" << endl; 
		}
		// 加入辅料
		virtual void addAccessories(){
			cout << "第四步：加入柠檬！" << endl;
		} 
		
};



void test01(){
	
	// 创建咖啡类 
	cout << "----------------制作咖啡饮品！----------" << endl; 
	Base *coff = new Coffee(); 
	coff->showStep();
	
	// 释放内存：收动开辟，手动释放 
	delete coff; 
	
	// 创建茶叶类 
	cout << "----------------制作茶叶饮品！----------" << endl; 
	Base *tea = new Tea();
	tea->showStep();
	// 释放内存：收动开辟，手动释放
	delete tea;
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
