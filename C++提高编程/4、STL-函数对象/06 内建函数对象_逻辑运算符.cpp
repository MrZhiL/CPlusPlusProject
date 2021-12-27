#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

// �ڽ����������߼������
// bool logical_and<T>��bool logical_or<T>��bool logical_not<T> 

void showVector(vector<bool> &val){
	for(vector<bool>::iterator it = val.begin(); it != val.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}

void test01(){
	
	vector<bool> v;
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);
	
	cout << "v: ";
	showVector(v);
	
	// �����ڽ������е��߼������������v����ȡ��������Ȼ��洢��v2��
	vector<bool> v2;
	// ��v2�Ŀռ������v�Ĵ�С�����������ռ䣬��ᱨ�� 
	v2.resize(v.size());
	// v2.reserve(v.size()); //reserve()Ԥ���������У�ֻ��ʹ��resize()���� 
	transform(v.begin(), v.end(), v2.begin(),logical_not<bool>());
	cout << "v2: ";
	showVector(v2); 
	
	// �����ڽ������е��߼������������v2��v3�����������Ȼ��洢��v4��
	vector<bool> v3;
	vector<bool> v4;
	
	// ��v4�Ŀռ������v3�Ĵ�С�����������ռ䣬��ᱨ�� 
	v3.push_back(false);
	v3.push_back(true);
	v3.push_back(false);
	v3.push_back(true);
	v3.push_back(true);
	
	cout << "v3: ";
	showVector(v3);
	 
	v4.resize(v3.size());
	
	//��v2��v3�����������Ȼ��洢��v4��
	//ʹ���߼�����߼������ʱ(��c=a&b)��transform����Ҫ�У�a.begin,a.end,b.begin,c.begin, logical_and<bool>();
	transform(v2.begin(), v2.end(), v3.begin(), v4.begin(), logical_and<bool>());
	
	cout << "v4(v2&v3): ";
	showVector(v4); 
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
