#include <iostream>

using namespace std;

int main(){
	
	// ��ά���鰸�������Գɼ�ͳ��
	// ����������������ͬѧ(���������ġ�����)����һ�ο����еĳɼ��ֱ����£���ֱ��������ͬѧ���ܳɼ� 
	// ���������ģ�100   ��ѧ��100   Ӣ�100
	// ���ģ����ģ�90	 ��ѧ��50	 Ӣ�100
	// ���壺���ģ�60	 ��ѧ��70	 Ӣ�80     
	
	// ����һ��3x3�����飬�����洢����ͬѧ�ĳɼ� 
	int score[3][3];
	
	cout << "Please zhangsan score: " ;
	cin >>score[0][0] >> score[0][1];
	cout << score[0][0] << "  " << score [0][1] << endl; 

	int a,b;
	a=score[0][0];
	b=score[0][1];
	
	if (a==0 || b==1){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}
	
	cout << "!a = " << !a << endl;
	cout << "a = " << a << endl;
	
	cout << "!b = " << !b << endl;
	cout << "b = " << b << endl;
	
	// &��ʾ��λ�� ��λ������� 
	cout << "a & b = " << (a&b) << endl;
	
	// &&��ʾ�߼��� 
	cout << "a && b = " << (a&&b) << endl;
	
	// |��ʾ��λ�� ��λ������� 
	cout << "a | b = " << (a|b) << endl;
	
	// || ��ʾ�߼��� 
	cout << "a || b = " << (a||b) << endl;
	
	system("pause");
	return 0; 
}	


