#include<iostream>
#include<set>

using namespace std;

// set��multiset������
// set��multiset�ڲ������ݺ���Զ���������
// set�������ظ�����Ԫ�أ���Ϊset�����ڲ������ݺ󣬻᷵�ز���Ľ������ʾ�����Ƿ�ɹ�
// multiset�е�Ԫ�ز���ɹ��󣬲��������ݣ����Կ����ظ����� 

void test01(){
	
	set<int> st;
	multiset<int> mst;
	
	pair<set<int>::iterator, bool> ret = st.insert(10);
	
	// ���pair�����з��ص�boolΪ�棬���ʾ����ɹ��������ʾ����ʧ�� 
	if(ret.second){
		cout << "��һ��Ԫ�ز���ɹ���" << endl; 
	}else{
		cout << "�ڶ���Ԫ�ز���ʧ�ܣ�" << endl;
	}	

	ret = st.insert(10);
	if(ret.second){
		cout << "��һ��Ԫ�ز���ɹ���" << endl; 
	}else{
		cout << "�ڶ���Ԫ�ز���ʧ�ܣ�" << endl;
	}
	
	
	mst.insert(11);
	mst.insert(11);
	for(multiset<int>::iterator it = mst.begin(); it != mst.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
