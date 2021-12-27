#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// ���ü����㷨������  set_intersection(iteration beg1, end1, beg2, end2, dest);
// set_intersection���ص��ǵ��������õ�����ָʾ����ȡ�꽻�����������ĩβ 
// ע�⣺���������󽻼����������� ��������������(������������������ҪΪ��������) 

void showPrint(int num){
	cout << num << "  "; 
}

void test01(){
	
	vector<int> vec1;
	vector<int> vec2;
	
	for(int i=0; i<10; i++){
		vec1.push_back(5+i);
		vec2.push_back(i);
	}
	
	cout << "vec1: ";
	for_each(vec1.begin(), vec1.end(), showPrint);
	cout << endl;
	
	cout << "vec2: ";
	for_each(vec2.begin(), vec2.end(), showPrint);
	cout << endl;
	
	// ȡvec1��vec2�����Ľ�������ŵ�vec3������
	vector<int> vec3;
	// ��ҪΪvec3�����ṩ�ռ䣬������������ һ������������һ����������˴�ʱvec3���������ڴ�ռ����
	// min(a,b)Ϊȡ��Сֵ���㷨 
	vec3.resize(min(vec1.size(),vec2.size())); 
	
	// ȡvec1��vec2�����Ľ�������ŵ�vec3������
	vector<int>::iterator vec3End = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	
	// ����vec3�����е�Ԫ�أ��鿴�Ƿ���ڽ��� 
	// ���ʹ��vec3.end()��־����ĩβ������ӡ���������еĴ�С��û��ȡ��������Ԫ�ػ��Զ���ֵΪ0
	// �����Ҫʹ��set_intersection�����º��ĵ����� 
	//for_each(vec3.begin(), vec3.end(), showPrint);
	
	if(vec3.empty()){
		cout << "��������û�н�����" << endl;
	}else{
		cout << "�����������ڽ���������Ԫ��Ϊ�� "; 
		for_each(vec3.begin(), vec3End, showPrint);
		cout << endl;
	}
	
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
