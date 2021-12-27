#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main(){
	
	// 冒泡排序
	
	int arr[10],temp,i,j,min;
	
	// 用rand产生一个伪随机数 ,srand()是产生时钟，从而使随机数不同 
	srand(time(NULL));
	
	cout << "产生的原序列为：  " ; 
	for (i=0;i<10;i++){
		arr[i] = rand()%100;
		
		// 随机产生一个0-99内的数组,并输出原序列 
		cout << arr[i] << "  ";
	} 
	cout << endl;	
	
	// 将arr[0]赋值给min 
	min = arr[0];
	
	// 使用冒泡排序法进行从小到大的排序
	cout << "冒泡排序后的序列：";
	for (i=0;i<10;i++){
		for (j=i;j<10;j++){
			
			if(arr[i] > arr[j]){
				// 将最小值 
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			} 
		} 
		cout << arr[i] << "  " ;
	} 
	
	cout << endl;
	
	system("pause");
	return 0; 
} 
