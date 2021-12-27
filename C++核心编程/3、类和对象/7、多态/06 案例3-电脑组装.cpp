#include <iostream>

using namespace std;

// ����������
// ������Ҫ��ɲ���ΪCPU���Կ����ڴ���
// ��ÿ�������װ�ɳ�����࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̺�Lenovo����
// �����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
// ����ʱ��װ��̨��ͬ�ĵ��Խ��й��� 

// ����CPU�� 
class CPU{
	public:
		// CPU�����ṩ���� 
		virtual void Calculate() = 0;
};

// �����Կ���
class VedioCard{
	public:
		// �Կ����ṩ��ʾ 
		virtual void display() = 0; 
}; 

// �����ڴ�����
class Memory{
	public:
		// �ڴ����ṩ�洢 
		virtual void storage() = 0;
}; 	

// ���������
class Computer{
	// ���캯���д���3�����ָ�� 
	public:
		Computer(CPU *cpu, VedioCard *vec, Memory *mem){
			m_cpu = cpu; 
			m_vec = vec;
			m_mem = mem;
		} 
		
		// �ṩ�����ĺ���
		void work(){
			
			m_cpu->Calculate();
			m_vec->display();
			m_mem->storage();
		} 

		~Computer(){
			if (m_cpu != NULL){
				delete m_cpu;
				m_cpu = NULL;
			}
			if (m_vec != NULL){
				delete m_vec;
				m_vec = NULL;
			}
			if (m_mem != NULL){
				delete m_mem;
				m_mem = NULL;
			}
		}		
		
	private:
		CPU 	  *m_cpu;	// CPU�����ָ�� 
		VedioCard *m_vec;		// �Կ������ָ�� 
		Memory    *m_mem;		// �ڴ��������ָ�� 
}; 

// ����Intel�ࣺ�ṩCPU���Կ����ڴ��� 
class IntelCPU : public CPU{
	public:
		
		// �ṩCPU
		virtual void Calculate(){
			cout << "This is Intel CPU and it are working!" << endl;
		} 
}; 

class IntelVedioCard : public VedioCard{
	public:
		
		// �ṩ�Կ�
		virtual void display(){
			cout << "This is Intel VedilCard and it can be display!" << endl;
		} 
}; 

class IntelMemory : public Memory{
	public:
		// �ṩ�ڴ���
		virtual void storage(){
			cout << "This is Intel Memory and it can be storage!" << endl;
		} 
}; 

// ����Lenovo�ࣺ�ṩCPU���Կ����ڴ��� 
class LenovoCPU : public CPU{
	public:
		
		// �ṩCPU
		virtual void Calculate(){
			cout << "This is Lenovo CPU and it are working!" << endl;
		} 
}; 

class LenovoVedioCard : public VedioCard{
	public:
		
		// �ṩ�Կ�
		virtual void display(){
			cout << "This is Lenovo VedilCard and it can be display!" << endl;
		} 
}; 

class LenovoMemory : public Memory{
	public:
		// �ṩ�ڴ���
		virtual void storage(){
			cout << "This is Lenovo Memory and it can be storage!" << endl;
		} 
}; 

// ��ʼ��װ����
// ����1��ʹ��intel�ࣻ����2��ʹ��lenove�ࣻ����3�������װ
void test01(){
	
	// ����1��
	cout << "---------------------Intel Computer!-------------------" << endl;
	
	CPU * cpu = new IntelCPU();
	VedioCard * vec = new IntelVedioCard();
	Memory * mem = new IntelMemory();
	
	Computer *comp1 = new Computer(cpu, vec, mem);
	comp1->work(); 
	
	delete comp1;
	
	// ����2
	cout << "---------------------Levono Computer!-------------------" << endl;
	Computer *comp2 = new Computer(new LenovoCPU, new LenovoVedioCard, new LenovoMemory);
	comp2->work(); 
	
	delete comp2;
	
	// ����3
	cout << "---------------------Hybrid Computer!-------------------" << endl;
	Computer *comp3 = new Computer(new LenovoCPU, new IntelVedioCard, new LenovoMemory);
	comp3->work(); 
	
	delete comp3;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
