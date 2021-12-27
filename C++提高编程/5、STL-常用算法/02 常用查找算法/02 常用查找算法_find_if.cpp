#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ָ�������㷨find_if
// find_if(v.begin, v.end, _Pred); 

// �����������Ͳ��� 
class FindGrateFive{
	public:
		bool operator()(int num){
			return num>15;
		}
};
void test01(){
	
	vector<int> vec;
	for(int i=0; i<10; i++){
		vec.push_back(i+10);
	} 
	
	// ʹ��find_if����vec�����д���5���� 
	vector<int>::iterator it = find_if(vec.begin(), vec.end(), FindGrateFive());
	
	// �жϲ����Ƿ�ɹ� 
	if(it != vec.end()){
		cout << "���ҳɹ�@���ҵ�ֵΪ��" << *it << endl;
	}else{
		cout << "����ʧ�ܣ�������û�и�Ԫ��" << endl; 
	}
}

// �Զ����������͵Ĳ���
class Person{
	public:
		
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		bool operator() (const Person &p){
//			if(p.m_Name == this->m_Name && p.m_Age == this->m_Age){
//				return true;
//			}else{
//				return false;
//			}
			if(p.m_Age > 30){
				return true;
			} else{
				return false;
			}
		}
		
		string m_Name;
		int m_Age;
};

class FindGrateAgeP{
	public:
		bool operator() (const Person &p){
			return p.m_Age > 35;
		}
};

void test02(){
	vector<Person> vec;
	
	vec.push_back(Person("�ŷ�", 32));
	vec.push_back(Person("����", 29));
	vec.push_back(Person("����", 31));
	vec.push_back(Person("�ܲ�", 40));
	vec.push_back(Person("��Ȩ", 38));
	
	Person pfind("��Ȩ",38);
	
	// �����������30�ĳ�Ա 
	vector<Person>::iterator it = find_if(vec.begin(), vec.end(), FindGrateAgeP());
	
	// �ж��Ƿ���ҳɹ�
	if(it != vec.end()){
		cout << "���ҳɹ�����Ԫ�ص�����Ϊ��" << it->m_Name << ", ����Ϊ��" << it->m_Age << endl;
		//cout << "���ҳɹ�����Ԫ�ص�����Ϊ��" << (++it)->m_Name << ", ����Ϊ��" << (++it)->m_Age << endl;
	} else{
		cout << "����ʧ�ܣ�������û�и�Ԫ��" << endl;
	}
} 

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
