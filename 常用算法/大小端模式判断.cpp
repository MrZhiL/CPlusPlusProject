#include <iostream>
#include <string>

using namespace std; 

int IsBigEndian()  
{  
    int a = 0x1234;  
    char b =  *(char *)&a;  //ͨ����intǿ������ת����char���ֽڣ�ͨ���ж���ʼ�洢λ�á������� ȡb����a�ĵ͵�ַ����  
    if( b == 0x12)  		// �����жϳ�ΪС��ģʽ 
    {  
        return 1;  
    }  
    cout << b << endl;
    return 0;  
}

int main(){
	
	int i = IsBigEndian();
	cout << i << endl; 
	return 0;
}

