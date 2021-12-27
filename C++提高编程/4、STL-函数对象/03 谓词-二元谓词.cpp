#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

// ν�ʣ�����º�������ֵΪbool���ͣ���Ϊν��
// һԪν�ʣ�operator()����������һ������
// ��Ԫν�ʣ�operator()������������������ 

class MyCompare{
	public:
		// ���operator()��������ֵΪbool���ͣ� ��Ϊν�� 
		bool operator() (int val1, int val2){
			return val1 > val2;	 
		}
};

void showVector(vector<int> &val){
	for(vector<int>::iterator it = val.begin(); it != val.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

void test01(){
	
	vector<int> v;
	
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(10);
	
	cout << "����ǰ��";
	showVector(v);
	
	cout << "ʹ��sort�㷨����Ĭ�������";
	sort(v.begin(), v.end());
	showVector(v); 
	
	cout << "ʹ�÷º����ı��������Ϊ��������";
	sort(v.begin(), v.end(), MyCompare()); 
	showVector(v); 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
