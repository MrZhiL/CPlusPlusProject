#include<iostream>
#include<vector>
#include<algorithm>
#include<functional> 

using namespace std;

// sort�����㷨

void MyPrint(int num){
	cout << num << "  ";
}

void test01(){
	vector<int> vec;
	
	vec.push_back(13);
	vec.push_back(15);
	vec.push_back(26);
	vec.push_back(7);
	vec.push_back(11);
	
	// ��������
	sort(vec.begin(), vec.end());
	
	// ��ӡԪ��
	for_each(vec.begin(), vec.end(), MyPrint); 
	cout << endl;
	
	// ��������,����ʹ���ڽ���������greater������ ,����ʹ��functionalͷ�ļ� 
	sort(vec.begin(), vec.end(), greater<int>());
	 
	for_each(vec.begin(), vec.end(), MyPrint); 
	cout << endl;
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
 
