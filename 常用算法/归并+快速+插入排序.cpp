#include <iostream>
#include <vector>

using namespace std;

// 分治合并
void merge(int arr[], int l, int m, int r);

// 归并排序（） 
void merge_Sort(int arr[], int l, int r);

// 快速排序
void QuickSort(int arr[], int l, int r);

// 插入排序
void InsertSort(int arr[], int n); 

void print_arr(int arr[], int n){
	for(int i=0; i<n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
} 

int main(){
	
	int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << "排序前："; 
	print_arr(arr,n);
	
	cout << "排序后（顺序）：";
	merge_Sort(arr,0,n-1);
	print_arr(arr,n);
	
	cout << "快速排序后（逆序）：";
	QuickSort(arr,0,n-1);
	print_arr(arr,n);
	
	cout << "插入排序(顺序): ";
	InsertSort(arr,n-1);
	print_arr(arr,n); 
}

// 归并排序（从小到大排序） 
void merge_Sort(int arr[], int l, int r){
	// 如果l>=r,说明此时数组中只有一个元素，已经排好序，无需在再次排序 
	if(l < r){
		int mid = (l+r)/2;
		merge_Sort(arr,l,mid);
		merge_Sort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

// 插入排序 (从小到大排序)
void InsertSort(int arr[], int n){
	int i=0;
	for(int k=1; k<=n; ++k){
		int temp = arr[k],j=k;
		while(j > 0 && temp < arr[j-1]){
			arr[j] = arr[j-1];
			--j;
		}
		arr[j] = temp;
	}
} 


// 快速排序（从大到小排序） 
void QuickSort(int arr[], int l, int r){
	if(l < r){
		int key = arr[l];	// 令第一个元素为基准 
		int left = l, right = r;
		// 先从右往前找第一个大于arr[key]的元素 
		while(left < right){
			while(left < right && arr[right] <= key) --right;
			 
			if(left < right) arr[left++] = arr[right];
			
			while(left < right && arr[left] >= key) ++left;
			
			if(left < right) arr[right--] = arr[left];
			
		} 
		// 将基准数放入 
		arr[left] = key; 
		
		// 执行分治操作，递归调用
		QuickSort(arr,l,left-1);
		QuickSort(arr,left+1,r);
	}
	
} 

// 分治合并
void merge(int arr[], int l, int m, int r){
	int n1 = m-l+1,n2 = r-m;
	// 创建两个临时数组，用来存储arr[l,m]和arr[m+1,r]中的元素 
	int temp1[n1+1],temp2[n2+1];
	for(int i=0; i<n1; ++i){
		temp1[i] = arr[i+l];
	}
	for(int i=0;i<n2;++i){
		temp2[i] = arr[i+m+1];
	}
	// temp1和temp2数组的最后一个元素存放哨兵位，避免每次判断是否到达数组末尾
	temp1[n1] = 0x7fffffff;
	temp2[n2] = 0x7fffffff; 
	
	// 使用分治合并两个数组
	int k1=0,k2=0;
	for(int i=l; i<=r; ++i){
		arr[i] = temp1[k1] <= temp2[k2] ? temp1[k1++] : temp2[k2++];
	} 
	
} 
