#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listlib.h"
#define CELULA_VIE 'X'
#define CELULA_MOARTA '+'

typedef char Data;

void citire_matrice(FILE *fin, Data **gen, int n, int m);
void printare_matrice(FILE *fout, Data **gen, int n, int m);
void eliberare_generatie(Data ***a, int n, int m);
ListNode* gen_urmatoare(Data **gen, int n, int m);