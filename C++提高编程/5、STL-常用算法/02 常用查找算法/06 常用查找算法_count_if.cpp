#include<iostream>
#include<algorithm>
#include<string> 
#include<vector>

using namespace std;

// ���ò����㷨��_count_if(beg, end, _Pred);//������ͳ��Ԫ�ظ���

// �����������Ͱ�����ͳ��

class GrateThirteenNum{
	public:
		bool operator() (int num){
			return num >= 13;
		}
};

void test01(){
	vector<int> vec;
	
	vec.push_back(10);
	vec.push_back(13);
	vec.push_back(15);
	vec.push_back(11);
	vec.push_back(10);
	vec.push_back(10);
	vec.push_back(16);
	
	// ͳ��Ԫ���д��ڵ���13�ĸ���
	int num = count_if(vec.begin(), vec.end(), GrateThirteenNum());
	
	cout << "vec�����д��ڵ���13��Ԫ�ظ���Ϊ��" << num << endl;
} 

// �Զ����������Ͱ�����ͳ�� 

class Person{
	public:
		Person(string name, int age){
			this->m_Name = name;
			this->m_Age = age;
		}
		
		// ���ͳ���Զ����������ͣ�����Ҫ���ضԱȲ����� 
		bool operator== (const Person &p){
			if(this->m_Age == p.m_Age){
				return true;
			}else
				return false;
		} 
		
		string m_Name;
		int m_Age;
};

bool GrateThirteenNum02(const Person &p){
	if(p.m_Age >= 35){
		return true;
	}else{
		return false;
	}
}

void test02(){
	
	vector<Person> vec;
	
	vec.push_back(Person("�ŷ�", 32));
	vec.push_back(Person("����", 29));
	vec.push_back(Person("����", 31));
	vec.push_back(Person("�ӵ�", 40));
	vec.push_back(Person("�ܲ�", 40));
	vec.push_back(Person("��Ȩ", 38));
	vec.push_back(Person("С��", 32));
	vec.push_back(Person("����", 32));
	
	// ͳ��������ڵ���35������ 
	int num = count_if(vec.begin(), vec.end(), GrateThirteenNum02); 
	cout << "�������35���������У�" << num << endl;
}

int main(){
	
	//test01();
	test02();
		
	system("pause");
	return 0;
}
