#include <iostream>

using namespace std;

/****多态案例1-计算器类******** 
 * 案例描述：分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类 
 * * * * * 多态优点 * * * * * *  
 * 代码组织结构清晰 
 * 可读性强
 * 利于前期和后期的扩展和维护 
 */

// 普通写法 
class Calcuator{
	public:
		int getResult(string oper){
			if(oper == "+"){
				return m_Num1+m_Num2;
			}else if(oper == "-"){
				return m_Num1-m_Num2;
			}else if(oper == "*"){
				return m_Num1*m_Num2;
			}else{
				return m_Num1/m_Num2;
			}
			// 如果想要扩展新的功能，需要修改源码
			// 在真是的开发中，提倡 开闭原则
			// 开闭原则：对扩展进行开发，对修改进行关闭 
		}
		
		int m_Num1;
		int m_Num2; 
}; 

void test01(){
	Calcuator cal;
	cout << "Please input the number of m_Num1:";
	cin >> cal.m_Num1;
	cout << "Please input the number of m_Num2:";
	cin >> cal.m_Num2;
	
	cout << "cal.m_Num1 = " << cal.m_Num1 << endl;
	cout << "cal.m_Num2 = " << cal.m_Num2 << endl;
	
	cout << cal.m_Num1 << "+" << cal.m_Num2 << "=" << cal.getResult("+") << endl;
	cout << cal.m_Num1 << "-" << cal.m_Num2 << "=" << cal.getResult("-") << endl;
	cout << cal.m_Num1 << "*" << cal.m_Num2 << "=" << cal.getResult("*") << endl;
	cout << "m_Num1/m_Num2取整为：" << cal.m_Num1 << "/" << cal.m_Num2 << "=" << cal.getResult("/") << endl;
}

// 利用多态实现计算器

// 实现计算器抽象类 

class CalcuatorPol{
	public:
		
		virtual int getResult(){
			return 0; 
		} 
		
		int m_Num1;
		int m_Num2;
};

class AddCal:public CalcuatorPol{
	public:
		int getResult(){
			return this->m_Num1 + this->m_Num2;
		}
		
};
class SubtractCal:public CalcuatorPol{
	public:
		int getResult(){
			return this->m_Num1 - this->m_Num2;
		}
};
class MultiplyCal:public CalcuatorPol{
	public:
		int getResult(){
			return this->m_Num1 * this->m_Num2;
		}
};
class DivisionCal:public CalcuatorPol{
	public:
		int getResult(){
			return this->m_Num1 / this->m_Num2;
		}
};

void test02(){
	
	int m_A,m_B;
	
	cout << "Please input the number of m_Num1:";
	cin >> m_A;
	cout << "Please input the number of m_Num2:";
	cin >> m_B;
	
	CalcuatorPol *calP; 

	// 进行加法运算 
	calP = new AddCal();
	calP->m_Num1 = m_A;
	calP->m_Num2 = m_B;
	
	cout << calP->m_Num1 << "+" << calP->m_Num2 << "=" << calP->getResult() << endl;
	// 用完后需要释放内存
	delete calP;
	
	// 进行减法运算
	calP = new SubtractCal();
	calP->m_Num1 = m_A;
	calP->m_Num2 = m_B;
	 
	cout << calP->m_Num1 << "-" << calP->m_Num2 << "=" << calP->getResult() << endl;
	delete calP;
	
	// 进行乘法运算	
	calP = new MultiplyCal();
	calP->m_Num1 = m_A;
	calP->m_Num2 = m_B;
	
	cout << calP->m_Num1 << "*" << calP->m_Num2 << "=" << calP->getResult() << endl;
	delete calP;
	
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
