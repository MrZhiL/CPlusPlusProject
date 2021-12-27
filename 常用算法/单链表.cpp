#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <iostream>

using namespace std;

struct ListNode {
	int val;					// ������ 
	struct ListNode* next;		// ָ���� 
};


// ��ʼ�������� 
struct ListNode* CreatListNode() {
	struct ListNode* ListCreat = (struct ListNode*)malloc(sizeof(struct ListNode));
	ListCreat->val = 0;
	ListCreat->next = NULL;
	return ListCreat;
}
struct ListNode* CreatListList(int val) {
	struct ListNode* ListCreat = (struct ListNode*)malloc(sizeof(struct ListNode));
	ListCreat->val = val;
	ListCreat->next = NULL;
	return ListCreat;
}

// ����ͷ�巨��valΪ��������� 
void ListNodeInsertTop(struct ListNode* head,int val){
	struct ListNode* temp = CreatListList(val);
	temp->next = head->next;
	head->next = temp;
}
// ɾ�������е�ָ��λ�õ�Ԫ�أ�posΪָ����λ�� 
void deleteListNode(struct ListNode* list, int pos){
	struct ListNode* posNode = list->next;
	struct ListNode* posNodeFront = list;
	if(posNode==NULL){
		printf("����Ϊ�գ��޷�����ɾ��!\n");
		return;
	}
	for(int i = 0; i<pos-1; ++i){
		posNodeFront = posNode;
		posNode = posNode->next;
		if(posNode == NULL){
			printf("������С��pos���޷�����ɾ��!\n");
			return;
		}
	}
	posNodeFront->next = posNode->next; 
	free(posNode);
} 

void printListNode(struct ListNode* lst){
	struct ListNode* temp = lst->next;
	while(temp){
		printf("%d ",temp->val);
		temp = temp->next;
	}
	
	printf("\n");
}

int main() {

//	struct ListNode* lst1 = CreatListNode();
//	lst1->val = 0;
//	lst1->next = NULL;
//	struct ListNode* lst2 = CreatListNode();
//	lst2->val = 1;
//	lst2->next = NULL;
//	struct ListNode* lst3 = CreatListNode();
//	lst3->val = 2;
//	lst3->next = NULL;
//	struct ListNode lst4 = { 3,NULL };
//	lst1->next = lst2;
//	lst2->next = lst3;
//	lst3->next = &lst4;
//	//printf("%d\n", lst4.val);
//	printListNode(lst1);
//	printListNode(lst2);
//	printListNode(lst3);
	int a = getchar();
	cout << a << endl;
	int b = 'a';
	cout << b << endl;
//	cout << typeid(a) << endl;
	struct ListNode* lst5 = CreatListNode();
	ListNodeInsertTop(lst5,1);
	ListNodeInsertTop(lst5,2);
	ListNodeInsertTop(lst5,3);
	ListNodeInsertTop(lst5,4);
	printf("lst5: ");
	printListNode(lst5);
	
	struct ListNode* lst6 = lst5;
	printf("lst6: ");
	printListNode(lst5);
	
	printf("lst6ɾ����3��λ�õ�Ԫ�غ�");
	deleteListNode(lst6,3);
	printListNode(lst6);
	
	printf("lst5: ");
	printListNode(lst5);
	
	printf("lst5ɾ����3��λ�õ�Ԫ�غ�");
	deleteListNode(lst5,3);
	printListNode(lst5);
	
	printf("lst6��");
	printListNode(lst6);
	
	return 0;
}
