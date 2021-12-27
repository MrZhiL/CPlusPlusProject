#include<iostream>
#include<vector>

using namespace std;

// vector������ �������ʹ�С
// empty(); �ж������Ƿ�Ϊ��
// capacity(); �ж����������� 
// size(); �ж������Ĵ�С
// resize(int num); ����ָ�������Ĵ�С�����num>ԭ���Ĵ�С������Ĭ��ֵ0��䣻���numС��ԭ������������ɾ�����������
// resize(int num, elem); ����ָ�������Ĵ�С�����num>ԭ���Ĵ�С������elem��䣻���numС��ԭ������������ɾ�����������

void printVector(vector<int> &vec){
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void IsEmptyVecotr(vector<int> &vec){
	// �ж������Ƿ�Ϊ��,empty()����bool���͵�ֵ���������true�����ʾ������Ϊ�� 
	if(vec.empty()){
		cout << "������Ϊ��" << endl; 
	}else{
		//cout << "��������Ϊ��!" << endl;
		cout << "������������Ϊ��" << vec.capacity() << "  ";
		cout << "�������Ĵ�СΪ��" << vec.size() << "  ";  
		cout << "�������е�����Ϊ��";
		printVector(vec);//��ӡ�����е�����  
	}
	cout << endl;
}

void test01(){
	
	vector<int> v1;		// �޲ι��죬Ĭ�Ϲ��� 
	IsEmptyVecotr(v1);		//�ж������Ƿ�Ϊ���Լ�������С 
	for(int i=0; i<10; i++){	// ���������и�ֵ 
		v1.push_back(i+10);
	}
	
	IsEmptyVecotr(v1);		//�ж������Ƿ�Ϊ���Լ�������С 
	
	v1.resize(14);			// ����ָ��������С����ʱ�ô��ڵĲ���Ĭ�����0
	IsEmptyVecotr(v1);		//�ж������Ƿ�Ϊ���Լ�������С 
	
	v1.resize(8); 			// ����ָ��������С����ʱɾ����������� 
	IsEmptyVecotr(v1);
	
	// resize���غ��� 
	v1.resize(20,1);		// ����ָ��������С����ʱ�ô��ڵĲ������1
	IsEmptyVecotr(v1);
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
