#include <iostream>

using namespace std;

int main(){
	
	// 二维数组案例：考试成绩统计
	// 案例描述：有三名同学(张三、李四、王五)，再一次考试中的成绩分别入下，请分别输出三名同学的总成绩 
	// 张三：语文：100   数学：100   英语：100
	// 李四：语文：90	 数学：50	 英语：100
	// 王五：语文：60	 数学：70	 英语：80     
	
	// 创建一个3x3的数组，用来存储三名同学的成绩 
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
	
	// &表示按位与 （位运算符） 
	cout << "a & b = " << (a&b) << endl;
	
	// &&表示逻辑与 
	cout << "a && b = " << (a&&b) << endl;
	
	// |表示按位或 （位运算符） 
	cout << "a | b = " << (a|b) << endl;
	
	// || 表示逻辑或 
	cout << "a || b = " << (a||b) << endl;
	
	system("pause");
	return 0; 
}	


