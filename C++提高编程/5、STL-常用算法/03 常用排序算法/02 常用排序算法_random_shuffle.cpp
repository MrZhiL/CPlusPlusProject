#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime> 

using namespace std;

// random_shuffle(iterator beg, iterator end); ������򣬽�ָ����Χ�ڵ�Ԫ������������� 

void MyPrint(int num){
	cout << num << "  "; 
}

void test01(){
	
	// ��Ҫ��������ӣ�Ҫ��ÿ�μӽ����ͬ 
	srand((unsigned int)time(NULL)); 
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	
	// �������ǰ����������Ϊ��
	cout << "�������ǰ����������Ϊ��" ; 
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl;
	
	// ����������������Ϊ��(����ϴ���㷨�����Ҵ���)
	cout << "����������������Ϊ: ";
	random_shuffle(vec.begin(), vec.end());
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl;
	 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
