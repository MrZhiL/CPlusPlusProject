#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// copy(iterator beg, iterator end, iterator dest); �������� 

void MyPrint(int num){
	cout << num << "  ";
}

void test01(){
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(rand()%10+1);
	}
	
	cout << "vec�����е�Ԫ��Ϊ��";
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl;
	
	// ��vec�����е�Ԫ�ؿ�����vec2��
	
	vector<int> vec2;
	vec2.resize(vec.size());
	
	copy(vec.begin(), vec.end(), vec2.begin());
	cout << "vec2�����е�Ԫ��Ϊ��";
	for_each(vec2.begin(), vec2.end(), MyPrint);
	cout << endl;	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
