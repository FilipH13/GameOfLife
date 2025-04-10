#include "genlib.h"

int main (int argc, const char* argv[]) {

    //declarare variabile
    FILE *fin, *fout;
    int nr_fisier, nr_linii, nr_coloane, nr_generatii, i;
    char **generatie;
    StackNode* stackTop = NULL;

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

    switch (nr_fisier)
    {
    case 1:
        printare_matrice(fout, generatie, nr_linii, nr_coloane);
        //Generare generatie urmatoare si printare
        for (i = 0; i < nr_generatii; i++) {
            listfree(gen_urmatoare(generatie, nr_linii, nr_coloane));
            printare_matrice(fout, generatie, nr_linii, nr_coloane);
        }
        break;
    
    case 2:
        for (i = 0; i < nr_generatii; i++) {
            StackData genlist = {i+1, gen_urmatoare(generatie, nr_linii, nr_coloane)};
            push(&stackTop, genlist);
        }
        fprintStack(fout, &stackTop);
        break;
    default: break;
    }
    deleteStack(&stackTop);
    eliberare_generatie(&generatie, nr_linii, nr_coloane);

    return 0;
}