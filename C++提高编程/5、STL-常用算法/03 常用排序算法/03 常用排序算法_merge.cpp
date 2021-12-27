#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;

// merge�㷨�������������ϲ������洢����һ������
/**
	merge(iterator beg1, iterator end, iterator beg2, iterator end2, iterator dest);
  //���������ϲ������洢����һ������
  //������������ע�⣺������������������ģ�����������������ʽ��ͬ������������������
  //beg1������1��ʼ��������end1������1������������
  //beg2������2��ʼ��������end2������2����������
  //dest��Ŀ��������ʼ������ 
*/ 

void MyPrint(int num){
	cout << num << "  ";
}

void test01(){
	
	srand((unsigned int)time(NULL));
	
	vector<int> vec1;
	vector<int> vec2;
	
	for(int i=0; i<10; i++){
		vec1.push_back(rand()%10+1);
		vec2.push_back(rand()%10+2);
	}
	
	cout << "vec1�����е�Ԫ��Ϊ��";
	for_each(vec1.begin(), vec1.end(), MyPrint);
	cout << endl;
	
	cout << "vec2�����е�Ԫ��Ϊ��";
	for_each(vec2.begin(), vec2.end(), MyPrint);
	cout << endl;
	
	// ������vec1��vec2�е�Ԫ�غϲ�������ŵ�vec3�� 
	// ע���ʱvec1��vec2�е�Ԫ��һ��Ҫ���򣬷�������Ľ��������� 
	vector<int> vec3;
	
	// ��Ҫ��vec3���������С��Ҫ���ᱨ�� 
	vec3.resize(vec1.size()+vec2.size());
	
	sort(vec1.begin(), vec1.end()); 
	sort(vec2.begin(), vec2.end()); 
	
	// ��ʱvec3�е�����Ҳ������� 
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	
	cout << "vec3�����е�Ԫ��Ϊ��";
	for_each(vec3.begin(), vec3.end(), MyPrint); 
	cout << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
