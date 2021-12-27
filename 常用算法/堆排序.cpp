#include <stdio.h>

inline void swap(int tree[], int i, int j) {
	int k = tree[i];
	tree[i] = tree[j];
	tree[j] = k;
}

inline void print(int tree[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", tree[i]);
	}
	printf("\n");
}

void hepify(int tree[], int n, int i) {
	if (i >= n) return;
	
	int c1 = 2*i + 1;
	int c2 = 2*i + 2;
	int max = i;
	
	if (c1 < n && tree[c1] > tree[max]) {
		max = c1;
	}
	if (c2 < n && tree[c2] > tree[max]) {
		max = c2;
	}
	
	if (max != i) {
		swap(tree, max, i);
		hepify(tree, n, max);
	}
}

void build_heap(int tree[], int n) {
	int i = (n - 1) / 2;

	for (i; i >= 0; --i) {
		hepify(tree, n, i);
	}
	print(tree, n);
}

/* 从小到大进行排序 */ 
void heapSort(int tree[], int n) {
	
	build_heap(tree, n);
	
	int i = n - 1;
	for (i; i >= 0; --i) {
		swap(tree, 0, i); 
		hepify(tree, i, 0);
	}
}

int main() {
	int tree[] = {5, 2, 3, 8, 6, 7};
	int n = sizeof(tree) / sizeof(tree[0]);
	
	heapSort(tree, n);
	print(tree, n);
	
	return 0;
} 
