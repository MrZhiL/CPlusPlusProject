#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main(){
	
	// ð������
	
	int arr[10],temp,i,j,min;
	
	// ��rand����һ��α����� ,srand()�ǲ���ʱ�ӣ��Ӷ�ʹ�������ͬ 
	srand(time(NULL));
	
	cout << "������ԭ����Ϊ��  " ; 
	for (i=0;i<10;i++){
		arr[i] = rand()%100;
		
		// �������һ��0-99�ڵ�����,�����ԭ���� 
		cout << arr[i] << "  ";
	} 
	cout << endl;	
	
	// ��arr[0]��ֵ��min 
	min = arr[0];
	
	// ʹ��ð�����򷨽��д�С���������
	cout << "ð�����������У�";
	for (i=0;i<10;i++){
		for (j=i;j<10;j++){
			
			if(arr[i] > arr[j]){
				// ����Сֵ 
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
