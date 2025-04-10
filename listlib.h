#include <stdio.h>
#include <stdlib.h>

struct lc {
    int linie;
    int coloana;
};

typedef struct lc ListData;

struct Elem {
    ListData val;
    struct Elem* next;
};

typedef struct Elem ListNode;

struct StackList {
    ListNode* val;
    struct StackList* next;
};

typedef struct StackList StackNode;

void addAtBeginning(ListNode** head, ListData v);
void addAtEnd(ListNode** head, ListData v);
void print(ListNode *head);
void push(StackNode** top, ListNode* v);
ListNode* pop(StackNode** top);
void deleteStack(StackNode** top);