#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// ����һ��Phone��
class Phone{
public:
	
	string name;		// ���� 
	vector<string> tel;	// �绰���루���԰�������绰���룩 

}; 

void PrintPhone(const vector<Phone> p){
	int n = p.size();
	for(int i=0; i<n; ++i){
		cout << "name:" << p[i].name << "   tel:";
		ostringstream format;
		for(int j=0; j<p[i].tel.size(); ++j){
			format << " " << p[i].tel[j];	// ����ʹ��ostringstream������� 
			//cout << p[i].tel[j] << " ";
		}
		// ���ʹ��ostringstream�����������Ҫʹ��.str()���� 
		cout << format.str() << endl;
	}
}


void test01(){
	string s,word;				// �ֱ������������������һ�к͵���	
	vector<Phone> p;			// ����������������м�¼ 
	// ���д������ȡ���ݣ�ֱ��cin�����ļ�β������������ 
	int k=0;
	while(k < 3 && getline(cin,s)){
		Phone p_temp;			// ����һ������˼�¼���ݵĶ��� 
		istringstream record(s);// ����¼�󶨵��ն������ 
		record >> p_temp.name;	// ��ȡ����	 
		while(record >> word){	// ��ȡ�绰 
			p_temp.tel.push_back(word);	// �������� 
		}			
		p.push_back(p_temp);	// ���˼�¼׷�ӵ�pĩβ
		k++;
	}
	PrintPhone(p);
}

int main(){
	test01();
	return 0;
} 
