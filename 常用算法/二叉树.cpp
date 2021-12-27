#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <iostream>

using namespace std;

typedef struct TreeNode{
	/*二叉树节点的数据*/	
	int data;
	
	/*左右子节点指针*/ 
	TreeNode *lchile,*rchile;
}TreeNode, *BiTree;

/*创建二叉树*/
TreeNode* CreateBiTree(){
	TreeNode* T;
	T = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
	T->data = 0;
	T->lchile = NULL;
	T->rchile = NULL;
	return T;
};

TreeNode* CreateBiTree(int num){
	TreeNode* T;
	T = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
	T->data = num;
	T->lchile = NULL;
	T->rchile = NULL;
	return T;
};


TreeNode* CreateBiTree(TreeNode& rot){
	TreeNode* T;
	T = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
	T->data = rot.data;
	T->lchile = rot.lchile;
	T->rchile = rot.rchile;
	return T;
};

int main(){
	TreeNode *l  = CreateBiTree(2);
	TreeNode *r  = CreateBiTree(3);
	TreeNode *p  = CreateBiTree();
	
	p->data = 1;
	p->lchile = l;
	p->rchile = r; 
	
	cout << p->data << endl; 
	cout << p->lchile->data << endl; 
	cout << p->rchile->data << endl; 
} 
