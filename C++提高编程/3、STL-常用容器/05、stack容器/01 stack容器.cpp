#include<iostream>
#include<stack>

using namespace std;

// stackջ�Ĳ���
// ջ���ص㣺ֻ���Ƚ�����������Ա���ջ
 
void test01(){
	// ����ջ��Ĭ�Ϲ��캯�� 
	stack<int> stk;
	
	// ʹ��push��ջ�в������� 
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	
	cout << "ջ�Ĵ�СΪ��" << stk.size() << endl; 
	// �鿴ջ�Ƿ�Ϊ�գ������Ϊ�գ���鿴ջ�����ݣ������� 
	while(!stk.empty()){
		cout << "ջ��Ԫ��Ϊ��" << stk.top() << endl;
		stk.pop();
	}
	cout << "ջ�Ĵ�СΪ��" << stk.size() << endl; 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
