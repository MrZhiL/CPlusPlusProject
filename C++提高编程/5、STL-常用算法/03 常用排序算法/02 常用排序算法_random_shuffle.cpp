#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime> 

using namespace std;

// random_shuffle(iterator beg, iterator end); 随机排序，将指定范围内的元素随机调整次序 

void MyPrint(int num){
	cout << num << "  "; 
}

void test01(){
	
	// 需要加随机种子，要不每次加结果相同 
	srand((unsigned int)time(NULL)); 
	
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	
	// 随机排序前，容器排序为：
	cout << "随机排序前，容器排序为：" ; 
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl;
	
	// 随机排序后，容器序列为：(利用洗牌算法，打乱次序)
	cout << "随机排序后，容器序列为: ";
	random_shuffle(vec.begin(), vec.end());
	for_each(vec.begin(), vec.end(), MyPrint);
	cout << endl;
	 
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
