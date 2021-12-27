#include<iostream>
#include<set>

using namespace std;

//set/multiset�����Ĳ����ɾ������ 
// ʹ��find(key)����keyֵ�Ƿ���ڣ�������ڷ��ظ�Ԫ�صĵ�����������������򷵻�set.end(); 
// ʹ��count(key) ͳ��keyֵ�ĸ��� 

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
	
	multiset<int> st;
	
	// ��������������ӡ����Ԫ�� 
	cout << "��������ǰ��" ; 
	printMultiSetRoom(st);
	
	cout << "--------------------------" << endl;
	cout << "�������ݺ�" << endl;;
	// ʹ��insert������������Ԫ�� 
	st.insert(89);
	st.insert(79);
	st.insert(81);
	st.insert(8);
	st.insert(19);
	st.insert(19);
	st.insert(19);
	
	// ��������������ӡ����Ԫ�� 
	cout << "st1:"; 
	printMultiSetRoom(st);
	
	cout << "����Ԫ�غ�st1�����Ĵ�СΪ��" << st.size() << endl;
	
	// st.find(key)���ص��ǵ�������������*�������ҳ�����
	//set<int>::iterator it = st.find(19); 
	cout << "Ԫ��19�����ڵ�λ��Ϊ��" << *st.find(89) << endl;
	
	// ͳ��������keyԪ�صĸ���
	cout << "Ԫ��19�ĸ���Ϊ��" << st.count(19) << endl; 
} 

int main(){
	
	test01(); 
	
	system("pause");
	return 0; 
}
