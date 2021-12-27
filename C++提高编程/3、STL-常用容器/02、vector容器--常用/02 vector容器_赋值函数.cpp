#include<iostream>
#include<vector>

using namespace std;

// ��vector�������и�ֵ�Ĳ�������д��=��operator=();
// vector& operator=(const vector &vec);	//���صȺŲ�����
// assign(beg, end);			// ��[beg, end)�����д�����ݿ�����ֵ������ 
// assign(n, elem); 			// ��n��elem���ݸ�ֵ������ 
//�ܽ᣺vector��ֵ��ʽ�Ƚϼ򵥣�ʹ��operator=,��assign������
 
void printVector(vector<int> &vec){
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
}

void test01(){
	
	vector<int> v1;		// �޲ι��� 
	for(int i=0; i<10; i++){	// ��v1���и�ֵ 
		v1.push_back(i);
	} 
	printVector(v1);
		
	vector<int> v2 = v1;
	printVector(v2);
	
	vector<int> v3;
	v3.assign(v2.begin(),v2.end());
	printVector(v3);
	
	vector<int> v4;
	v4.assign(10,10);
//	v4.assign(v2.begin(),v2.end());
	printVector(v4);
	
}

int main(){
	
	test01();
	 
	system("pause");
	return 0;
} 
