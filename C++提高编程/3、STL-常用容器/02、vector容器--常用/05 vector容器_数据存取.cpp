#include<iostream>
#include<vector>

using namespace std;

// vector�����е����ݴ�ȡ 
/**
	at(int idx);	//��������idx��ָ������ 
	operator[];		//��������idx��ָ������ 
	front();		//���������е�һ������Ԫ�� 
	back();			//�������������һ������Ԫ��  
 */

void test01(){
	
	vector<int> vec;
	for(int i=0;i<10;i++){
		vec.push_back(i+1);
	}

	// vector�����е����ݴ�ȡ
	for(int i=0;i<vec.size();i++){
		cout << "vec[" << i << "] = " << vec[i] << endl; // ʹ��operator[]�����������ȡ����
	}
		
	for(int i=0;i<vec.size(); i++)
	cout << "vec.at(" << i << ")=" << vec.at(i) << endl; // ʹ��at(int idx)���±�Ϊidx������
	
	cout << "�����еĵ�һ������Ϊ��" << vec.front() << endl;
	cout << "�����е����һ������Ϊ: " << vec.back() << endl; 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
