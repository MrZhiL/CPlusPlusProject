#include <iostream>
#include <vector>
/**
���ӣ�https://www.nowcoder.com/questionTerminal/f9533a71aada4f35867008be22be5b6e?answerType=1&f=discussion
��Դ��ţ����

��һ������a[N]˳����0~N-1��Ҫ��ÿ��������ɾ��һ��������ĩβʱѭ������ͷ�������У������һ����ɾ��������ԭʼ�±�λ�á���8����(N=7)Ϊ��:��0��1��2��3��4��5��6��7����0->1->2(ɾ��)->3->4->5(ɾ��)->6->7->0(ɾ��),���ѭ��ֱ�����һ������ɾ����

��������:

ÿ������Ϊһ��һ������n(С�ڵ���1000)��Ϊ�����Ա��,�������1000�����a[999]���м��㡣


�������:

һ��������һ����ɾ��������ԭʼ�±�λ�á�
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
//           cout << "ret�Ĵ�СΪ:" << ret.size() << endl;
//        }
//        cout << ret[0] << endl;
//    }
	// ʹ�õݹ���� f(n) = [f(n-1)+m]%n;
	int val = 0,s = 0;
	for(int i = 1; i<=n; ++i){
		s = (s+m)%i;
	} 
	cout << s << endl;
    
    return 0;
}
