#include <iostream>

using namespace std;

void Bubble_Sort1(int *, int len);
void Selectt_Sort1(int *, int len);

int main(){
	
	// ������������װһ������������ð������ʵ�ֶ����������������������
	// �������飺int arr[10] = {9,4,3,6,0,2,5,8,7,1}; 
	
	int arr[10] = {9,4,3,6,10,2,5,8,7,1};	//��������
	int i,len,*p = arr;	//����ָ�룬��ָ������ 
	
	len = sizeof(arr)/sizeof(arr[0]);
	cout << "����ǰ��" << endl;
	for (i=0;i<len;i++){
		cout << *(p+i) << "  ";
	}
	cout << endl;
	
	// ʹ��ð�������Ӻ���������������ʹ�õ�ַ���ݣ��ı�ʵ�Σ� 
	Bubble_Sort1(p,len);

	cout << "ð��������������" << endl;
	for (i=0;i<len;i++){
		cout << *p << "  ";
		p++;
	}
	cout << endl;
	
	// ʹ��ѡ�������Ӻ������н�������ʹ�õ�ַ���ݣ��ı�ʵ�Σ� 
	Selectt_Sort1(arr,len); 
	cout << "ѡ���������" << endl;
	for (i=0;i<len;i++){
		cout << arr[i] << "  ";
	}
	cout << endl;
	
	system("pause");
	return 0;
} 

// Bubble_Sort�Ӻ���������������������� 
void Bubble_Sort1(int *p,int len){
	
	int i,j,max;
	
	// ð������ 
	for (i=0;i<len-1;i++){
		
		for (j=0;j<len-i-1;j++){
			
			max = *(p+j);
			
			if (max > *(p+j+1)){
				
				// �����������н��� 
				max = *(p+j+1);
				*(p+j+1) = *(p+j);
				*(p+j) = max; 
				
			}
		}
	} 
}


// ѡ������ 
void Selectt_Sort1(int *arr, int len){
	
	int i,j,max,temp;
	
	for(i=0;i<len-1;i++){
		max = i;
		for(j=i+1;j<len;j++){
			
			// �ҳ����������ֵ����ţ�Ȼ��������� 
			if(arr[max]<arr[j]){
				 max = j;
			}
			
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}
 
