#include <iostream>

using namespace std;
 
int main() {
	
	// break的使用时机
	
	// 1、出现在switch语句中
	
//	int select; // 创建选择结果的变量
//	select = 0;
//	
//	cout << "请选择将要进行的动作" << endl;
//	cout << "1、Sleep" << endl;
//	cout << "2、Study" << endl;
//	cout << "3、Exercise" << endl; 
//	
//	cin >> select;
//	
//	switch(select){
//		
//		case 1: 
//			cout << "您选择的动作是Sleep" << endl;   
//			break; // 推出switch语句，如果不写break则会执行下面所有语句 
//		case 2:
//			 cout << "您选择的动作是Study" << endl;
//			 break;
//		case 3:
//			cout << "您选择的动作是Exercise" << endl;
//			break;
//		default: 
//		
//		break;
//	}
//	
//	 
	// 2、出现在循环语句中
//	
//	for(int i=0;i<10;i++){
//		
//		if(i>5){
//			break;
//		}
//		
//		cout << i << endl;
//	}

	
//	// 3、出现在嵌套循环语句中
//	
//	for(int i=0;i<10;i++){
//		
//		for(int j=0; j<10; j++){
//			if(j>5)	break;
//			cout << "* " ;
//		}
//
//		cout << endl;
//	}

	// 4、continue用法
	int i;
	
	for (i=1; i<=10; i++){
		if(i%2 == 0){
			continue;
		}
		cout << i << endl;
	} 
	
	system("pause");
	return 0; 
}
