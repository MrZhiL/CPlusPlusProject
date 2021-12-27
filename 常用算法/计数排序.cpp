#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ¼ÆÊýÅÅÐò
void countSort(vector<int>& vec) {
	int maxEle = *max_element(vec.begin(), vec.end());
	int minEle = *min_element(vec.begin(), vec.end());
	int n = maxEle - minEle + 1;
	
	vector<int> ret(n, 0);
	
	for (auto& k : vec) {
		ret[k - minEle]++;
	}
	
	int k = 0;
	for (int i = 0; i < ret.size(); ++i) {
		if (ret[i] != 0) {
			for (int j = 0; j < ret[i]; ++j) {
				vec[k++] = i + minEle;
			}
		}
	}
} 

inline void print(const vector<int>& vec) {
	for (auto& k : vec) {
		cout << k << " ";
	}
	cout << endl;
}

int main()
{
    vector<int> vecRaw = {0, 5, 7, 9, 6, 3, 4, 5, 2, 8, 6, 9, 2, 1};
	
	cout << "before sort: ";
	print(vecRaw);
		
    countSort(vecRaw);

	cout << "after  sort: ";
    print(vecRaw);
    
    return 0;
}

