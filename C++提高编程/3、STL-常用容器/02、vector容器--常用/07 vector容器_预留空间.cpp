#include<iostream>
#include<vector>

using namespace std;

// vector����Ԥ���ռ䣺ͨ������ʹ�ø÷��������Դ����ٿ��ٿռ�Ĵ��� 
// ������reserve(int len); 

void test01(){
	
	vector<int> vec;
	
	vec.reserve(100000);	// ����reserve()������vecԤ��100000�Ŀռ��С�����Լ����ڴ濪�ٴ��� 
		
	int num = 0;		// ͳ��vec��ֵ�����У��ܹ��������ٴ��ڴ�ռ� 
	int *p = NULL;		// �ø�ָ��ָ�򿪱ٿռ�ĵ�ַ 
	for(int i=0; i<100000; i++){
		vec.push_back(i);
		
		// ��if����ʾ���ж�ָ��p�Ƿ�ָ��vec���ٿռ���׵�ַ����������ڣ�����pָ���׵�ַ
		// ��Ϊ���vec�д洢��Ԫ�ش�С����vec����������Ὺ��һ���µĵ�ַ������ԭ��vec��Ԫ�����¸��Ƶ��µ�vecָ��ĵ�ַ�� 
		if(p != &vec[0]){
			p = &vec[0];
			num++;
		} 
	}
	cout << "�ڶ�vec�������ݴ洢ʱ�����ٿռ�Ĵ���Ϊ��" << num << endl;	
} 

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
