#include <iostream>

using namespace std;

void Bubble_Sort1(int *, int len);
void Selectt_Sort1(int *, int len);

int main(){
	
	// 案例描述：封装一个函数，利用冒泡排序，实现对整个整型数组的升序排序
	// 例如数组：int arr[10] = {9,4,3,6,0,2,5,8,7,1}; 
	
	int arr[10] = {9,4,3,6,10,2,5,8,7,1};	//创建数组
	int i,len,*p = arr;	//创建指针，并指向数组 
	
	len = sizeof(arr)/sizeof(arr[0]);
	cout << "排序前：" << endl;
	for (i=0;i<len;i++){
		cout << *(p+i) << "  ";
	}
	cout << endl;
	
	// 使用冒泡排序子函数进行升序排序（使用地址传递，改变实参） 
	Bubble_Sort1(p,len);

	cout << "冒泡排序进行升序后：" << endl;
	for (i=0;i<len;i++){
		cout << *p << "  ";
		p++;
	}
	cout << endl;
	
	// 使用选择排序子函数进行降序排序（使用地址传递，改变实参） 
	Selectt_Sort1(arr,len); 
	cout << "选择排序降序后：" << endl;
	for (i=0;i<len;i++){
		cout << arr[i] << "  ";
	}
	cout << endl;
	
	system("pause");
	return 0;
} 

// Bubble_Sort子函数，对数组进行升序排序 
void Bubble_Sort1(int *p,int len){
	
	int i,j,max;
	
	// 冒泡排序 
	for (i=0;i<len-1;i++){
		
		for (j=0;j<len-i-1;j++){
			
			max = *(p+j);
			
			if (max > *(p+j+1)){
				
				// 依次两两进行交换 
				max = *(p+j+1);
				*(p+j+1) = *(p+j);
				*(p+j) = max; 
				
			}
		}
	} 
}


// 选择排序 
void Selectt_Sort1(int *arr, int len){
	
	int i,j,max,temp;
	
	for(i=0;i<len-1;i++){
		max = i;
		for(j=i+1;j<len;j++){
			
			// 找出数组中最大值的序号，然后进行排序 
			if(arr[max]<arr[j]){
				 max = j;
			}
			
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}
 
