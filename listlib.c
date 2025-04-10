#include "listlib.h"

void addAtBeginning(ListNode** head, ListData v) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(ListNode** head, ListData v) {
    ListNode *aux = *head;
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = v;
    if (*head == NULL) 
        addAtBeginning(&*head, v);
    else {
        while (aux->next != NULL) 
            aux = aux->next;
        aux->next = newNode;
        newNode->next = NULL;
    }
}

void print(ListNode *head) {
    while (head != NULL) {
        printf("%d %d", head->val.linie, head->val.coloana);
        head = head->next;
    }
}

void push(StackNode** top, ListNode* v) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->val = v;
    newNode->next = *top;
    *top = newNode;
}

ListNode* pop(StackNode** top) {
    if (*top == NULL) 
        return NULL;
    StackNode *temp = (*top);
    ListNode* aux = temp->val;
    *top = (*top)->next;
    free(temp);
    return aux;
}

void deleteStack(StackNode** top) {
    StackNode* temp;
    while ((*top) != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}
