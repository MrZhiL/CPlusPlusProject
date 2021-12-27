#include <iostream>

using namespace std;

/*********����������**********************
 *������Ʒ�Ĵ�������Ϊ����ˮ-����-���뱭��-���븨�� 
 *
 *���ö�̬����ʵ�ֱ��������ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ 
 *
 *data:			2020-08-16
 *
 *copyright:	Mr.Zhi
 *****************************************
 */

// ���ࣺ��ˮ-����-���뱭��-���븨��  
class Base{
	public:
		// ��ˮ 
		virtual void BoilWater() = 0;
		// ����
		virtual void Brew() = 0;
		// ���뱭��
		virtual void PourCup() = 0;
		// ���븨��
		virtual void addAccessories() = 0; 
		
		// ������Ʒ���� 
		void showStep(){
			this->BoilWater();
			this->Brew();
			this->PourCup();
			this->addAccessories();
		}
};

// �������� 
class  Coffee : public Base{
	public:
		// ��ˮ 
		virtual void BoilWater(){
			cout << "��һ������ʱ������ˮ������" << endl; 
		}
		// ����
		virtual void Brew(){
			cout << "�ڶ�������ʱ���г��ݿ��Ȳ�����" << endl;
		}
		// ���뱭��
		virtual void PourCup(){
			cout << "����������ʱ�����ݺõĿ��ȵ��뱭�У�" << endl; 
		}
		// ���븨��
		virtual void addAccessories(){
			cout << "���Ĳ�������ţ�̺��ǣ�" << endl;
		} 
		
};

// ��Ҷ���� 
class  Tea : public Base{
	
	public:
		// ��ˮ 
		virtual void BoilWater(){
			cout << "��һ������ʱ������ˮ������" << endl; 
		}
		// ����
		virtual void Brew(){
			cout << "�ڶ�������ʱ���г��ݲ�Ҷ������" << endl;
		}
		// ���뱭��
		virtual void PourCup(){
			cout << "����������ʱ�����ݺõĲ�Ҷ���뱭�У�" << endl; 
		}
		// ���븨��
		virtual void addAccessories(){
			cout << "���Ĳ����������ʣ�" << endl;
		} 
		
};



void test01(){
	
	// ���������� 
	cout << "----------------����������Ʒ��----------" << endl; 
	Base *coff = new Coffee(); 
	coff->showStep();
	
	// �ͷ��ڴ棺�ն����٣��ֶ��ͷ� 
	delete coff; 
	
	// ������Ҷ�� 
	cout << "----------------������Ҷ��Ʒ��----------" << endl; 
	Base *tea = new Tea();
	tea->showStep();
	// �ͷ��ڴ棺�ն����٣��ֶ��ͷ�
	delete tea;
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
