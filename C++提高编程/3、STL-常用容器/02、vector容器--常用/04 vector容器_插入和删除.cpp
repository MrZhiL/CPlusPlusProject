#include<iostream>
#include<vector>

using namespace std;

/**
	push_back(ele);									//��β������Ԫ��ele 
	pop_back();										//ɾ�����һ��Ԫ�� 
	insert(const_iterator pos, ele);				//�� ������ָ ��λ��pos����Ԫ��ele 
	insert(cosnt_iterator pos, int count, ele);		//�� ������ ָ��λ��pos����count��ele 
	erase(const_iterator pos);						//ɾ�� ������ ָ��λ��pos��Ԫ�� 
	erase(const_iterator start, const_iterator end);//ɾ�� ������ ��start��end֮���Ԫ�� 
	clear();//ɾ������������Ԫ�� 
*/ 

// ��������е�Ԫ�� 
void printVector(vector<int> &vec){
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
// �ж������Ƿ�Ϊ��
void IsEmptyVector(vector<int> &vec){
	
	if(vec.empty()){
		cout << "����Ϊ�գ�" << endl;
		return;
	}else{
		cout << "������������Ϊ��" << vec.capacity() << " ";
		cout << "�������Ĵ�СΪ��" << vec.size() << "  ";
		cout << "Ԫ��Ϊ��";
		printVector(vec);
	}
	
} 

void test01(){
	
	vector<int> vec;
	IsEmptyVector(vec); 
	//printVector(vec);
	for(int i=0; i<10; i++){
		vec.push_back(i+1);	//ʹ��push_back()β�巨��������Ԫ�� 
	}
	IsEmptyVector(vec);
	
	vec.pop_back();			//ʹ��pop_back()βɾ��ɾ�����һ��Ԫ��
	IsEmptyVector(vec);
	
	// ��Ҫʹ�õ����� 
	vec.insert(vec.begin(),5,5);		//�� ������ ͷ������5��5 
	IsEmptyVector(vec);
	
	// ʹ�õ�����ȥ��ɾ��vec�����ĵ�һ������ 
	vec.erase(vec.begin());
	IsEmptyVector(vec);
	
	// ����������ݣ��൱��clear(); 
	vec.erase(vec.begin(),vec.end());
	IsEmptyVector(vec);
	
	vec.clear();//ɾ������������Ԫ�� 
	IsEmptyVector(vec);
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
