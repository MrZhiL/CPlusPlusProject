#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// replace(beg, end, _Pred, newvalue); // ��[beg, end)����������������_Pred��ֵ�滻Ϊnewvalue

// ��ӡ�ĺ������� 
class MyPrint{
	public:
		void operator() (int num){
			cout << num << "  ";
		} 
};

// ʹ�ú��� 
bool RepGrateFivty(int num){
	if (num > 30){
		return true;
	}else{
		return false;
	}
}

// ʹ�ú�������,��������ͺ���ѡһ���ɣ�������ͬ 
class RepGrateFivth2{
	public:
		bool operator() (int num){
			if (num > 30){
				return true;
			}else{
				return false;
			}
		}
}; 

void test01(){
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(5*i);
	}
	
	// ��ӡvec�е�Ԫ��
	cout << "ԭ�����е�Ԫ��Ϊ��";
	for_each(vec.begin(), vec.end(), MyPrint());
	cout << endl; 
	
	// ����replace_if��vec�����д���50�����滻Ϊ0
	replace_if(vec.begin(), vec.end(), RepGrateFivth2(), 0); 
	cout << "�������д���30��Ԫ���滻Ϊ0��";
	for_each(vec.begin(), vec.end(), MyPrint());
	cout << endl;

	vector<int> vec2;
	vec2.push_back(111); 
	vec2.push_back(222); 
	vec2.push_back(333); 
	vec2.push_back(444); 
	
	vec.swap(vec2);
	for_each(vec.begin(), vec.end(), MyPrint());
	cout << endl;

} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
