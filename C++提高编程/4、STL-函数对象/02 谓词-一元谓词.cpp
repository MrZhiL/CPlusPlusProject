#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

// ν�ʣ�����º�������ֵΪbool���ͣ���Ϊν��
// һԪν�ʣ�operator()����������һ������
// ��Ԫν�ʣ�operator()������������������ 

class FindGraterFive{
	public:
		// ���operator()��������ֵΪbool���ͣ� ��Ϊν�� 
		bool operator() (int val){
			return val > 5;	// �жϴ���5�������Ƿ���� 
		}
};

void test01(){
	
	vector<int> v;
	for(int i=0; i<10; i++){
		v.push_back(i);
	}
	
	// find_if���ص���һ�������� 
	vector<int>:: iterator it = find_if(v.begin(), v.end(), FindGraterFive());
	if(it == v.end()){
		cout << "δ�ҵ�����5�����֣�" << endl; 
	}else{
		cout << "�ҵ�����5�����֣���ֵΪ��" << *it << endl; 		
	}
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
