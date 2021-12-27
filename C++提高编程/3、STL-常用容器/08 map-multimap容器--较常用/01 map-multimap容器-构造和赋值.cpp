#include<iostream>
#include<map> 

using namespace std;

// map�����Ĺ���͸�ֵ 
// map�����ڲ���Ԫ�ص�ʱ�򣬻��Զ�����keyֵ��������
// map�����в������ظ�������ͬ��keyֵ������valueֵ������ͬ

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
	
	printMapRoom(mp);
	
	// �������캯�� 
	map<int, int> mp2(mp); 
	printMapRoom(mp2);
	
	// ��ֵ
	map<int, int> mp3;
	mp3 = mp2;
	printMapRoom(mp3);
	 
} 
 
int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
