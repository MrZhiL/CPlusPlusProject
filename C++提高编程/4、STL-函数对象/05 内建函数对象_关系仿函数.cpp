#include<iostream>
#include<functional>
#include<vector>
#include<algorithm> 
using namespace std;

// ���ú������󣺹�ϵ�º��� 

class MyCompare{
	public:
		bool operator() (int num1, int num2){
			return num1 > num2;
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
	v.push_back(44);
	v.push_back(23);
	v.push_back(46);
	v.push_back(29);
	
	cout << "����ǰ��";
	showVector(v); 
	
//	sort(v.begin(), v.end(), MyCompare());
//	cout << "ͨ���Լ������ķº������н�������";
//	showVector(v);
	
	// ͨ���ڽ���������greater���������н������� 
	cout << "ͨ���ڽ�����greater�����򳡽��н�������";
	sort(v.begin(), v.end(), greater<int>());
	showVector(v); 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
