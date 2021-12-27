#include <iostream>
#include <vector>

using namespace std;

// ���κϲ�
void merge(int arr[], int l, int m, int r);

// �鲢���򣨣� 
void merge_Sort(int arr[], int l, int r);

// ��������
void QuickSort(int arr[], int l, int r);

// ��������
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
	
	cout << "����ǰ��"; 
	print_arr(arr,n);
	
	cout << "�����˳�򣩣�";
	merge_Sort(arr,0,n-1);
	print_arr(arr,n);
	
	cout << "������������򣩣�";
	QuickSort(arr,0,n-1);
	print_arr(arr,n);
	
	cout << "��������(˳��): ";
	InsertSort(arr,n-1);
	print_arr(arr,n); 
}

// �鲢���򣨴�С�������� 
void merge_Sort(int arr[], int l, int r){
	// ���l>=r,˵����ʱ������ֻ��һ��Ԫ�أ��Ѿ��ź����������ٴ����� 
	if(l < r){
		int mid = (l+r)/2;
		merge_Sort(arr,l,mid);
		merge_Sort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

// �������� (��С��������)
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


// �������򣨴Ӵ�С���� 
void QuickSort(int arr[], int l, int r){
	if(l < r){
		int key = arr[l];	// ���һ��Ԫ��Ϊ��׼ 
		int left = l, right = r;
		// �ȴ�����ǰ�ҵ�һ������arr[key]��Ԫ�� 
		while(left < right){
			while(left < right && arr[right] <= key) --right;
			 
			if(left < right) arr[left++] = arr[right];
			
			while(left < right && arr[left] >= key) ++left;
			
			if(left < right) arr[right--] = arr[left];
			
		} 
		// ����׼������ 
		arr[left] = key; 
		
		// ִ�з��β������ݹ����
		QuickSort(arr,l,left-1);
		QuickSort(arr,left+1,r);
	}
	
} 

// ���κϲ�
void merge(int arr[], int l, int m, int r){
	int n1 = m-l+1,n2 = r-m;
	// ����������ʱ���飬�����洢arr[l,m]��arr[m+1,r]�е�Ԫ�� 
	int temp1[n1+1],temp2[n2+1];
	for(int i=0; i<n1; ++i){
		temp1[i] = arr[i+l];
	}
	for(int i=0;i<n2;++i){
		temp2[i] = arr[i+m+1];
	}
	// temp1��temp2��������һ��Ԫ�ش���ڱ�λ������ÿ���ж��Ƿ񵽴�����ĩβ
	temp1[n1] = 0x7fffffff;
	temp2[n2] = 0x7fffffff; 
	
	// ʹ�÷��κϲ���������
	int k1=0,k2=0;
	for(int i=l; i<=r; ++i){
		arr[i] = temp1[k1] <= temp2[k2] ? temp1[k1++] : temp2[k2++];
	} 
	
} 
