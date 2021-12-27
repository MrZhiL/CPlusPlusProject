#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
private:
	/* 寻找每一个节点的父节点函数*/
	int find_root(vector<int>& parent, int x){
		int x_root = x;
		/*如果每个节点指向本身，则自身为父节点；如果自己指向另一个节点，则父节点为其他节点，依次迭代，找到最高的父节点*/ 
		while(parent[x_root] != x_root){
			x_root = parent[x_root];
		}
		/* 找到父节点后，返回父节点的标号*/ 
		return x_root;
	}
	
	/* 联合函数，如果两个节点x和y的父节点不相同，则可以将两个父节点联合起来；如果父节点相同，则说明两个连点在一个连通域中，无需改变*/
	/* 输出：0-表示两个节点处于一个连通域中，无需进行联合；1-两个节点处于不同的连通域中，并将父节点进行联合*/ 
	int union_join(vector<int>& parent, int x, int y,vector<int>& rank){
		/* 先找到x y节点的父节点，然后判断两个节点是否在一个连通域中*/ 
		int x_root = find_root(parent,x);
		int y_root = find_root(parent,y);
		cout << x_root << " " << y_root << endl;
		/* 如果两个节点不在一个连通域中，则进行联合，联合方向随意（但是可能存在一个最长路径问题，后面会解决）*/ 
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
	// 寻找联通区域 
	int findCircleNum(vector<vector<int> >& vec){
		int n = vec.size();
		cout << n << endl; 
		/* 创建父节点目录，此时所有节点的父节点都为自己，指向-1*/
		vector<int> parent(6);
		/* rank表示每个节点的高度，为了使路径最短，应该将父节点表示为rank最大的元素*/
		vector<int> rank(6);
		// 此时需要将每个节点指向父节点（-1），n表示节点的数量 
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
