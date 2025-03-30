#include "genlib.h"

void citire_matrice(FILE *fin, char **gen, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fin, " %c", &gen[i][j]);
        }
    }
}

void printare_matrice(FILE *fout, char **gen, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fout, "%c", gen[i][j]);
        } 
        fprintf(fout, "\n");
    }
    fprintf(fout, "\n");
}

void eliberare_generatie(char ***a, int n, int m) {
    for (int i = 0; i < n; i++) {
        free ((*(a))[i]);
    }
    free (*(a));
}

void eliberare_matrice(int ***a, int n, int m) {
    for (int i = 0; i < n; i++) {
        free ((*(a))[i]);
    }
    free (*(a));
}

int calcul_vecini_vii(char **gen, int ln, int cl, int n, int m) {
    int nr = 0;
    if (ln > 0 && cl > 0 && ln < n - 1 && cl < m - 1 ) { //celula centru 
        if (gen[ln][cl - 1] == CELULA_VIE) { //vecin stanga !
            nr++;
        }
        if (gen[ln][cl + 1] == CELULA_VIE) { //vecin dreapta
            nr++;
        }
        if (gen[ln - 1][cl] == CELULA_VIE) { //vecin sus !
            nr++;
        }
        if (gen[ln + 1][cl] == CELULA_VIE) { //vecin jos
            nr++;
        }
        if (gen[ln - 1][cl - 1] == CELULA_VIE) { //sus stanga
            nr++;
        }
        if (gen[ln + 1][cl - 1] == CELULA_VIE) { //jos stanga
            nr++;
        }
        if (gen[ln - 1][cl + 1] == CELULA_VIE) { //sus dreapta !
            nr++;
        }
        if (gen[ln + 1][cl + 1] == CELULA_VIE) { //jos dreapta
            nr++;
        }
    } else if (ln == 0) { //prima linie, fara vecini sus
        if (cl == 0) { //colt generatie stanga sus
            if (gen[ln][cl + 1] == CELULA_VIE) { //vecin dreapta
                nr++;
            }
            if (gen[ln + 1][cl] == CELULA_VIE) { //vecin jos
                nr++;
            }
            if (gen[ln + 1][cl + 1] == CELULA_VIE) { //jos dreapta
                nr++;
            }
        } else if (cl == m - 1) { //colt generatie dreapta sus
            if (gen[ln][cl - 1] == CELULA_VIE) { //vecin stanga
                nr++;
            }
            if (gen[ln + 1][cl] == CELULA_VIE) { //vecin jos
                nr++;
            }
            if (gen[ln + 1][cl - 1] == CELULA_VIE) { //jos stanga
                nr++;
            }
        } else {
            if (gen[ln][cl - 1] == CELULA_VIE) { //vecin stanga
                nr++;
            }
            if (gen[ln][cl + 1] == CELULA_VIE) { //vecin dreapta
                nr++;
            }
            if (gen[ln + 1][cl] == CELULA_VIE) { //vecin jos
                nr++;
            }
            if (gen[ln + 1][cl - 1] == CELULA_VIE) { //jos stanga
                nr++;
            }
            if (gen[ln + 1][cl + 1] == CELULA_VIE) { //jos dreapta
                nr++;
            }
        }
    } else if (ln == n - 1) { //ultima linie, fara vecini jos
        if (cl == 0) { //colt generatie stanga jos
            if (gen[ln][cl + 1] == CELULA_VIE) { //vecin dreapta
                nr++;
            }
            if (gen[ln - 1][cl] == CELULA_VIE) { //vecin sus
                nr++;
            }
            if (gen[ln - 1][cl + 1] == CELULA_VIE) { //sus dreapta
                nr++;
            }
        } else if (cl == m - 1) { //colt generatie dreapta jos
            if (gen[ln][cl - 1] == CELULA_VIE) { //vecin stanga
                nr++;
            }
            if (gen[ln - 1][cl] == CELULA_VIE) { //vecin sus
                nr++;
            }
            if (gen[ln - 1][cl - 1] == CELULA_VIE) { //sus stanga
                nr++;
            }
        } else {
            if (gen[ln][cl - 1] == CELULA_VIE) { //vecin stanga
                nr++;
            }
            if (gen[ln][cl + 1] == CELULA_VIE) { //vecin dreapta
                nr++;
            }
            if (gen[ln - 1][cl] == CELULA_VIE) { //vecin sus
                nr++;
            }
            if (gen[ln - 1][cl - 1] == CELULA_VIE) { //sus stanga
                nr++;
            }
            if (gen[ln - 1][cl + 1] == CELULA_VIE) { //sus dreapta
                nr++;
            }
        }
    } else if (cl == 0) { //prima coloana, fara vecini stanga
        if (gen[ln][cl + 1] == CELULA_VIE) { //vecin dreapta
            nr++;
        }
        if (gen[ln - 1][cl] == CELULA_VIE) { //vecin sus
            nr++;
        }
        if (gen[ln - 1][cl + 1] == CELULA_VIE) { //sus dreapta
            nr++;
        }
        if (gen[ln + 1][cl] == CELULA_VIE) { //vecin jos
            nr++;
        }
        if (gen[ln + 1][cl + 1] == CELULA_VIE) { //jos dreapta
            nr++;
        }
    } else if (cl == m - 1) { //ultima coloana, fara vecini dreapta
        if (gen[ln][cl - 1] == CELULA_VIE) { //vecin stanga
            nr++;
        }
        if (gen[ln - 1][cl] == CELULA_VIE) { //vecin sus
            nr++;
        }
        if (gen[ln - 1][cl - 1] == CELULA_VIE) { //sus stanga
            nr++;
        }
        if (gen[ln + 1][cl] == CELULA_VIE) { //vecin jos
            nr++;
        }
        if (gen[ln + 1][cl - 1] == CELULA_VIE) { //jos stanga
            nr++;
        }
    }
    return nr;
}

void gen_urmatoare(char **gen, int n, int m) {
    //Definire si alocare memore matrice nr_vecini_vii
    int **vecini, i, j;
    if ((vecini = (int**)malloc(n*sizeof(int*))) == NULL) {
        printf("Eroare alocare memorie generatie linii");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        if ((vecini[i] = (int*)malloc(m*sizeof(int))) == NULL) {
            printf("Eroare alocare memorie generatie coloane");
            exit(1);
        }
    }

    //
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            vecini[i][j] = calcul_vecini_vii(gen, i, j, n, m);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            switch (gen[i][j]) {
                case CELULA_VIE:
                    if (vecini[i][j] < 2 || vecini[i][j] > 3) {
                        gen[i][j] = CELULA_MOARTA;
                    }
                    break;
                default:
                    if (vecini[i][j] == 3) {
                        gen[i][j] = CELULA_VIE;
                    }
                    break;
            }
        }
    }
    eliberare_matrice(&vecini, n, m);
}