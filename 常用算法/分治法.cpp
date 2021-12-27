#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;


// 分治算法：其中a表示数组，p<=q<r分布表示数组下标 
// 此时假设a[p,q]和a[p+1,r]中都已排好序 
// 可以在数组末尾中添加哨兵，从而避免每次都有判断是否遍历到了数组的末尾 
void merge(int a[], int p, int q, int r){
	int n1 = q-p+1,n2 = r-q;
	// 创建临时数组，用来存储a和b数组中的内容 
	int temp_n1[n1+1],temp_n2[n2+1];
	memset(temp_n1,0,sizeof(temp_n1));
	memset(temp_n2,0,sizeof(temp_n2));
	for(int i=0; i<n1; ++i){
		temp_n1[i] = a[i];
	}
	for(int i=0; i<n2; ++i){
		temp_n2[i] = a[i+n1];
	}
	cout << endl;
	// 在数组最后填充无穷值，用来表示哨兵
	temp_n1[n1] = 0x7FFFFFFF;
	temp_n2[n2] = 0x7FFFFFFF;
	 
	// 此时分别用i和j指向两个数组，并依次向后移动 
	int i = 0, j = 0;
	// 使用分治法将两个临时数组中的元素放到一个中（按顺序排好） 
	for(int k=p; k<=r;k++){
		if(temp_n1[i] <= temp_n2[j]) a[k] = temp_n1[i++];
		else a[k] = temp_n2[j++];
	} 
}

int main(){
	
	int a[] = {1,3,5,6,8,10,0,2,4,7,9};
	int n = sizeof(a)/sizeof(a[0]);
	// 合并a[0,4]和a[5,9]两个子数组中的内容，并从小到大排序
	
	cout << "分治合并前：";
	for(int i=0; i<n; ++i){
		cout << a[i] << " ";
	}  
	cout << endl;
	
	
	merge(a,0,5,n-1);
	cout << "分治合并后：";
	for(int i=0; i<n; ++i){
		cout << a[i] << " ";
	} 
	
	cout << endl;
	
	return 0;
}
