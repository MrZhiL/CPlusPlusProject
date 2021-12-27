#include <iostream>

using namespace std;

int main(){
	
	// goto语句
	
	cout << "第一步" << endl; 
	
	goto FLAG;
	
	cout << "第二步" << endl; 
	cout << "第三步" << endl; 
	cout << "第四步" << endl; 
	
	FLAG: 
		cout << "直接跳转：第五步" << endl; 
	
	system("pause");
	
	return 0; 
	
} 
