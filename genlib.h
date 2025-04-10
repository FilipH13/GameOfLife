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
void eliberare_matrice(int ***a, int n, int m);
int calcul_vecini_vii(Data **gen, int ln, int cl, int n, int m);
void gen_urmatoare(Data **gen, int n, int m);