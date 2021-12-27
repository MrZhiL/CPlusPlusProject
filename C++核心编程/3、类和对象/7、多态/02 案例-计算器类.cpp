#include <iostream>

using namespace std;

/****��̬����1-��������******** 
 * �����������ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ������� 
 * * * * * ��̬�ŵ� * * * * * *  
 * ������֯�ṹ���� 
 * �ɶ���ǿ
 * ����ǰ�ںͺ��ڵ���չ��ά�� 
 */

// ��ͨд�� 
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
			// �����Ҫ��չ�µĹ��ܣ���Ҫ�޸�Դ��
			// �����ǵĿ����У��ᳫ ����ԭ��
			// ����ԭ�򣺶���չ���п��������޸Ľ��йر� 
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
	cout << "m_Num1/m_Num2ȡ��Ϊ��" << cal.m_Num1 << "/" << cal.m_Num2 << "=" << cal.getResult("/") << endl;
}

// ���ö�̬ʵ�ּ�����

// ʵ�ּ����������� 

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

	// ���мӷ����� 
	calP = new AddCal();
	calP->m_Num1 = m_A;
	calP->m_Num2 = m_B;
	
	cout << calP->m_Num1 << "+" << calP->m_Num2 << "=" << calP->getResult() << endl;
	// �������Ҫ�ͷ��ڴ�
	delete calP;
	
	// ���м�������
	calP = new SubtractCal();
	calP->m_Num1 = m_A;
	calP->m_Num2 = m_B;
	 
	cout << calP->m_Num1 << "-" << calP->m_Num2 << "=" << calP->getResult() << endl;
	delete calP;
	
	// ���г˷�����	
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
