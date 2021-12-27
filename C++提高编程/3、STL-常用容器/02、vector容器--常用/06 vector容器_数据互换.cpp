#include<iostream>
#include<vector>

using namespace std;

//ʵ������������Ԫ�ؽ��л���

void printVector(vector<int> &vec){
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
}

// 1������ʵ�� 
void test01(){
	
	vector<int> vec;
	for(int i=0; i<10; i++){
		vec.push_back(i);
		//vec[i] = 10+i;
	}
	cout << "����ǰ��" << endl; 
	printVector(vec);
	
	vector<int> vec2;
	for(int i=999; i>=990; i--){
		vec2.push_back(i);
	}
	printVector(vec2);
	
	// ������
	cout << "������" << endl; 
	vec.swap(vec2);
	printVector(vec);
	printVector(vec2);
}

// 2��Ӧ�ð����� 
// �����������������Լ����ڴ�ռ�
void test02(){
	
	vector<int> vec;
	for(int i=0; i<100000; i++){
		vec.push_back(i);
	}
	cout << "vec������Ϊ��" << vec.capacity() << endl;
	cout << "vec�Ĵ�СΪ��" << vec.size() << endl;
	
	// ���������������������ڴ�ռ�
	vec.resize(10); 
	cout << "����vec�����е����ݴ�СΪ10��" << endl; 
	cout << "vec������Ϊ��" << vec.capacity() << endl;
	cout << "vec�Ĵ�СΪ��" << vec.size() << endl;
	
	vector<int> vec2 = vec;
	cout << "vec2������Ϊ��" << vec2.capacity() << endl;
	cout << "vec2�Ĵ�СΪ��" << vec2.size() << endl;
	
	// vector<int>(vec)��ʾ�������������ϵͳ������������ 
	vector<int>(vec).swap(vec);	//��ʾ�ȴ���һ����������x��x(vec)��ʾ���п������캯�����ٽ�x��vec��������������֮������������������ 
	cout << "��������������vec������" << endl; 
	cout << "vec������Ϊ��" << vec.capacity() << endl;
	cout << "vec�Ĵ�СΪ��" << vec.size() << endl;

} 
 
int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
	
} 
