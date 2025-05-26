#include "genlib.h"

void citire_matrice(FILE *fin, Data **gen, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fin, " %c", &gen[i][j]);
        }
    }
}

void printare_matrice(FILE *fout, Data **gen, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fout, "%c", gen[i][j]);
        } 
        fprintf(fout, "\n");
    }
    fprintf(fout, "\n");
}

void eliberare_generatie(Data ***a, int n, int m) {
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

static int calcul_vecini_vii(Data **gen, int ln, int cl, int n, int m) {
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

ListNode* gen_urmatoare(Data **gen, int n, int m, int c) {
    //Declarari
    int **vecini, i, j;
    ListNode* head = NULL;
    //Alocare memore matrice nr_vecini_vii
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

    //Populare matrice vecini
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            vecini[i][j] = calcul_vecini_vii(gen, i, j, n, m);
        }
    }
    if (c == 0) { //regula A
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                switch (gen[i][j]) {
                    case CELULA_VIE:
                        if (vecini[i][j] < 2 || vecini[i][j] > 3) {
                            gen[i][j] = CELULA_MOARTA;
                            ListData value = {i, j};
                            addAtEnd(&head, value);
                        }
                        break;
                    default:
                        if (vecini[i][j] == 3) {
                            gen[i][j] = CELULA_VIE;
                            ListData value = {i, j};
                            addAtEnd(&head, value);
                        }
                        break;
                }
            }
        }
    } else if (c == 1) { //regula B
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (vecini[i][j] == 2 && gen[i][j] == CELULA_MOARTA) {
                    gen[i][j] = CELULA_VIE;
                    ListData value = {i, j};
                    addAtEnd(&head, value);
                }
            }
        }
    }
    eliberare_matrice(&vecini, n, m);
    return head;
}

void geninit(Data*** generatie, int nr_linii, int nr_coloane) {
    if ((*generatie = (char**)malloc(nr_linii*sizeof(char*))) == NULL) {
        printf("Eroare alocare memorie generatie linii");
        exit(1);
    }
    for (int i = 0; i < nr_linii; i++) {
        if (((*generatie)[i] = (char*)malloc(nr_coloane*sizeof(char))) == NULL) {
            printf("Eroare alocare memorie generatie coloane");
            exit(1);
        }
    }
}

static void gencpy(char** gen1, Data** gen2, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            gen1[i][j] = gen2[i][j];
        }
    }
}

ListNode *create_initNode(Data **gen, int n, int m) {
    ListNode *head = NULL;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(gen[i][j] == CELULA_VIE) {
                ListData value = {i, j};
                addAtEnd(&head, value);
            }
        }
    }
    return head;
}

void GenerationTree(FILE *f, Data **gen, int n, int m, BinaryNode *root, int k, int c) {
    if (k < 0) {
        return;
    }
    if (c == 0) {
        printare_matrice(f, gen, n, m);
    }
    else if (c == 1) {
        Graph *g = convert(gen, n, m);
        getLHpath(f, g);
    }
    Data **copy;
    geninit(&copy, n, m);
    gencpy(copy, gen, n, m);
    StackData listleft = {root->val.nr + 1, gen_urmatoare(copy, n, m, 1)};
    StackData listright = {root->val.nr + 1, gen_urmatoare(gen, n, m, 0)};
    initTree(&root->left, listleft);
    initTree(&root->right, listright);
    k--;
    GenerationTree(f, copy, n, m, root->left, k, c);
    GenerationTree(f, gen, n, m, root->right, k, c);
    eliberare_generatie(&gen, n, m);
    eliberare_generatie(&copy, n, m);
}

int nr_celule_vii (Data **gen, int n, int m) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (gen[i][j] == CELULA_VIE) {
                k++;
            }
        }
    }
    return k;
}

int existamuchie(int a, int b, Data **gen, int n, int m, GraphVerticesData v) {
    int nr_ordine = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (gen[i][j] == CELULA_VIE) {
                nr_ordine++;
                if (nr_ordine == a) {
                    v.linie = i;
                    v.coloana = j;
                    v.nr_ord = nr_ordine;
                } else if (nr_ordine == b) {
                    int disti = ((i - v.linie) > 0) ? i - v.linie : v.linie - i;
                    int distj = ((j - v.coloana) > 0) ? j - v.coloana : v.coloana - j;
                    if (disti <= 1 && distj <= 1) {
                        return 1;
                    } else return 0;
                }
            }
        }
    }
    return -1;
}

Graph *convert(Data **gen, int n, int m) {
    int i,j;
    Graph* g;
    if ((g = (Graph*)malloc(sizeof(Graph))) == NULL) {
        printf("Eroare alocare de memorie convert graph");
        exit(1);
    }
    g->V = nr_celule_vii(gen, n, m);
    if ((g->a = (int**)malloc((g->V)*sizeof(int*))) == NULL) {
        printf("Eroare alocare de memorie convert matrix rows");
        exit(1); 
    }
    for (i = 0; i < g->V; i++) {
        if ((g->a[i] = (int*)calloc((g->V), sizeof(int))) == NULL) {
            printf("Eroare alocare de memorie convert matrix cols");
            exit(1); 
        }
    }
    g->E = 0;
    if ((g->vertices = (GraphVerticesData*)calloc((g->V), sizeof(GraphVerticesData))) == NULL) {
        printf("Eroare alocare de memorie convert vertices");
        exit(1);
    }

    for (i = 0; i < g->V; i++) {
        for (j = 0; j < i; j++) {
            g->a[i][j] = existamuchie(j, i, gen, n, m, g->vertices[j]); //pentru ca j < i
            g->a[j][i] = g->a[i][j];
            if (g->a[i][j] != 0){
                g->E += 2;
            }
        }
    }
    for (i = 0; i < g->V; i++) {
        for (j = 0; j < g->V; j++) {
            if (g->a[i][j] != 0) {
                g->vertices[i].grad++;
            }
        }
    }
    return g;
}

// void DFS_scan(FILE* f, Graph *g, int visited[], int i, int ord1) {
//     int j;
//     visited[i] = 1;
//     if (g->vertices[i].grad == 1) {
//         ord1++;
//     }
//     if (ord1 > 2) return -1;
//     fprintf(f, "Node %d -> ", i);
//     for (j = 0; j < g->V; j++) 
//         if (g->a[i][j] == 1 && visited[j] == 0)
//             DFS_scan(f, g, visited, j, ord1);
// }

void DFS_hamiltonian(FILE* f, Graph* g, int visited[], int path[], int pos, int current) {
    visited[current] = 1;
    path[pos] = current;

    if (pos == g->V - 1) {
        // Found a Hamiltonian path
        fprintf(f, "Hamiltonian Path: ");
        for (int i = 0; i < g->V; i++) {
            fprintf(f, "%d ", path[i]);
        }
        fprintf(f, "\n");
        //visited[current] = 0; // If you want *all* Hamiltonian paths
        return;
    }

    for (int j = 0; j < g->V; j++) {
        if (g->a[current][j] == 1 && visited[j] == 0) {
            DFS_hamiltonian(f, g, visited, path, pos + 1, j);
        }
    }

    visited[current] = 0; // backtrack
}

void getLHpath(FILE *f, Graph *g) {
    int i;
    int *visited = (int*)calloc(g->V,sizeof(int));
    int* head = (int*)calloc(g->V, sizeof(int));
    for (i = 0; i < g->V; i++) 
        if (visited[i] == 0) {
            int ord1 = 0;
            //DFS_hamiltonian(f, g, visited, head, 0, i);
        }
    free(visited);
}

