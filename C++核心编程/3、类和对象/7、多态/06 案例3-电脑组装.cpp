#include <iostream>

using namespace std;

// 案例描述：
// 电脑主要组成部分为CPU、显卡、内存条
// 将每个零件封装成抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
// 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
// 测试时组装三台不同的电脑进行工作 

// 抽象CPU类 
class CPU{
	public:
		// CPU类中提供计算 
		virtual void Calculate() = 0;
};

// 抽象显卡类
class VedioCard{
	public:
		// 显卡中提供显示 
		virtual void display() = 0; 
}; 

// 抽象内存条类
class Memory{
	public:
		// 内存中提供存储 
		virtual void storage() = 0;
}; 	

// 抽象电脑类
class Computer{
	// 构造函数中传输3个零件指针 
	public:
		Computer(CPU *cpu, VedioCard *vec, Memory *mem){
			m_cpu = cpu; 
			m_vec = vec;
			m_mem = mem;
		} 
		
		// 提供工作的函数
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
		CPU 	  *m_cpu;	// CPU的零件指针 
		VedioCard *m_vec;		// 显卡的零件指针 
		Memory    *m_mem;		// 内存条的零件指针 
}; 

// 抽象Intel类：提供CPU、显卡、内存条 
class IntelCPU : public CPU{
	public:
		
		// 提供CPU
		virtual void Calculate(){
			cout << "This is Intel CPU and it are working!" << endl;
		} 
}; 

class IntelVedioCard : public VedioCard{
	public:
		
		// 提供显卡
		virtual void display(){
			cout << "This is Intel VedilCard and it can be display!" << endl;
		} 
}; 

class IntelMemory : public Memory{
	public:
		// 提供内存条
		virtual void storage(){
			cout << "This is Intel Memory and it can be storage!" << endl;
		} 
}; 

// 抽象Lenovo类：提供CPU、显卡、内存条 
class LenovoCPU : public CPU{
	public:
		
		// 提供CPU
		virtual void Calculate(){
			cout << "This is Lenovo CPU and it are working!" << endl;
		} 
}; 

class LenovoVedioCard : public VedioCard{
	public:
		
		// 提供显卡
		virtual void display(){
			cout << "This is Lenovo VedilCard and it can be display!" << endl;
		} 
}; 

class LenovoMemory : public Memory{
	public:
		// 提供内存条
		virtual void storage(){
			cout << "This is Lenovo Memory and it can be storage!" << endl;
		} 
}; 

// 开始组装电脑
// 电脑1：使用intel类；电脑2：使用lenove类；电脑3：混合组装
void test01(){
	
	// 电脑1：
	cout << "---------------------Intel Computer!-------------------" << endl;
	
	CPU * cpu = new IntelCPU();
	VedioCard * vec = new IntelVedioCard();
	Memory * mem = new IntelMemory();
	
	Computer *comp1 = new Computer(cpu, vec, mem);
	comp1->work(); 
	
	delete comp1;
	
	// 电脑2
	cout << "---------------------Levono Computer!-------------------" << endl;
	Computer *comp2 = new Computer(new LenovoCPU, new LenovoVedioCard, new LenovoMemory);
	comp2->work(); 
	
	delete comp2;
	
	// 电脑3
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
