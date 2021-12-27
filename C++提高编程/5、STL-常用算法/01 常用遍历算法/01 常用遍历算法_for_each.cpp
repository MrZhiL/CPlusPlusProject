#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ���ñ����㷨��for_each
// for_each�㷨��algorithmͷ�ļ��� 

void printVector01(int num){
	cout << num << "  ";
} 

class printVector02{
	public:
		void operator() (int num){
			cout << num << "  ";
		}
}; 

void test01(){
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	
	// ʹ��for_each�㷨����vec�����е�Ԫ��
	// ʹ�ú������������ʹ�ú�����ֻ��Ҫд�뺯�������� 
	for_each(vec.begin(), vec.end(), printVector01); 
	cout << endl;
	
	// ʹ�÷º���������������ʱ��Ҫ������������Ҳ��Ҫ����() 
	for_each(vec.begin(), vec.end(), printVector02());
	cout << endl;
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
