#include <iostream>
#include <vector>
/**
链接：https://www.nowcoder.com/questionTerminal/f9533a71aada4f35867008be22be5b6e?answerType=1&f=discussion
来源：牛客网

有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。

输入描述:

每组数据为一行一个整数n(小于等于1000)，为数组成员数,如果大于1000，则对a[999]进行计算。


输出描述:

一行输出最后一个被删掉的数的原始下标位置。
*/ 
#include <algorithm>

using namespace std;
const int m = 3;
int main(){
    int n = 249;
//    while(cin >> n){
//        if(n == 1) return 0;
//        if(n == 2) return 1;
//        
//        if(n>1000) n = 1000;
//        vector<int> ret(n);
//        for(int i=0;i<n;i++){
//            ret[i] = i;
//        }
//        
//        int last_num = -1;
//        int k = 1;
//        while(ret.size() > 1){
//        	for(vector<int>::iterator it = ret.begin(); it!=ret.end(); ){
//        		if(k%3 == 0) ret.erase(it);
//        		else ++it;
//        		k++;
//			}
//           cout << endl;
//           cout << "ret的大小为:" << ret.size() << endl;
//        }
//        cout << ret[0] << endl;
//    }
	// 使用递归求解 f(n) = [f(n-1)+m]%n;
	int val = 0,s = 0;
	for(int i = 1; i<=n; ++i){
		s = (s+m)%i;
	} 
	cout << s << endl;
    
    return 0;
}
