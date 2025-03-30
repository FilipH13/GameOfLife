#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CELULA_VIE 'X'
#define CELULA_MOARTA '+'

static void citire_matrice(FILE *fin, char **gen, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fin, " %c", &gen[i][j]);
        }
    }
}

static void printare_matrice(FILE *fout, char **gen, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fout, "%c", gen[i][j]);
        } 
        fprintf(fout, "\n");
    }
    fprintf(fout, "\n");
}

static void eliberare_generatie(char ***a, int n, int m) {
    for (int i = 0; i < n; i++) {
        free ((*(a))[i]);
    }
    free (*(a));
}

static void eliberare_matrice(int ***a, int n, int m) {
    for (int i = 0; i < n; i++) {
        free ((*(a))[i]);
    }
    free (*(a));
}

static int calcul_vecini_vii(char **gen, int ln, int cl, int n, int m) {
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

static void gen_urmatoare(char **gen, int n, int m) {
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

int main (int argc, const char* argv[]) {
    
    //declarare variabile
    FILE *fin, *fout;
    int nr_fisier, nr_linii, nr_coloane, nr_generatii, i;
    char **generatie;

    //verificare deschidere fisiere
    if ((fin = fopen(argv[1], "r")) == NULL) {
        printf("Eroare deschidere fisier de intrare");
        exit(1);
    }
    if ((fout = fopen(argv[2], "w")) == NULL) {
        printf("Eroare deschidere fisier de iesire");
        exit(1);
    }
    
    //Task 1: Simularea jocului game of life
    
    //Citire date
    fscanf(fin, "%d", &nr_fisier);
    fscanf(fin, "%d%d", &nr_linii, &nr_coloane);
    fscanf(fin, "%d", &nr_generatii);

    //Alocare memorie pentru generatie
    if ((generatie = (char**)malloc(nr_linii*sizeof(char*))) == NULL) {
        printf("Eroare alocare memorie generatie linii");
        exit(1);
    }
    for (i = 0; i < nr_linii; i++) {
        if ((generatie[i] = (char*)malloc(nr_coloane*sizeof(char))) == NULL) {
            printf("Eroare alocare memorie generatie coloane");
            exit(1);
        }
    }

    citire_matrice(fin, generatie, nr_linii, nr_coloane);

    printare_matrice(fout, generatie, nr_linii, nr_coloane);

    //Generare generatie urmatoare si printare
    for (i = 0; i < nr_generatii; i++) {
        gen_urmatoare(generatie, nr_linii, nr_coloane);
        printare_matrice(fout, generatie, nr_linii, nr_coloane);
    }

    eliberare_generatie(&generatie, nr_linii, nr_coloane);

    return 0;
}