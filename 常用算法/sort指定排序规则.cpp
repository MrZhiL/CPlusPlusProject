#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int x,int y){
	return x>y;
}

void print_arr(int arr[], int n){
	for(int i=0; i<n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[] = {1,6,2,3,6,2,2,7,89,10,15,36};
	int n = sizeof(arr)/sizeof(arr[0]);
	// 指定sort按从大到小的顺序排序
	sort(arr,arr+n,cmp); 
	print_arr(arr,n);
	return 0;
} 
