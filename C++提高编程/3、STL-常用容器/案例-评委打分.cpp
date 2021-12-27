#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime> 
using namespace std;

// ����-��ί���
// ����������������ѡ�֣��ֱ�ΪABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ����
// ʵ�ֲ��裺1����������ѡ�֣��ŵ�vector�����У�
//			 2������vector������ȡ��ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ浽deque������
//			 3��sort�㷨��deque�����еķ�������ȥ������ֺ���ͷ�
// 			 4��deque��������һ�飬�ۼ��ܷ�
//			 5����ȡƽ���� 

// ����Person�࣬������¼ѡ�ֵ���Ϣ 
class Person {
	
	public:
		Person(string name, float score, deque<int> deq){
			this->m_Name = name;
			this->m_Score = score;
			this->D_score = deq;
		} 
		
		string m_Name;	// ѡ�ֵ����� 
		float m_Score;	// ��¼ѡ�ֵ�ƽ���ɼ� 
		deque<int> D_score;	// ��¼��ί���
	
};

// ��ѡ�ֳ�ʼ����Ϣ
//void CratePlayer(vector<Person> &vec) {
//	
//	srand(time(NULL));
//	
//	string nameSeed = "ABCDE";
//	
//	for(int i=0; i<5; i++){
//		string name = "ѡ��";
//		name += nameSeed[i]; 
//		
//		// ��ί���
//		deque<int> score;
//		for(int j=0; j<10; j++){
//			score.push_back(rand()%10+1);		// ��ί���Ϊ1-10���� 
//		} 
//		
//		sort(score.begin(), score.end());		// ����ί�ɼ�����С����ķ�Χ���� 
//		score.pop_back();	// ɾ����ߵĳɼ� 
//		score.pop_front(); 	// ɾ����͵ĳɼ�
//		
//		float N_score=0;	// ��¼ƽ���ɼ�
//		for(int j=0; j<score.size(); j++){
//			N_score += score[j];
//		}
//		N_score = N_score/score.size();
//		
//		vec.push_back(Person(name, N_score));
//	}
//}

void CratePlayer2(vector<Person> &vec) {
	
	string nameSeed = "ABCDE";

	for(int k=0; k<5; k++){
		string name = "ѡ��";
		name += nameSeed[k];
		deque<int> score;
		vec.push_back(Person(name, 0, score));
	}
}

// ��ί���
void setScore(vector<Person> &vec){
	
	for(vector<Person>::iterator it = vec.begin(); it != vec.end(); it++){
		deque<int> score;
		for(int j=0; j<10; j++){
			score.push_back(rand()%10+1);		// ��ί���Ϊ1-10���� 
		} 
		it->D_score = score;
		
		sort(score.begin(), score.end());		// ����ί�ɼ�����С����ķ�Χ���� 
		score.pop_back();	// ɾ����ߵĳɼ� 
		score.pop_front(); 	// ɾ����͵ĳɼ�
		
		float N_score=0;	// ��¼ƽ���ɼ�
		for(int j=0; j<score.size(); j++){
			N_score += score[j];
		}
		N_score = N_score/(score.size());
		
		it->m_Score = N_score;
	}
} 

// ��ӡѡ����Ϣ
void printPlayer(const vector<Person> &vec){
	for(vector<Person>::const_iterator it = vec.begin(); it != vec.end(); it++) {
		cout << "ѡ�ֵ�����Ϊ��" << it->m_Name << ", ƽ���ɼ�Ϊ�� " << it->m_Score << endl; 
		cout << "��ί���Ϊ�� ";
		for(deque<int>::const_iterator it2 = it->D_score.begin(); it2 != it->D_score.end(); it2++){
			cout << *it2 << " ";
		}
		cout << endl;
	}
} 

void test01(){
	
	srand(time(NULL));
	
	vector<Person> player;
	//CratePlayer(player);	// ��ѡ�ֳ�ʼ����Ϣ
	CratePlayer2(player);	// ��ѡ�ֳ�ʼ����Ϣ
	setScore(player);		// ��ί��ѡ�ִ�� 
	
	printPlayer(player);
	
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0;
} 
