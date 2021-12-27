#include <iostream>
#include <vector>

using namespace std;

// 分治合并 
void merge(int arr[], int l, int m, int n){
//	cout << l << " " << m << " " << n << endl; 
	int n1 = m-l+1, n2 = n-m;
	// 创建两个临时数组，用来存储两边的元素，以便进行合并 
	int *temp1 = new int[n1+1];
	int *temp2 = new int[n2+1]; 
	for(int i=0;i<n1;++i){
		temp1[i] = arr[l+i];
	}
	for(int i=0;i<n2;++i){
		temp2[i] = arr[m+i+1];
	}
	// 设置哨兵，从而避免每次合并时都判断指向数组的位置
	temp1[n1] = 0x7FFFFFFF;
	temp2[n2] = 0x7FFFFFFF;
	
	// 合并temp1和temp2两个数组
	int k1=0,k2=0;
	for(int i=l; i<=n; ++i){
		arr[i] = temp1[k1] <= temp2[k2] ? temp1[k1++] : temp2[k2++];
		//cout << arr[i] << " ";
	}
	//cout << endl;
}

// 递归排序
void RecursiveSort(int arr[],int l, int r){
	
	if(l < r){
		int mid = (l+r)/2;
		RecursiveSort(arr,l,mid);
		RecursiveSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void printArr(int arr[], int n){
	for(int i=0; i<n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	string s = "helloworld";
	for(char c : s){
		cout << c;
	} 
	cout << endl;
	int arr[] = {9,8,7,6,5,4,3,2,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArr(arr,n);
	RecursiveSort(arr,0,n-1);
	printArr(arr,n);
}
