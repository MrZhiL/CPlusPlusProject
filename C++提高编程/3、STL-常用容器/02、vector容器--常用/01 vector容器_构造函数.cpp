#include<iostream>
#include<vector>

using namespace std;

// vector���캯��
/** 
	vector<T> v;					//����ģ����ʵ�֣�Ĭ�Ϲ��캯�� 
	vector<v.begin(), v.end());		//��[v.begin(),v.end())����(ǰ�պ�)�е�Ԫ�ؿ��������� 
	vector(n, elem);				//���캯����n��elem���������� 
	vector(const vector &vec); 		//�������캯��  
*/ 

// ��vector�����е����ݽ������ 
void printVector(vector<int> &vec){
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
} 

void test01(){
	
	// 1��Ĭ�Ϲ��캯�����޲ι��� 
	vector<int> v1;
	
	for(int i=0; i<10; i++){	// ��v1���и�ֵ 
		v1.push_back(i);
	} 
	printVector(v1);
	
	// 2��vector<v.begin(), v.end())����[v.begin(),v.end() )�е����ݿ���
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);
	
	// 3��vector(n, elem)����n��elem���ݸ�ֵ��vector����
	vector<int> v3(10,100);	//��10��100��ֵ��v3
	printVector(v3);
	
	// 4��vector(const vector &vec)���������캯��
	vector<int> v4(v3);
	printVector(v4);
	 
}


int main(){

	test01();
		
	system("pause");
	return 0;
} 
