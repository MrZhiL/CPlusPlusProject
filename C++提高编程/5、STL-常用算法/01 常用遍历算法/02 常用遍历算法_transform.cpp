#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// transform�㷨���������е�Ԫ�ؿ�������һ��������
// transform(v.begin(), v.end(), v2.begin(), _func); 

// transform�еķº��� 
class CopyVec{
	public:
		// �ڸú����п��Խ����߼����� 
		int operator() (int num){
			//return num; 
			return num+100;	// ���Խ����߼����� 
		}
};

// for_each����Ԫ�صķº��� 
class PrintVec2{
	public:
		void operator()(int num){
			cout << num << "  ";
		}
};

void test01(){
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	
	vector<int> vec2;  // Ŀ����������vec�е�Ԫ�ؿ�����vec2��
	// �������Ŀ�����������С���ҿ��ٿռ�Ĵ�С������ڵ���Դ�����Ŀռ䣬��ᱨ��
	vec2.resize(vec.size()); 
	
	transform(vec.begin(), vec.end(), vec2.begin(), CopyVec());
	
	for_each(vec2.begin(), vec2.end(), PrintVec2());
	cout << endl; 
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
