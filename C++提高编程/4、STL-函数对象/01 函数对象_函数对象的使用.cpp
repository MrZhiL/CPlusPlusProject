#include<iostream>
#include<string>

using namespace std;

// ���������ʹ���ص㣺 
// 1������������ʹ��ʱ����������ͨ����һ���в����ͷ���ֵ
// 2���������󳬳���ͨ�����ĸ���������Լ���״̬
// 3���������������Ϊ�������� 


// 1������������ʹ��ʱ����������ͨ����һ���в����ͷ���ֵ 
class MyAdd{
	public:
		// ���ص�()�������в���������int�ķ���ֵ 
		int operator() (int m1, int m2){
			return m1 + m2;
		}
}; 

void test01(){
	MyAdd myadd;
	cout << myadd(10,20) << endl;	
} 

// 2���������󳬳���ͨ�����ĸ���������Լ���״̬����Ϊ����������һ���ࣩ
class MyPrint{
	public:
		MyPrint(){
			this->count = 0;
		}
		void operator() (string st){
			cout << st << endl;
			this->count++; 
		} 
		
		int count;	// count������¼���ص�()�������ô��� 
}; 

void test02(){
	MyPrint mp;
	mp("HELLOWORLD");
	mp("HELLOWORLD");
	mp("HELLOWORLD");
	mp("HELLOWORLD");
	
	cout << "myPrint���õĴ���Ϊ��" << mp.count << endl;
}

// 3���������������Ϊ��������
void doPrint(MyPrint &mp, string st){
	mp(st);
	cout << "doPrint��mp���õĴ�����" << mp.count << endl; 
}

void test03(){
	
	MyPrint mp;
	doPrint(mp, "HElloC++");
	doPrint(mp, "HElloC++");
	doPrint(mp, "HElloC++");
	doPrint(mp, "HElloC++");
	
	cout << "mp�ĵ��ô�����" << mp.count << endl;
} 
int main(){
	
	//test01();
	//test02();
	test03();
	
	system("pause");
	return 0;
} 
