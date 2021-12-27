#include <iostream>
#include <string>

using namespace std; 

int IsBigEndian()  
{  
    int a = 0x1234;  
    char b =  *(char *)&a;  //通过将int强制类型转换成char单字节，通过判断起始存储位置。即等于 取b等于a的低地址部分  
    if( b == 0x12)  		// 可以判断出为小端模式 
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

