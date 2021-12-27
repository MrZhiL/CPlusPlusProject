#include <iostream>

using namespace std;

// ʵ��ͨ�� �������������ĺ���
// �滮���Ӵ�С
// �㷨��ѡ������
// ���ԣ�char���飬int���� 

// ������������ģ�� 
template<typename T>
void MySwap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
} 

// ��������ģ��-ѡ�������㷨
template<typename T>
void MySortFunc(T *arr, int len){
	
	// ѡ�������㷨���Ӵ�С�������� 
	for(int i=0; i<len-1; i++){
		
		int min = i; // �϶����ֵ���±� 
		
		for(int j=i+1; j<len; j++){
			// ����϶������ֵС�ڱ���������ֵ�����¼�����е����ֵλ�� 
			if (arr[min] < arr[j]){
				min = j; // �������ֵ�±� 
			}
		}
		
		if(min != i){
			// ʹ��ģ�庯���������ݽ���
			MySwap<T>(arr[min],arr[i]); 
			
		}
	}
} 

// ������ӡ���ģ��
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
	
	//1��ʹ��ģ������������������ 
	cout << "����ǰ��" ; 
	MyDisplay(arr,sizeof(arr)/sizeof(arr[0]));
	
	MySortFunc<int>(arr, sizeof(arr)/sizeof(arr[0]));
	
	cout << "�����" ; 
	MyDisplay(arr,sizeof(arr)/sizeof(arr[0]));
	
	//2��ʹ��ģ���char����������� 
	cout << "����ǰ��" ; 
	MyDisplay(arrc2,sizeof(arrc2)/sizeof(arrc2[0]));
	
	MySortFunc<char>(arrc2, sizeof(arrc2)/sizeof(arrc2[0]));
	
	cout << "�����" ; 
	MyDisplay(arrc2,sizeof(arrc2)/sizeof(arrc2[0]));
	
}

int main(){
	
	test01(); 
	
	system("pause");
	return 0;
} 
