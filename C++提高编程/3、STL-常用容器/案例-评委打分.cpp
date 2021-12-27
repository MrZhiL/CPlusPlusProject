#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime> 
using namespace std;

// 案例-评委打分
// 案例描述：有五名选手，分别为ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分
// 实现步骤：1、创建五名选手，放到vector容器中；
//			 2、遍历vector容器，取出每一个选手，执行for循环，可以把10个评分存到deque容器中
//			 3、sort算法对deque容器中的分数排序，去除最过分和最低分
// 			 4、deque容器遍历一遍，累计总分
//			 5、获取平均分 

// 创建Person类，用来记录选手的信息 
class Person {
	
	public:
		Person(string name, float score, deque<int> deq){
			this->m_Name = name;
			this->m_Score = score;
			this->D_score = deq;
		} 
		
		string m_Name;	// 选手的姓名 
		float m_Score;	// 记录选手的平均成绩 
		deque<int> D_score;	// 记录评委打分
	
};

// 给选手初始化信息
//void CratePlayer(vector<Person> &vec) {
//	
//	srand(time(NULL));
//	
//	string nameSeed = "ABCDE";
//	
//	for(int i=0; i<5; i++){
//		string name = "选手";
//		name += nameSeed[i]; 
//		
//		// 评委打分
//		deque<int> score;
//		for(int j=0; j<10; j++){
//			score.push_back(rand()%10+1);		// 评委打分为1-10分制 
//		} 
//		
//		sort(score.begin(), score.end());		// 将评委成绩按从小到大的范围排序 
//		score.pop_back();	// 删除最高的成绩 
//		score.pop_front(); 	// 删除最低的成绩
//		
//		float N_score=0;	// 记录平均成绩
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
		string name = "选手";
		name += nameSeed[k];
		deque<int> score;
		vec.push_back(Person(name, 0, score));
	}
}

// 评委打分
void setScore(vector<Person> &vec){
	
	for(vector<Person>::iterator it = vec.begin(); it != vec.end(); it++){
		deque<int> score;
		for(int j=0; j<10; j++){
			score.push_back(rand()%10+1);		// 评委打分为1-10分制 
		} 
		it->D_score = score;
		
		sort(score.begin(), score.end());		// 将评委成绩按从小到大的范围排序 
		score.pop_back();	// 删除最高的成绩 
		score.pop_front(); 	// 删除最低的成绩
		
		float N_score=0;	// 记录平均成绩
		for(int j=0; j<score.size(); j++){
			N_score += score[j];
		}
		N_score = N_score/(score.size());
		
		it->m_Score = N_score;
	}
} 

// 打印选手信息
void printPlayer(const vector<Person> &vec){
	for(vector<Person>::const_iterator it = vec.begin(); it != vec.end(); it++) {
		cout << "选手的姓名为：" << it->m_Name << ", 平均成绩为： " << it->m_Score << endl; 
		cout << "评委打分为： ";
		for(deque<int>::const_iterator it2 = it->D_score.begin(); it2 != it->D_score.end(); it2++){
			cout << *it2 << " ";
		}
		cout << endl;
	}
} 

void test01(){
	
	srand(time(NULL));
	
	vector<Person> player;
	//CratePlayer(player);	// 给选手初始化信息
	CratePlayer2(player);	// 给选手初始化信息
	setScore(player);		// 评委给选手打分 
	
	printPlayer(player);
	
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0;
} 
