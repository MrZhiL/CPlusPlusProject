#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// ���ò����㷨��find�㷨 

// �����������Ͳ��� 
void showVec(int num){
	cout << num << "  ";
}
void test01(){
	vector<int> vec;
	vec.push_back(19); 
	vec.push_back(15); 
	vec.push_back(17); 
	vec.push_back(21); 
	vec.push_back(8);
	vec.push_back(19);
	
	// ��ӡvec�����е�Ԫ��
	for_each(vec.begin(), vec.end(), showVec); 
	cout << endl;
	
	// �����������������Ƿ����,��������򷵻ظ����ݵĵ�����������������򷵻ؽ��������� 
	vector<int>::iterator it = find(vec.begin(), vec.end(), 19);
	if(it == vec.end()){
		cout << "δ�ҵ���Ԫ�أ�" << endl;
	}else{
		cout << "�ҵ���Ԫ��: " << *it << endl;
		//cout << *(++it) << endl; 
	}
	 
} 

// �Զ����������Ͳ���
class Person{
	public:
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		// ���Ҫ�����Զ����������ͣ�����Ҫ����==�����������find������ζ��Զ����������ͶԱ�
		bool operator==(const Person &p){
			if(p.m_Age == this->m_Age && p.m_Name == this->m_Name){
				return true;
			}else{
				return false;
			}
		} 
		
		string m_Name;
		int m_Age;
};

void test02(){
	vector<Person> vec;
	
	vec.push_back(Person("�ŷ�", 32));
	vec.push_back(Person("����", 29));
	vec.push_back(Person("����", 31));
	vec.push_back(Person("�ܲ�", 40));
	vec.push_back(Person("��Ȩ", 38));
	
	// �����Զ����������� 
	Person pf("��Ȩ", 38);
	vector<Person>::iterator it = find(vec.begin(), vec.end(), pf);
	// �ж��Ƿ���ҵ���Ԫ�� 
	if(it == vec.end()){
		cout << "δ�ҵ���Ԫ�أ�" << endl;
	}else{
		cout << "�ҵ���Ԫ��@��Ԫ�ص�����Ϊ��" << it->m_Name << ", ����Ϊ��" << it->m_Age << endl;  
	}
	
} 

int main(){
	
	//test01(); 
	test02();
	
	system("pause");
	return 0;
} 
