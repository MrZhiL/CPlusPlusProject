#include<iostream>
#include<set>

using namespace std;

// �����º������ı��������
class MyCompare{
	
	public:
		bool operator() (int num1, int num2){
			// ʹ�����е�Ԫ�ذ��Ӵ�С�ķ�ʽ���� 
			return num1>num2;	
		}
};

void printSetRoom(const set<int> &st){
	
	if(st.empty()){
		cout << "����Ϊ�գ�" << endl;
		return ;
	}
	
	for(set<int>::const_iterator it = st.begin(); it != st.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

void test01(){
	
	set<int> st;
	// set��������Ԫ��ʱ�������Ĭ������
	// set����ʹ��insert����Ԫ�غ���Ѿ����򣬲��ɸ���
	// ��ˣ������Ҫ�ı������������Ҫ�ڲ���֮ǰ�͸ı�������� 
	st.insert(10);
	st.insert(22);
	st.insert(8);
	st.insert(19);
	st.insert(43);
	
	// ����
	cout << "Ĭ�����򣨴�С���󣩣�"; 
	printSetRoom(st);
	
	// ���дӴ�С������ 
	set<int,MyCompare> st2;
	// ͨ���º����ı�������������� 
	st2.insert(10);
	st2.insert(22);
	st2.insert(8);
	st2.insert(19);
	st2.insert(43);
	// ����
	cout << "ͨ���º����ı�������򣨴Ӵ�С����"; 
	
	for(set<int, MyCompare>::iterator it = st2.begin(); it != st2.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0;
} 
