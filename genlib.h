#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CELULA_VIE 'X'
#define CELULA_MOARTA '+'

void citire_matrice(FILE *fin, char **gen, int n, int m);
void printare_matrice(FILE *fout, char **gen, int n, int m);
void eliberare_generatie(char ***a, int n, int m);
void eliberare_matrice(int ***a, int n, int m);
int calcul_vecini_vii(char **gen, int ln, int cl, int n, int m);
void gen_urmatoare(char **gen, int n, int m);