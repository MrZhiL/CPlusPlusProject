#include<iostream>
#include<set>

using namespace std;

// set-multiset�����Ĺ��캯��
// set/multiset�������ǰ��������ķ�ʽ�洢���� 

// set�������ص㣺�������ݺ���Զ�����������set�����в���������ظ���Ԫ��
// multiset�������������ݺ�Ҳ���Զ��������򣬵�multiset�������Բ����ظ���Ԫ�� 
// multiset��set����������setһ��ͷ�ļ�

//template<class T>  
void printSetRoom(set<int> &st){
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  "; 
	}
	cout << endl;
}

void printMultiSetRoom(multiset<int> &st){
	for(multiset<int>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  "; 
	}
	cout << endl;
}

void test01(){
	
	// ����set������Ĭ�Ϲ��캯�� 
	set<int> set1;
	
	// set����ֻ����insert����Ԫ�أ��Ҳ���������ظ���Ԫ�� 
	set1.insert(10);
	set1.insert(8);
	set1.insert(20); 
	set1.insert(30); 
	set1.insert(50); 
	
	printSetRoom(set1);
	
	// �������캯�� 
	set<int> set2(set1); 
	printSetRoom(set1);
	
	// ��ֵ�����صȺ�������� 
	set<int> set3;
	set3 = set2; 
	printSetRoom(set1);
	
	// multiset����,��������ظ���Ԫ�� 
	multiset<int> mst;
	mst.insert(3); 
	mst.insert(111); 
	mst.insert(21); 
	mst.insert(31); 
	mst.insert(8); 
	mst.insert(31); 
	printMultiSetRoom(mst);
	cout << *mst.rbegin() << endl; 
	cout << *mst.begin() << endl; 
	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
