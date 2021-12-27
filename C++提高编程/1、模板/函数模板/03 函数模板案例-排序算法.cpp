#include <iostream>

using namespace std;

// 实现通用 对数组进行排序的函数
// 规划：从大到小
// 算法：选择排序
// 测试：char数组，int数组 

// 创建交换函数模板 
template<typename T>
void MySwap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
} 

// 创建函数模板-选择排序算法
template<typename T>
void MySortFunc(T *arr, int len){
	
	// 选择排序算法：从大到小进行排序 
	for(int i=0; i<len-1; i++){
		
		int min = i; // 认定最大值的下标 
		
		for(int j=i+1; j<len; j++){
			// 如果认定的最大值小于遍历出的数值，则记录遍历中的最大值位置 
			if (arr[min] < arr[j]){
				min = j; // 更新最大值下标 
			}
		}
		
		if(min != i){
			// 使用模板函数进行数据交换
			MySwap<T>(arr[min],arr[i]); 
			
		}
	}
} 

// 创建打印输出模板
template<typename T>
void MyDisplay(T *arr, int len){
	
	for(int i=0; i<len; i++){
		cout << arr[i] << "  ";
	} 
	cout << endl;
} 

void test01(){
	
	int arr[10] = {0,9,4,1,6,2,7,3,8,5};
	char arrc[10] = {'a','c','z','q','b','p','o','r','v','k'};
	char arrc2[] = "abcdefghijklmnopqrsttuvwxyz";
	
	//1、使用模板对整形数组进行排序 
	cout << "排序前：" ; 
	MyDisplay(arr,sizeof(arr)/sizeof(arr[0]));
	
	MySortFunc<int>(arr, sizeof(arr)/sizeof(arr[0]));
	
	cout << "排序后：" ; 
	MyDisplay(arr,sizeof(arr)/sizeof(arr[0]));
	
	//2、使用模板对char数组进行排序 
	cout << "排序前：" ; 
	MyDisplay(arrc2,sizeof(arrc2)/sizeof(arrc2[0]));
	
	MySortFunc<char>(arrc2, sizeof(arrc2)/sizeof(arrc2[0]));
	
	cout << "排序后：" ; 
	MyDisplay(arrc2,sizeof(arrc2)/sizeof(arrc2[0]));
	
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0;
} 
