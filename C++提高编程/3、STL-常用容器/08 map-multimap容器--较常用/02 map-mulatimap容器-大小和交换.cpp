#include<iostream>
#include<map> 

using namespace std;

// map�����Ĵ�С�ͽ��� 
// size();  empty();  swap(map<T,T> &st); 

void printMapRoom(const map<int, int> &mp) {
	
	if(mp.empty()){
		cout << "������Ϊ�գ�" << endl;
		return ;
	}
	for(map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++){
		cout << "key = " << (*it).first << ", value = " << it->second << endl; 
	}
	cout << endl;
}

void test01(){
	map<int, int> mp;

	// ��map�����в���Ԫ�أ�����Ԫ��ʱ�����������ظ���keyֵ����
	// ��Ϊmap����������ֵ��key��value�������Ҫʹ��pair(����)���и�ֵ 
	mp.insert(pair<int, int>(1, 10)); 
	mp.insert(pair<int, int>(5, 50)); 
	mp.insert(pair<int, int>(3, 50)); 
	mp.insert(pair<int, int>(4, 40)); 
	mp.insert(pair<int, int>(2, 20)); 
	mp.insert(pair<int, int>(1, 110)); 	// ����ʧ�ܣ�map�����в���������ͬ��keyֵ 
	mp.insert(pair<int, int>(6, 10)); 	// ����ɹ�����������ͬ��valueֵ 

	cout << "st�����Ĵ�СΪ��" << mp.size() << endl;	
	printMapRoom(mp);
	
	// �������캯�� 
	map<int, int> mp2; 
	mp2.insert(pair<int, int>(101, 199)); 
	mp2.insert(pair<int, int>(102, 142)); 
	mp2.insert(pair<int, int>(103, 113)); 
	mp2.insert(pair<int, int>(108, 118)); 
	mp2.insert(pair<int, int>(106, 186)); 
	cout << "st2�����Ĵ�СΪ��" << mp2.size() << endl;
	printMapRoom(mp2);
	
	cout << "----------------------------------------" << endl;
	cout << "��st������st2����������" << endl;
	mp2.swap(mp);
	
	cout << "st������" << endl;
	cout << "st�����Ĵ�СΪ��" << mp.size() << endl;
	printMapRoom(mp);
	
	cout << "st2������" << endl;
	cout << "st2�����Ĵ�СΪ��" << mp2.size() << endl;
	printMapRoom(mp2);
	 
} 
 
int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
