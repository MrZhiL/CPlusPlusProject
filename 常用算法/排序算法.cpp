// 排序算法
#include <iostream>
#include <vector>

using namespace std;

void QuickSort(int*, int, int);
void BubbleSort(int*, int);
void SelectSort(int*, int);
void printArr(int* arr){
	//int n = arr.size();
	for(int i=0;i<11;i++){
		cout << arr[i] << "  ";
	}
	cout << endl; 
}

int main(){
	int a[11] = {5,1,4,7,2,3,8,12,10,9,6};
	cout << "原序列\t\t";
	printArr(a);
	// 按从小到大的顺序 
	cout << "快算排序算法： "; 
	QuickSort(a,0,10);
	printArr(a);
	cout << "冒泡排序算法： "; 
	BubbleSort(a,10);
	printArr(a);
	cout << "选择排序算法： ";
	SelectSort(a,10);
	printArr(a);
	
} 

// 快速排序算法 （顺序） 
void QuickSort(int* arr,int left, int right){
	if(left >= right) return;
	// 使用两个变量分别指向数组的第一个元素和最后一个元素
	// 使arr[0]为中间值进行计算，最后arr[0]的右边元素均大于它，左边的元素均小于它 
	int num = arr[left],i = left, j = right;
	while(i < j){
		// 先从右向左寻找第一个小于arr[num]的值 
		while(arr[j] >= num && j > left){
			--j;
		}
		if(i<j) arr[i++] = arr[j];  // 如果right指向的元素小于arr[num],则将arr[right]元素填充到arr[left]处 
		
		// 此时从左向右寻找第一个大于arr[num]的值,然后将其填充到arr[right]中
		while(arr[i] <= num && i < j){
			i++;
		}
		if(i<j) arr[j--] = arr[i];
	}
	arr[i] = num;
	// 然后对[0,left]和[right,n-1]继续调用快速排序算法进行计算（递归调用） 
	QuickSort(arr,left,i-1);
	QuickSort(arr,j+1,right);
} 

// 冒泡排序算法 (逆序)
void BubbleSort(int* arr, int n){
	// 依次将最小的值放到最后 
	for(int i=0;i<=n;++i){
		for(int j = i+1; j<=n; ++j){
			if(arr[j] > arr[i]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		} 
	}
}

// 选择排序算法（顺序） 
void SelectSort(int* arr, int n){
	while(n >= 0){
		int max = 0;
		for(int i=1;i<=n;++i){
			if(arr[i] > arr[max]){
				max = i;
			}
		}
		int temp = arr[n];
		arr[n] = arr[max];
		arr[max] = temp;
		--n;
	}
	
}
