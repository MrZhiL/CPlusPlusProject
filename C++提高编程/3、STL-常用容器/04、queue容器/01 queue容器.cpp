//queue������������ֻ����һ�˲������ݣ�һ���Ƴ�����
//������ֻ�ж�ͷ�Ͷ�β�ſ��Ա����ʹ�ã���˶��в������б�����Ϊ 
// ���в�֧�ֵ�����������֧��������� 

/**
	���캯����queue<T> que;				//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ 
			  queue(const queue &que);	//�������캯�� 
					  
	��ֵ������queue& operator=(const queue &que);	//���صȺ������ 
			
	���ݴ�ȡ��	push(elem);				//����β���elemԪ�� 
				pop();					//�Ӷ�ͷ�Ƴ���һ��Ԫ�� 
				back();					//�������һ��Ԫ�� 
				front();				//���ص�һ��Ԫ�� 
					  
	��С������	empty(); 	    		//�ж϶����Ƿ�Ϊ�� 
				size();					//���ض��еĴ�С  
*/

#include<iostream>
#include<queue>

using namespace std;

//���е�ʵ����FIFO�������ȳ� 
void test01(){
	
	queue<int> que;	// Ĭ�Ϲ��캯��
	
	que.push(11);
	que.push(22);
	que.push(33);
	que.push(44);
	// push 4��Ԫ�غ󣬶����е�����Ϊ��11 22 33 44������FIFO��֪��pop�����е�����Ϊ��11 22 33 44 
	cout << "que�Ķ��д�СΪ��" << que.size() << endl;
	
	/*�������que��Ϊ�գ����ӡͷ�����ݺ�β�����ݣ����Ƴ�β������*/
	while( !que.empty() ) {
		cout << "que��ͷ������Ԫ��Ϊ��" << que.front(); 
		cout << "  ,que��β������Ԫ��Ϊ��" << que.back() << endl; 
		que.pop();
	} 
	cout << "que�Ķ��д�СΪ��" << que.size() << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
