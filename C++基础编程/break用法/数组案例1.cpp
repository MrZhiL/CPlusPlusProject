#include <iostream>

using namespace std;

int main(){
	
	// ����1-��ֻС�������
	// ������������һ�������м�¼��ֻС������أ��磺arr[5]={300,350,200,400,250};
	// �ҳ�����ӡ���ص�С������
	
	int arr[5] =  {300,350,200,400,250};
	int max,i;
	
	max = 0; 
	
	for (i=0;i<5;i++){
		if (max < arr[i]){
			max = arr[i];
		}
	}
	
	cout << "���ص�С������Ϊ: " << max << endl; 
	
	cout << "*****************************" << endl; 
	// ����2-������Ԫ������
	
	int arr2[] = {1,2,3,4,5,6,7,8,9};
	int j,start,end,size_arr2,temp;
	
	// ����������Ԫ�صĸ��� 
	size_arr2 = sizeof(arr2)/sizeof(arr2[0]);
	cout << "�����СΪ��" << size_arr2 << endl; 
	
	// ��ʼ����λ�� 
	start = 0;
	
	// ĩβ����λ�� 
	end = size_arr2 - 1;
	
	cout << "ԭ��������Ϊ��" << endl; 
	for (j=0;j<size_arr2;j++){
		
		// ���ԭ��������
		cout << arr2[j] << "  "; 
	}
	cout <<endl;
	
	// ������������� ,temp����������ʱ���� 
	while (start<end){
		
		temp = arr2[start];
		arr2[start] = arr2[end];
		arr2[end] = temp;
		start++;
		end--;
	}
	
	cout << "����������Ϊ��" << endl; 
	for(j=0;j<size_arr2;j++){
		
		cout << arr2[j] << "  " ;
	}
	cout << endl; 
	
	
	system("pause");
	
	return 0;
}
