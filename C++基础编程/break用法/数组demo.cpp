#include <iostream>

using namespace std;

int main(){
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	
	int arr2[3];
	arr2[0] = 11;
	arr2[1] = 12;
	arr2[2] = 13;
	
	cout << arr2[0] << endl;
	cout << arr2[1] << endl;
	cout << arr2[2] << endl;
	
	// 如果赋值时没有全部赋值，则其余用0补全 
	int arr3[5] = {10,20,30};
	for (int i=0;i<5;i++){
		
		cout << arr3[i] << endl; 
	}
	
	cout << sizeof(arr) << arr << endl;
	cout << &arr[2] << endl;
	cout << sizeof(arr2) << endl;
	cout << sizeof(arr3) << endl; 
	
	system("pause");
	return 0;
	
	
}
