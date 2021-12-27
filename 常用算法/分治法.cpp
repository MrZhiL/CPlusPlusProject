#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;


// �����㷨������a��ʾ���飬p<=q<r�ֲ���ʾ�����±� 
// ��ʱ����a[p,q]��a[p+1,r]�ж����ź��� 
// ����������ĩβ������ڱ����Ӷ�����ÿ�ζ����ж��Ƿ�������������ĩβ 
void merge(int a[], int p, int q, int r){
	int n1 = q-p+1,n2 = r-q;
	// ������ʱ���飬�����洢a��b�����е����� 
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
	// ����������������ֵ��������ʾ�ڱ�
	temp_n1[n1] = 0x7FFFFFFF;
	temp_n2[n2] = 0x7FFFFFFF;
	 
	// ��ʱ�ֱ���i��jָ���������飬����������ƶ� 
	int i = 0, j = 0;
	// ʹ�÷��η���������ʱ�����е�Ԫ�طŵ�һ���У���˳���źã� 
	for(int k=p; k<=r;k++){
		if(temp_n1[i] <= temp_n2[j]) a[k] = temp_n1[i++];
		else a[k] = temp_n2[j++];
	} 
}

int main(){
	
	int a[] = {1,3,5,6,8,10,0,2,4,7,9};
	int n = sizeof(a)/sizeof(a[0]);
	// �ϲ�a[0,4]��a[5,9]�����������е����ݣ�����С��������
	
	cout << "���κϲ�ǰ��";
	for(int i=0; i<n; ++i){
		cout << a[i] << " ";
	}  
	cout << endl;
	
	
	merge(a,0,5,n-1);
	cout << "���κϲ���";
	for(int i=0; i<n; ++i){
		cout << a[i] << " ";
	} 
	
	cout << endl;
	
	return 0;
}
