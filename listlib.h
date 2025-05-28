#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct sd {
    int nr;
    ListNode* listhead;
};

typedef struct sd StackData;

struct StackList {
    StackData val;
    struct StackList* next;
};

typedef struct StackList StackNode;

struct bt {
    StackData val;
    struct bt *left, *right;
};

typedef struct bt BinaryNode;


 typedef struct gld {
    int nr_ord;
    int linie;
    int coloana;
    int grad;
 } GraphVerticesData;

typedef struct gr {
    int V; 
    int E; 
    int **a;
    GraphVerticesData *vertices;

 } Graph;

//functii lista
void addAtEnd(ListNode** head, ListData v);
void listfree(ListNode* head);
//functii stack
void push(StackNode** top, StackData v);
void fprintStack(FILE* fout, StackNode** top);
void deleteStack(StackNode** top);
//functii arbore
void initTree(BinaryNode **root, StackData d);
void deleteTree(BinaryNode **root);
//
int DFS(FILE* f, Graph *g);