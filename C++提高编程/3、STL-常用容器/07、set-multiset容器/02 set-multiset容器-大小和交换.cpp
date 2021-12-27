#include<iostream>
#include<set>

using namespace std;

//set/multiset�����Ĵ�С�ͽ���

void printSetRoom(set<int> &st){
	
	if(st.empty()){
		cout << "����Ϊ��@" << endl;
		return ;
	}
	
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  "; 
	}
	cout << endl;
}

void printMultiSetRoom(multiset<int> &st){
	
	if(st.empty()){
		cout << "����Ϊ��@" << endl;
		return ;
	}
	
	for(multiset<int>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  "; 
	}
	cout << endl;
}


void test01(){
	
	set<int> st;
	
	// ��������������ӡ����Ԫ�� 
	cout << "��������ǰ��" ; 
	printSetRoom(st);
	
	cout << "--------------------------" << endl;
	cout << "�������ݺ�" << endl;;
	st.insert(89);
	st.insert(79);
	st.insert(81);
	st.insert(8);
	st.insert(19);
	
	// ��������������ӡ����Ԫ�� 
	cout << "st1:"; 
	printSetRoom(st);
	
	cout << "����Ԫ�غ�st1�����Ĵ�СΪ��" << st.size() << endl;
	
	set<int> st2;
	st2.insert(1); 
	st2.insert(2); 
	st2.insert(9); 
	st2.insert(8); 
	
	cout << "st2:";
	printSetRoom(st2);
	cout << "����Ԫ�غ�st1�����Ĵ�СΪ��" << st.size() << endl;
	
	cout << "-------------------------------" << endl;
	cout << "��st1��st2�����������ݽ�����������" << endl;
	st2.swap(st);
	cout << "st1: ";
	printSetRoom(st);
	cout << "st2: ";
	printSetRoom(st2);
	
} 

int main(){
	
	test01(); 
	
	system("pause");
	return 0; 
}
