#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// replace(beg, end, _Pred, newvalue); // 将[beg, end)区间中满足条件吗_Pred的值替换为newvalue

// 打印的函数对象 
class MyPrint{
	public:
		void operator() (int num){
			cout << num << "  ";
		} 
};

// 使用函数 
bool RepGrateFivty(int num){
	if (num > 30){
		return true;
	}else{
		return false;
	}
}

// 使用函数对象,函数对象和函数选一即可，作用相同 
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
	
	// 打印vec中的元素
	cout << "原容器中的元素为：";
	for_each(vec.begin(), vec.end(), MyPrint());
	cout << endl; 
	
	// 利用replace_if将vec容器中大于50的数替换为0
	replace_if(vec.begin(), vec.end(), RepGrateFivth2(), 0); 
	cout << "将容器中大于30的元素替换为0：";
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
