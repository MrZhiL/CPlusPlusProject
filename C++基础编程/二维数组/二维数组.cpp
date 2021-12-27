#include <iostream>

using namespace std;

int main(){
	
	// 查看二维数组所占内存空间
	// 获取二维数组首地址 
	
	int a[][3]={1,2,3,4,5,6,7,8,9,10,11,12};
	
	// 打印二维数组
	
	cout << "二维数组：" << endl;
	for(int i=0;i<4;i++){
		for (int j=0;j<3;j++){
			cout << a[i][j] << "  ";
		}
		
		cout << endl;
	} 
	
	cout << "二维数组的大小为：" << sizeof(a) << endl;
	cout << "二维数组的首地址为：" << a[0] << endl; 
	cout << "二维数组的一行元素大小为：" << sizeof(a[0]) << endl; 
	cout << "二维数组的一个元素大小为：" << sizeof(a[0][0]) << endl; 
	cout << "二维数组的第二行地址为：" << a[1] << endl; 
	
	cout << endl;
	
	cout << "二维数组的行数为：" << sizeof(a)/sizeof(a[0]) << endl;
	cout << "二维数组的列数为：" << sizeof(a[0])/sizeof(a[0][0]) << endl; 
	
	cout << "末元素地址为：" << &a[3][2] << endl; 
	cout << "末元素地址为：" << a[3]+2 << endl;
	
	system("pause");
	return 0;
} 
