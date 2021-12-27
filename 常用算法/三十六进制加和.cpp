#include <string>
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;


class Solution{
public:
	char getChar(int n){
		if(n <= 9) return n+'0';
		else return n-10+'a';
	}
	
	int getInt(char ch){
		if('0' <= ch && ch <= '9') return ch - '0';
		else return ch - 'a' + 10;
	}
	
	string add36Strings(string num1, string num2){
		int carry = 0;
		int i = num1.size()-1, j = num2.size()-1;
		string res;
		while(i>=0 || j>=0 || carry){
			int x = i >= 0 ? getInt(num1[i]) : 0;
			int y = j >= 0 ? getInt(num2[j]) : 0;
			int sum = x + y + carry;
			res += getChar(sum%36);
			carry = sum/36;
			i--,j--;
		}
		reverse(res.begin(),res.end());
		return res;  
	}
};

int main ()
{
	Solution s;
	string a = "a", b = "x", c;
	c = s.add36Strings(a,b);
	cout << c << endl;
	
	vector<int> aa;
	aa.push_back(1); 
	aa.push_back(2); 
	aa.push_back(3); 
	aa.push_back(4); 
	cout << aa[aa.size()-1]<< endl;
}


//// 使用并查集找省份 
//class Solution {
//public:
//    int Find(vector<int>& parent, int index) {
//        if (parent[index] != index) {
//            parent[index] = Find(parent, parent[index]);
//        }
//        return parent[index];
//    }
//
//    void Union(vector<int>& parent, int index1, int index2) {
//        parent[Find(parent, index1)] = Find(parent, index2);
//    }
//
//    int findCircleNum(vector<vector<int> >& isConnected) {
//        int provinces = isConnected.size();
//        vector<int> parent(provinces);
//        for (int i = 0; i < provinces; i++) {
//            parent[i] = i;
//        }
//        for (int i = 0; i < provinces; i++) {
//            for (int j = i + 1; j < provinces; j++) {
//                if (isConnected[i][j] == 1) {
//                    Union(parent, i, j);
//                }
//            }
//        }
//        int circles = 0;
//        for (int i = 0; i < provinces; i++) {
//            if (parent[i] == i) {
//                circles++;
//            }
//        }
//        return circles;
//    }
//}; 
//
//void print2Vec(vector<vector<int> >& vec){
//	int n = vec.size();
//	int m = vec[0].size();
//	for(int i = 0;i < n; i++){
//		for(int j=0;j<n;j++){
//			cout << vec[i][j] << " ";
//		}
//		cout << endl;
//	}
//} 
//
//int main(){
//	int a[15][15] = {{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,1,0,1,0,0,0,0,0,0,0,0,0,1,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,1,0,1,0,0,0,1,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
//	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
//	{0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},{0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};
//	for(int i = 0;i < 15; i++){
//		for(int j=0;j<15;j++){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	vector<vector<int> > vec;
//	vec.push_back(vector<int>());
//	vec[0].push_back(1);
//	vec[0].push_back(1);
//	vec[0].push_back(0);
//	vec.push_back(vector<int>());
//	vec[1].push_back(1);
//	vec[1].push_back(1);
//	vec[1].push_back(0);
//	vec.push_back(vector<int>());
//	vec[2].push_back(0);
//	vec[2].push_back(0);
//	vec[2].push_back(1);
//	print2Vec(vec);
//	Solution S;
//	int num = S.findCircleNum(vec);
//	cout << num << endl;
//} 

