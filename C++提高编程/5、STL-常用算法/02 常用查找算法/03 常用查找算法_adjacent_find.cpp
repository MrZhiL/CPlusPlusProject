#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ���������ظ�Ԫ���Ƿ����: adjacent_find(begin, end); 

void test01(){
	vector<int> vec;
	
	vec.push_back(10);	// ��Ȼ����Ҳ��Ԫ��10�����ǲ����� 
	vec.push_back(14);
	vec.push_back(16);
	vec.push_back(12);	// ���Թ۲쵽12Ԫ�غ�����Ԫ���ظ� 
	vec.push_back(12);
	vec.push_back(10);
	vec.push_back(14);
	
	vector<int>::iterator it = adjacent_find(vec.begin(), vec.end());
	
	// �жϲ����Ƿ�ɹ�
	if(it != vec.end()){
		cout << "���ҳɹ���" << *it << endl;
	}else{
		cout << "����ʧ�ܣ�����������Ԫ�����ظ���" << endl;
	}
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
