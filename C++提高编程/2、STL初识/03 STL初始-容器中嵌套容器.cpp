#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 容器中嵌套容器：相当于二维数组 

// 容器中存储内置数据类型 
void test01(){
	
	vector< vector<int> > v;
	
	// 创建小容器 
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	
	for(int i=1;i<=5;i++){
		v2.push_back(i);
		v3.push_back(i+5);
		v4.push_back(i+10);
		
	}

	// 将小容器插入到大容器中 
	v.push_back(v2); 
	v.push_back(v3); 
	v.push_back(v4); 
	
	for(vector<vector<int> >::iterator it = v.begin(); it != v.end(); it++){
		cout << "it" << "" << ":" << endl;
		for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++){
			cout << *it2 << "  ";
		}
		cout << endl;
	}
}

int main(){

	test01();
	
	system("pause");
	return 0;
} 
