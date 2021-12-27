#include<iostream>
#include<set>

using namespace std;

//set/multiset�����Ĳ����ɾ������ 

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
	// ʹ��insert������������Ԫ�� 
	st.insert(89);
	st.insert(79);
	st.insert(81);
	st.insert(8);
	st.insert(19);
	
	// ��������������ӡ����Ԫ�� 
	cout << "st1:"; 
	printSetRoom(st);
	
	cout << "����Ԫ�غ�st1�����Ĵ�СΪ��" << st.size() << endl;
	
	st.erase(st.begin());	// ɾ��λ��Ϊ0��Ԫ��
	cout << "ɾ��λ��Ϊ1��Ԫ�غ�st1��Ԫ��Ϊ��" ; 
	printSetRoom(st); 
	cout << "ɾ��Ԫ�غ�st1�����Ĵ�СΪ��" << st.size() << endl;
	
	st.erase(81);	// ɾ��ֵΪ81������Ԫ�� 
	printSetRoom(st); 
	// ɾ��[begin,end)���������Ԫ��,�൱��clear() 
	st.erase(st.begin(),st.end());
	printSetRoom(st); 
	cout << "ɾ��Ԫ�غ�st1�����Ĵ�СΪ��" << st.size() << endl;
	
} 

int main(){
	
	test01(); 
	
	system("pause");
	return 0; 
}
