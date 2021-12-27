#include <iostream>
#include <vector>

using namespace std; 

// ���͵�ַ��https://blog.csdn.net/morewindows/article/details/6684558 

void quirtSort(int* arr, int l, int r){
    if(l < r){
    	int x = arr[l];
	    // ȷ������ռ�
	    int i = l, j = r;
        while(i<j){
        
            // ���������ҵ�С��x��ֵ
            while(i<j && arr[j] >= x) --j;
            // ��ʱ�뽫�����arr[0]�У�����arr[j]���ظ��������Ҫ���
            if(i < j) arr[i++] = arr[j];
            // ���������ҵ���һ�����ڵ���arr[j]��ֵ������䵽arr[j]��
            while(i<j && arr[i] < x) ++i;
            // ��ʱ�뽫arr[i]����arr[j]�У�����arr[i]���ظ��������Ҫ���
            if(i < j) arr[j--] = arr[i];
            // ����ִ��whileѭ����ֱ��x����ֵ��С��x���Ҳ������x
        }
        // ��ʱarr[i/j](j==i)����ֵ��Ҫ���
		arr[i] = x; 
        
        // ִ�з��β������ݹ����
        quirtSort(arr,l,i-1);
        quirtSort(arr,i+1,r);
    }
}

int main(){
	int arr[] = {1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663}; 
//	vector<int> arr;
//	arr.push_back(5);
//	arr.push_back(2);
//	arr.push_back(3);
//	arr.push_back(8);
//	arr.push_back(4);

	int n = 49;
	quirtSort(arr,0,n-1);
	
	for(int i=0;i<n;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	cout << arr[n-23-1] << endl;
	return 0;
}
