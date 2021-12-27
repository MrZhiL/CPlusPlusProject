#include<iostream>
#include<map>

using namespace std;

// map�߳��Ĳ��Һ�ͳ�� 
// ʹ��find����keyֵ�Ƿ���ڣ���������򷵻ظ�ֵ�ĵ�����������������򷵻�mp.end(); 
// count(key) ��������ͳ�Ƽ�ֵΪkey��Ԫ�ظ���������ֵΪ���� 

void printMapRoom(const map<int, int> &mp){
	if(mp.empty()){
		cout << "������Ϊ��@" << endl;
	}
	for(map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++){
		cout << "key = " << it->first << " ,value = " << it->second << endl;
	}
	cout << endl;
}

void test01(){
	map<int, int> mp;
	mp.insert(make_pair(1,10));
	mp.insert(make_pair(3,21));
	mp.insert(make_pair(5,16));
	mp.insert(make_pair(2,17));
	
	mp.insert(map<int, int>::value_type(4,23));
	
	printMapRoom(mp);
	
	int i;
	cout << "��������ҵļ�ֵ��"; 
	cin >> i;
	// ʹ��find����keyֵ�Ƿ���ڣ���������򷵻ظ�ֵ�ĵ�����������������򷵻�mp.end(); 
	if(mp.find(i) != mp.end()){
		cout << "��ֵΪ" << i << "��Ԫ�ش��ڣ���Ԫ��Ϊ��ֵΪ��" << mp.find(i)->first << ", ֵΪ��" << (*mp.find(i)).second << endl; 
	}else{
		cout << "�Ҳ����ü�ֵ@" << endl;
	}
	
	// map�в���������ظ��ļ�ֵ�����mp.count(key)�ķ���ֵΪ1��0
	// multtimap���Բ����ظ��ļ�ֵ����˷���ֵ���Դ���1 
	cout << "��ֵΪ" << i << "��Ԫ�ظ���Ϊ��" << mp.count(i) << endl; 
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
