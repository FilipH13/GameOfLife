#include "listlib.h"
#define CELULA_VIE 'X'
#define CELULA_MOARTA '+'

typedef char Data;

void citire_matrice(FILE *fin, Data **gen, int n, int m);
void printare_matrice(FILE *fout, Data **gen, int n, int m);
void eliberare_generatie(Data ***a, int n, int m);
ListNode* gen_urmatoare(Data **gen, int n, int m, int c);
void geninit(Data*** generatie, int nr_linii, int nr_coloane);
void GenerationTree(FILE *f, Data **gen, int n, int m, BinaryNode *root, int k, int c);
ListNode *create_initNode(Data **gen, int n, int m);
Graph *convert(Data **gen, int n, int m);
void getLHpath(FILE *f, Graph *g);