#include "listlib.h"

static void addAtBeginning(ListNode** head, ListData v) {
    ListNode *newNode;
    if((newNode = (ListNode*)malloc(sizeof(ListNode))) == NULL) {
        printf("Eroare alocare memorie addAtBeginning");
        exit(1);
    }
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(ListNode** head, ListData v) {
    ListNode *aux = *head;
    ListNode *newNode;
    if((newNode = (ListNode*)malloc(sizeof(ListNode))) == NULL) {
        printf("Eroare alocare memorie addAtEnd");
        exit(1);
    }
    newNode->val = v;
    if (*head == NULL) {
        addAtBeginning(head, v);
        free(newNode);
    } else {
        while (aux->next != NULL) 
            aux = aux->next;
        aux->next = newNode;
        newNode->next = NULL;
    }
}

static void fprint(FILE* fout, ListNode *head) {
    while (head != NULL) {
        fprintf(fout, " %d %d", head->val.linie, head->val.coloana);
        head = head->next;
    }
}

void push(StackNode** top, StackData v) {
    StackNode *newNode;
    if((newNode = (StackNode*)malloc(sizeof(StackNode))) == NULL) {
        printf("Eroare alocare memorie push stiva");
        exit(1);
    }
    newNode->val = v;
    newNode->next = *top;
    *top = newNode;
}

static StackData pop(StackNode** top) {
    if (*top == NULL) 
        return (StackData){-1, NULL};
    StackNode *temp = (*top);
    StackData aux = temp->val;
    *top = (*top)->next;
    free(temp);
    return aux;
}

void listfree(ListNode* head) {
    if (head == NULL)
        return;
    listfree(head->next);
    free(head);
}

void fprintStack(FILE* fout, StackNode** top) {
    if((*top) == NULL) 
        return;
    fprintStack(fout, &(*top)->next);
    fprintf(fout, "%d", (*top)->val.nr);
    ListNode* head = pop(top).listhead;
    fprint(fout, head);
    fprintf(fout, "\n");
    listfree(head);
}

void deleteStack(StackNode** top) {
    while ((*top) != NULL) {
        StackNode* temp;
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}