#include <iostream>

using namespace std;

int main(){
	
	// �鿴��ά������ռ�ڴ�ռ�
	// ��ȡ��ά�����׵�ַ 
	
	int a[][3]={1,2,3,4,5,6,7,8,9,10,11,12};
	
	// ��ӡ��ά����
	
	cout << "��ά���飺" << endl;
	for(int i=0;i<4;i++){
		for (int j=0;j<3;j++){
			cout << a[i][j] << "  ";
		}
		
		cout << endl;
	} 
	
	cout << "��ά����Ĵ�СΪ��" << sizeof(a) << endl;
	cout << "��ά������׵�ַΪ��" << a[0] << endl; 
	cout << "��ά�����һ��Ԫ�ش�СΪ��" << sizeof(a[0]) << endl; 
	cout << "��ά�����һ��Ԫ�ش�СΪ��" << sizeof(a[0][0]) << endl; 
	cout << "��ά����ĵڶ��е�ַΪ��" << a[1] << endl; 
	
	cout << endl;
	
	cout << "��ά���������Ϊ��" << sizeof(a)/sizeof(a[0]) << endl;
	cout << "��ά���������Ϊ��" << sizeof(a[0])/sizeof(a[0][0]) << endl; 
	
	cout << "ĩԪ�ص�ַΪ��" << &a[3][2] << endl; 
	cout << "ĩԪ�ص�ַΪ��" << a[3]+2 << endl;
	
	system("pause");
	return 0;
} 
