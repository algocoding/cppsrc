/*
 * mergeSort_list.cpp
 * 	병합 정렬
 *
 */
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}NODE;
void printList(NODE* head){
	NODE* curr = head;

	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
}

void insertFirstNode(NODE** head, NODE* node)
{
	if (*head == NULL) //빈공백
	{
		*head = node;
	}
	else{
		node->next = *head;
		*head = node;
	}
}
void insertLastNode(NODE** head, NODE* node)
{
	NODE* curr = *head;
	if (*head == NULL) //빈공백
	{
		*head = node;
	}
	else{
		while (curr->next != NULL)
			curr = curr->next;

		curr->next = node;
	}
}
NODE* makeList(int arr[], int count) {
	NODE *head = NULL;
	NODE *temp = NULL;

	for (int i = count - 1; i >= 0; i--){
		temp = new NODE;
		temp->data = arr[i];
		temp->next = NULL;
		insertFirstNode(&head, temp);
	}
	return head;
}

NODE* mergesort(NODE* head);
NODE* merge(NODE* left, NODE* right);

int main(void) {
	struct node *head = NULL;
	struct node *curr = NULL;
	struct node *del = NULL;
	int data[] = { 82, 13, 22, 61, 12, 52, 41, 75, 98 };
	//int data[] = { 1, 0, 1, 0, 1, 1, 1, 0, 0, 0 };
	//int data[] = { 23, 45, 2, 5, 88, 12, 7, 49, 45, 16 };

	head = makeList(data, sizeof(data) / sizeof(data[0]));

	printList(head); printf("\n");

	head = mergesort(head);

	printList(head); printf("\n");

	curr = head;
	while (curr != NULL){
		del = curr;
		curr = curr->next;
		free(del);
	}
	return 0;
}

int listLength(NODE* head){
	int length = 0;
	NODE* curr = head;

	while (curr != NULL){
		curr = curr->next; length++;
	}
	return length;
}
NODE* mergesort(NODE* head) {
	NODE* left = NULL;
	NODE* right = NULL;
	NODE* curr = head;

	// 사이즈가 0이거나 1인 경우 바로 리턴
	if ((head == NULL) || (head->next == NULL))
		return head;

	// 리스트 분할하기
	int mid = listLength(head) / 2;
	for (int i = 0; i < mid - 1; i++)
		curr = curr->next;
	left = head;
	right = curr->next;
	curr->next = NULL;

	return merge(mergesort(left), mergesort(right));
}
NODE* merge(NODE* left, NODE* right) {
	NODE* result = NULL;
	NODE* temp = NULL;
	while (left != NULL || right != NULL){
		if (left != NULL && right != NULL){
			if (left->data < right->data)
			{
				temp = left;
				left = left->next;
				temp->next = NULL;
				insertLastNode(&result, temp);
			}
			else{
				temp = right;
				right = right->next;
				temp->next = NULL;
				insertLastNode(&result, temp);
			}
		}
		else if (left != NULL){
			temp = left;
			left = left->next;
			temp->next = NULL;
			insertLastNode(&result, temp);
		}
		else if (right != NULL){
			temp = right;
			right = right->next;
			temp->next = NULL;
			insertLastNode(&result, temp);
		}
	}

	return result;
}
