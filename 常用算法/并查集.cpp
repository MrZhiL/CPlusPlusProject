#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
private:
	/* Ѱ��ÿһ���ڵ�ĸ��ڵ㺯��*/
	int find_root(vector<int>& parent, int x){
		int x_root = x;
		/*���ÿ���ڵ�ָ����������Ϊ���ڵ㣻����Լ�ָ����һ���ڵ㣬�򸸽ڵ�Ϊ�����ڵ㣬���ε������ҵ���ߵĸ��ڵ�*/ 
		while(parent[x_root] != x_root){
			x_root = parent[x_root];
		}
		/* �ҵ����ڵ�󣬷��ظ��ڵ�ı��*/ 
		return x_root;
	}
	
	/* ���Ϻ�������������ڵ�x��y�ĸ��ڵ㲻��ͬ������Խ��������ڵ�����������������ڵ���ͬ����˵������������һ����ͨ���У�����ı�*/
	/* �����0-��ʾ�����ڵ㴦��һ����ͨ���У�����������ϣ�1-�����ڵ㴦�ڲ�ͬ����ͨ���У��������ڵ��������*/ 
	int union_join(vector<int>& parent, int x, int y,vector<int>& rank){
		/* ���ҵ�x y�ڵ�ĸ��ڵ㣬Ȼ���ж������ڵ��Ƿ���һ����ͨ����*/ 
		int x_root = find_root(parent,x);
		int y_root = find_root(parent,y);
		cout << x_root << " " << y_root << endl;
		/* ��������ڵ㲻��һ����ͨ���У���������ϣ����Ϸ������⣨���ǿ��ܴ���һ���·�����⣬���������*/ 
		if(x_root != y_root){
			if(rank[x_root] > rank[y_root]){
				parent[y_root] = x_root;
			}else{
				parent[x_root] = y_root;
			}
			return 1;
		}else{
			return 0;
		}
	}
	
public:
	// Ѱ����ͨ���� 
	int findCircleNum(vector<vector<int> >& vec){
		int n = vec.size();
		cout << n << endl; 
		/* �������ڵ�Ŀ¼����ʱ���нڵ�ĸ��ڵ㶼Ϊ�Լ���ָ��-1*/
		vector<int> parent(6);
		/* rank��ʾÿ���ڵ�ĸ߶ȣ�Ϊ��ʹ·����̣�Ӧ�ý����ڵ��ʾΪrank����Ԫ��*/
		vector<int> rank(6);
		// ��ʱ��Ҫ��ÿ���ڵ�ָ�򸸽ڵ㣨-1����n��ʾ�ڵ������ 
		for(int i=0;i<6;i++){
			parent[i] = i;
			rank[i] = 0; 
			cout << parent[i] << " ";
		}
		cout << endl;
		for(int i=0;i<n;i++){
			if ( union_join(parent,vec[i][0],vec[i][1], rank) == 0 ) return 1;
		}
		return 0;
	}
	
};

int main(){
	vector<vector<int> > parent;
	parent.push_back(vector<int>());
	parent[0].push_back(0); 
	parent[0].push_back(1); 
	parent.push_back(vector<int>());
	parent[1].push_back(1); 
	parent[1].push_back(2); 
	parent.push_back(vector<int>());
	parent[2].push_back(1); 
	parent[2].push_back(3); 
	parent.push_back(vector<int>());
	parent[3].push_back(2); 
	parent[3].push_back(5); 
	parent.push_back(vector<int>());
	parent[4].push_back(3); 
	parent[4].push_back(4); 
	parent.push_back(vector<int>());
	parent[5].push_back(4); 
	parent[5].push_back(5); 
	
	Solution S;
	int x = S.findCircleNum(parent);
	if(x) cout << "Circle detected!" << endl;
	else cout << "Circle not detected!" << endl;
} 
