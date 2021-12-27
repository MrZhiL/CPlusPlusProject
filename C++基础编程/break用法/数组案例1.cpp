#include <iostream>

using namespace std;

int main(){
	
	// 案例1-五只小猪撑体重
	// 案例描述：在一个数组中记录五只小猪的体重，如：arr[5]={300,350,200,400,250};
	// 找出并打印最重的小猪体重
	
	int arr[5] =  {300,350,200,400,250};
	int max,i;
	
	max = 0; 
	
	for (i=0;i<5;i++){
		if (max < arr[i]){
			max = arr[i];
		}
	}
	
	cout << "最重的小猪体重为: " << max << endl; 
	
	cout << "*****************************" << endl; 
	// 案例2-将数组元素逆置
	
	int arr2[] = {1,2,3,4,5,6,7,8,9};
	int j,start,end,size_arr2,temp;
	
	// 计算数组中元素的个数 
	size_arr2 = sizeof(arr2)/sizeof(arr2[0]);
	cout << "数组大小为：" << size_arr2 << endl; 
	
	// 起始数组位置 
	start = 0;
	
	// 末尾数组位置 
	end = size_arr2 - 1;
	
	cout << "原数组序列为：" << endl; 
	for (j=0;j<size_arr2;j++){
		
		// 输出原数组序列
		cout << arr2[j] << "  "; 
	}
	cout <<endl;
	
	// 将数组进行逆置 ,temp用来保存临时变量 
	while (start<end){
		
		temp = arr2[start];
		arr2[start] = arr2[end];
		arr2[end] = temp;
		start++;
		end--;
	}
	
	cout << "新数组序列为：" << endl; 
	for(j=0;j<size_arr2;j++){
		
		cout << arr2[j] << "  " ;
	}
	cout << endl; 
	
	
	system("pause");
	
	return 0;
}
