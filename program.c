#include "genlib.h"

int main (int argc, const char* argv[]) {

    //declarare variabile
    FILE *fin, *fout;
    int nr_fisier, nr_linii, nr_coloane, nr_generatii, i;
    char **generatie;
    StackNode* stackTop = NULL;
    BinaryNode* BinTree = NULL;

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
    fscanf(fin, "%d", &nr_linii);
    fscanf(fin, "%d", &nr_coloane);
    fscanf(fin, "%d", &nr_generatii);

    //Alocare memorie pentru generatie
    geninit(&generatie, nr_linii, nr_coloane);

    citire_matrice(fin, generatie, nr_linii, nr_coloane);

    switch (nr_fisier)
    {
    case 1:
        printare_matrice(fout, generatie, nr_linii, nr_coloane);
        //Generare generatie urmatoare si printare
        for (i = 0; i < nr_generatii; i++) {
            listfree(gen_urmatoare(generatie, nr_linii, nr_coloane, 0));
            printare_matrice(fout, generatie, nr_linii, nr_coloane);
        }
        break;
    
    case 2:
        for (i = 0; i < nr_generatii; i++) {
            StackData genlist = {i+1, gen_urmatoare(generatie, nr_linii, nr_coloane, 0)};
            push(&stackTop, genlist);
        }
        fprintStack(fout, &stackTop);
        break;
    case 3:
        StackData genbinlist = {0, create_initNode(generatie, nr_linii, nr_coloane)};
        initTree(&BinTree, genbinlist);
        printGenTree(fout, generatie, nr_linii, nr_coloane, BinTree, nr_generatii);
        deleteTree(&BinTree);
        break;
    default: break;
    }
    deleteStack(&stackTop);
    eliberare_generatie(&generatie, nr_linii, nr_coloane);

    return 0;
}