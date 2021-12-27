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
	
	// ��һ�ֲ��뷽ʽ 
	mp.insert(pair<int, int>(1, 10)); 
	mp.insert(pair<int, int>(5, 50)); 
	mp.insert(pair<int, int>(3, 50)); 
	mp.insert(pair<int, int>(4, 40)); 
	mp.insert(pair<int, int>(2, 20)); 
	mp.insert(pair<int, int>(1, 110)); 	// ����ʧ�ܣ�map�����в���������ͬ��keyֵ 
	mp.insert(pair<int, int>(6, 10)); 	// ����ɹ�����������ͬ��valueֵ 
	
	// �ڶ��ֲ��뷽ʽ���Ƽ�ʹ�ø��ַ����� 
	mp.insert(make_pair(7,77));
	
	// �����ֲ��뷽ʽ
	mp.insert(map<int, int>::value_type(8,88));
	
	// �����ֲ��뷽ʽ---������ʹ�ø��ַ�ʽ 
	mp[9] = 99;
	
	// �����ӡ��mp[key]Ԫ���У���ֵΪkey��Ԫ�ز����ڣ���������Զ�����mp[key] = 0
	// mp[key]���ַ�������ͨ��keyֵ���ʵ�valueֵ 
	cout << "mp[9] = " << mp[9] << endl; 
	
	cout << "st�����Ĵ�СΪ��" << mp.size() << endl;	
	printMapRoom(mp);
	
	// ɾ��keyΪkey�ĵ�Ԫ��
	mp.erase(1); 
	cout << "st�����Ĵ�СΪ��" << mp.size() << endl;	
	printMapRoom(mp);
	
	// ɾ��mp�����е����һ��Ԫ��,�����е����һ��Ԫ��λ��Ϊ--mp.end() 
	mp.erase(--mp.end());
	cout << "st�����Ĵ�СΪ��" << mp.size() << endl;	
	printMapRoom(mp); 
	
	// ɾ��[beg,end)���������Ԫ��,beg��end�õ�������ʾ
	mp.erase(++mp.begin(),--mp.end());
	cout << "st�����Ĵ�СΪ��" << mp.size() << endl;	
	printMapRoom(mp);
	
	// ɾ������Ԫ�� 
	mp.clear();
	cout << "st�����Ĵ�СΪ��" << mp.size() << endl;	
	printMapRoom(mp);
	
} 
 
int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
