#include <iostream>

using namespace std; 

/*���õı�����C++�ڲ�ʵ����һ��ָ�볣��*/ 

// 1����Ҫ���ؾֲ��������� 
int& func(){
	
	int a = 10; //�ֲ����� �����ջ����,��ϵͳ�Զ��ͷ� 
	
	cout << "func2�е�a=" << a << endl; 
	return a;
}

// 2�����ؾ�̬��������
// �������ÿ�����Ϊ��ֵ 
int &func2(){
	static int a = 20;	// ��̬���������ȫ����,ȫ�����ϵ������ڳ����������ϵͳ�ͷ� 
	return a; 
} 

int main(){
	int &ref1 = func();
	int &ref2 = func2();
	
	cout << ref1 << endl;	// ��һ�������ȷ�����ԭ�����ڱ��������˱��� 
	cout << ref1 << endl; 	// ����func�������к�,����������ڴ������ͷ�.�ڶ��α��������ٱ���,��˲����ٶԴ˵�ַ����
	cout << ref1 << endl;
	
	cout << ref2 << endl;
	cout << ref2 << endl;
	
	func2() = 1000;			// ��������ķ���ֵ������,����������ÿ�����Ϊ��ֵ 
	func2();
	cout << ref2 << endl;
	cout << ref2 << endl;
	
	return 0;
}
