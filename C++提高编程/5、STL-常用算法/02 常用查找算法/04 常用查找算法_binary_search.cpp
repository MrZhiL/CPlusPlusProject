#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ���ַ����ң�bool binary_search(beg, end, value); 
// note: ֻ��������������ʹ�ã�����������������ʹ��

void test01(){
	vector<int> vec;
	
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	//vec.push_back(8);
	// ������ҵ�������Ԫ��û�й���δ���򣩣����޷���֤���ҵĽ���Ƿ�׼ȷ����ʹ�и�Ԫ�أ�Ҳ���ܲ��Ҳ��� 
	bool findVal = binary_search(vec.begin(), vec.end(), 9);
	
	if(findVal == true){
		cout << "���ҵ���Ԫ��!" << endl; 
	}else{
		cout << "δ�ҵ���Ԫ��!" << endl;
	}
	
} 
 
int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
