#include<iostream>
#include<vector>

using namespace std;

// 对vector容器进行赋值的操作是重写了=，operator=();
// vector& operator=(const vector &vec);	//重载等号操作符
// assign(beg, end);			// 将[beg, end)区间中大的数据拷贝赋值给本身 
// assign(n, elem); 			// 将n个elem数据赋值给本身 
//总结：vector赋值方式比较简单，使用operator=,或assign都可以
 
void printVector(vector<int> &vec){
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
}

void test01(){
	
	vector<int> v1;		// 无参构造 
	for(int i=0; i<10; i++){	// 对v1进行赋值 
		v1.push_back(i);
	} 
	printVector(v1);
		
	vector<int> v2 = v1;
	printVector(v2);
	
	vector<int> v3;
	v3.assign(v2.begin(),v2.end());
	printVector(v3);
	
	vector<int> v4;
	v4.assign(10,10);
//	v4.assign(v2.begin(),v2.end());
	printVector(v4);
	
}

int main(){
	
	test01();
	 
	system("pause");
	return 0;
} 
