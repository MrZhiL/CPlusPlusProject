#include <iostream>
#include <cstdio>

using namespace std;

void insertSort(int arr[],int n){
	if(n < 2) return;
	// ִ�в������򣬴ӵڶ���Ԫ�ؿ�ʼ��Ȼ��ִ�в������ 
	for(int k = 1; k < n; k++){
		int key = arr[k];	// ��¼Ҫ�����Ԫ�صĴ�С
		int j = k-1;		// ��kλ�ÿ�ʼ����������������ң����keyС��arr[j]����arr[j]�Ƶ�ĩβ 
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
	cout << "����ǰ��";
	print_arr(arr,sizeof(arr)/sizeof(arr[0]));
	
	cout << "�����"; 
	insertSort(arr,sizeof(arr)/sizeof(arr[0]));
	print_arr(arr,sizeof(arr)/sizeof(arr[0]));
	
	
	return 0;
	
} 
