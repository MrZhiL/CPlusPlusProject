#include <iostream>
#include <cstdio>

using namespace std;

void insertSort(int arr[],int n){
	if(n < 2) return;
	// 执行插入排序，从第二个元素开始，然后执行插入过程 
	for(int k = 1; k < n; k++){
		int key = arr[k];	// 记录要插入的元素的大小
		int j = k-1;		// 从k位置开始，依次向左遍历查找，如果key小于arr[j]，则将arr[j]移到末尾 
		while(j >=0 && key < arr[j]) {
			arr[j+1] = arr[j];
			j--; 
		}
		arr[j+1] = key;
	}
}

void print_arr(int* arr, int n){
	for(int i=0; i<n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[] = {5,2,4,6,1,3};
	cout << "排序前：";
	print_arr(arr,sizeof(arr)/sizeof(arr[0]));
	
	cout << "排序后："; 
	insertSort(arr,sizeof(arr)/sizeof(arr[0]));
	print_arr(arr,sizeof(arr)/sizeof(arr[0]));
	
	
	return 0;
	
} 
