#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// ���ò����㷨_count(beg, end, value);

// 1��ͳ��������������

void test01(){
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(13);
	vec.push_back(15);
	vec.push_back(11);
	vec.push_back(10);
	vec.push_back(10);
	
	// ͳ��vec������Ԫ��10������
	int num = count(vec.begin(), vec.end(), 10); 
	
	cout << "Ԫ��10�ĸ���Ϊ��" << num << endl;
}

// 2��ͳ���Զ����������� 
class Person{
	public:
		Person(string name, int age){
			this->m_Name = name,
			this->m_Age = age;
		}
		
		// ���ͳ���Զ����������ͣ�����Ҫ����== 
		bool operator== (const Person &p){
			if(this->m_Age == p.m_Age){
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
	vec.push_back(Person("�ӵ�", 40));
	vec.push_back(Person("�ܲ�", 40));
	vec.push_back(Person("��Ȩ", 38));
	vec.push_back(Person("С��", 32));
	vec.push_back(Person("����", 32));
	
	// ͳ������Ϊ32������ 
	int num = count(vec.begin(), vec.end(), Person("as",32));
	cout << "����Ϊ32�Ĺ��� " << num << "�ˣ�" << endl;
}

int main(){
	
	//test01();
	test02();
	
	system("pause");
	return 0;
} 
