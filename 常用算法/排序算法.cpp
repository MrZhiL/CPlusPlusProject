// �����㷨
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
	cout << "ԭ����\t\t";
	printArr(a);
	// ����С�����˳�� 
	cout << "���������㷨�� "; 
	QuickSort(a,0,10);
	printArr(a);
	cout << "ð�������㷨�� "; 
	BubbleSort(a,10);
	printArr(a);
	cout << "ѡ�������㷨�� ";
	SelectSort(a,10);
	printArr(a);
	
} 

// ���������㷨 ��˳�� 
void QuickSort(int* arr,int left, int right){
	if(left >= right) return;
	// ʹ�����������ֱ�ָ������ĵ�һ��Ԫ�غ����һ��Ԫ��
	// ʹarr[0]Ϊ�м�ֵ���м��㣬���arr[0]���ұ�Ԫ�ؾ�����������ߵ�Ԫ�ؾ�С���� 
	int num = arr[left],i = left, j = right;
	while(i < j){
		// �ȴ�������Ѱ�ҵ�һ��С��arr[num]��ֵ 
		while(arr[j] >= num && j > left){
			--j;
		}
		if(i<j) arr[i++] = arr[j];  // ���rightָ���Ԫ��С��arr[num],��arr[right]Ԫ����䵽arr[left]�� 
		
		// ��ʱ��������Ѱ�ҵ�һ������arr[num]��ֵ,Ȼ������䵽arr[right]��
		while(arr[i] <= num && i < j){
			i++;
		}
		if(i<j) arr[j--] = arr[i];
	}
	arr[i] = num;
	// Ȼ���[0,left]��[right,n-1]�������ÿ��������㷨���м��㣨�ݹ���ã� 
	QuickSort(arr,left,i-1);
	QuickSort(arr,j+1,right);
} 

// ð�������㷨 (����)
void BubbleSort(int* arr, int n){
	// ���ν���С��ֵ�ŵ���� 
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

// ѡ�������㷨��˳�� 
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
