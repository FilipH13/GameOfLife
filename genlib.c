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

static int nr_same_label(int **labels, int n, int m, int k) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labels[i][j] == k) {
                cnt++;
            }
        }
    }
    return cnt;
}

static int existamuchie(GraphVerticesData v1, GraphVerticesData v2) {
    
    int disti = ((v2.linie - v1.linie) > 0) ? v2.linie - v1.linie : v1.linie - v2.linie;
    int distj = ((v2.coloana - v1.coloana) > 0) ? v2.coloana - v1.coloana : v1.coloana - v2.coloana;
    if (disti <= 1 && distj <= 1) {
        return 1;
    }
    return 0;

}

static Graph *build_graph(Data **gen, int n, int m, int** labels, int k) {
    int i,j;
    Graph* g;
    if ((g = (Graph*)malloc(sizeof(Graph))) == NULL) {
        printf("Eroare alocare de memorie convert graph");
        exit(1);
    }
    g->V = nr_same_label(labels, n, m, k);
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

    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (gen[i][j] == CELULA_VIE && labels[i][j] == k) {
                g->vertices[index].nr_ord = index;
                g->vertices[index].linie = i;
                g->vertices[index++].coloana = j;
            }
        }
    }

    for (i = 0; i < g->V; i++) {
        for (j = 0; j < i; j++) {
            g->a[i][j] = existamuchie(g->vertices[i], g->vertices[j]); //pentru ca j < i
            g->a[j][i] = g->a[i][j];
            if (g->a[i][j] != 0) {
                g->E += 2;
                g->vertices[i].grad++;
                g->vertices[j].grad++;
            }
        }
    }
    return g;
}

static int hamiltonian_bool(Graph *g, int curr, int *visited, int *path, int npath) {
    if (npath == g->V) {
        return 1;
    }

    int *near, count = 0;
    if ((near = (int*)malloc(g->V*sizeof(int))) == NULL) {
        printf("memerror hb near");
        exit(1);
    }

    for (int i = 0; i < g->V; i++) {
        if (g->a[curr][i] == 1 && visited[i] == 0) {
            near[count++] = i;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (g->vertices[near[i]].linie > g->vertices[near[j]].linie || (g->vertices[near[i]].linie == g->vertices[near[j]].linie && 
                        g->vertices[near[i]].coloana > g->vertices[near[j]].coloana)) {
                int aux = near[i];
                near[i] = near[j];
                near[j] = aux;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        int next = near[i];
        visited[next] = 1;
        path[npath] = next;
        if (hamiltonian_bool(g, next, visited, path, npath + 1)) {
            free(near);
            return 1;
        }
        visited[next] = 0;
    }
    free(near);
    return 0;
}

static void print_path(FILE *f, const Graph *g, const int *path) {
            fprintf(f, "%d\n", g->V - 1);
            for (int i = 0; i < g->V; i++) {
                fprintf(f, "(%d ,%d) ", g->vertices[path[i]].linie, g->vertices[path[i]].coloana);
            }
            fprintf(f, "\n");
}

static int* findHpath(Graph *g) {
    int *visited, *path; 
    if ((visited = (int*)calloc(g->V, sizeof(int))) == NULL) {
        printf("Eroare alocare memorie findHpath visited");
        exit(1);
    }
    if ((path = (int*)calloc(g->V, sizeof(int))) == NULL) {
        printf("Eroare alocare memorie findHpath visited");
        exit(1);
    }

    for (int i = 0; i < g->V; i++) {
        visited[i] = 1;
        path[0] = i;

        if (hamiltonian_bool(g, i, visited, path, 1)) {
            free(visited);
            return path;
        }

        visited[i] = 0;
    }

    free(visited);
    free(path);
    return NULL;
}

static void fill_label(Data **gen, int **labels, int n, int m, int i, int j, int l) {
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (gen[i][j] == CELULA_MOARTA || labels[i][j] != 0) return;
    labels [i][j] = l;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di != 0 || dj != 0) {
                fill_label(gen, labels, n, m, i + di, j + dj, l);
            }
        }
    }
}

static Graph **convert(Data **gen, int n, int m, int *num) {
    int **labels; 
    if ((labels = (int**)calloc(n, sizeof(int*))) == NULL) {
        printf("Eroare alocare memorie labels linii");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        if ((labels[i] = (int*)calloc(m, sizeof(char))) == NULL) {
            printf("Eroare alocare memorie labels coloane");
            exit(1);
        }
    }
    int currentl = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (gen[i][j] == CELULA_VIE && labels[i][j] == 0) {
                fill_label(gen, labels, n, m, i, j, currentl);
                currentl++;
            }
        }
    }
    int ncomp = currentl - 1;
    Graph **graphs;
    if ((graphs = (Graph**)malloc(ncomp*sizeof(Graph*))) == NULL) {
        printf("Eroare alocare memorie graphs array");
        exit(1);
    }
    for (int i = 0; i < ncomp; i++) {
        Graph *gi = build_graph(gen, n, m, labels, i + 1);
        graphs[i] = gi;
    }

    for (int i = 0; i < n; i++) {
        free(labels[i]);
    }
    free(labels);
    *num = ncomp;
    return graphs;
}

static int *sort_graphs(Graph **arr, int n) {
    int *s;    
    if ((s = (int*)malloc(n*sizeof(int))) == NULL) {
        printf("Eroare alocare memorie sorted");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        s[i] = i;
    }
    for (int i = 1; i < n; i++) {
        int x = s[i];
        int p = i -1;
        while (p >= 0 && arr[s[p]]->V < arr[x]->V) {
            s[p+1] = s[p];
            p--;
        }
        s[p+1] = i;
    }
    return s;
}

static void free_graph(Graph *g) {
    for (int i = 0; i < g->V; i++) {
        free(g->a[i]);
    }
    free(g->a);
    free(g->vertices);
    free(g);
}

static void hamilton(FILE *f, Data** gen, int n, int m) {
    int galength;
    Graph **grapharray = convert(gen, n, m, &galength);
    int *sorted = sort_graphs(grapharray, galength);
    
    int ok = 1;
    for (int i = 0; i < galength; i++) {
        int *path = findHpath(grapharray[sorted[i]]);
        if (path != NULL) {
            print_path(f, grapharray[sorted[i]], path);
            ok = 0;
            free(path);
            break;
        };
    }
    for (int i = 0; i < galength; i++) {
        free_graph(grapharray[i]);
    }
    free(grapharray);
    free(sorted);
    if (ok) {
        fprintf(f, "-1\n");
    }
}

void printGenTree(FILE *f, Data **gen, int n, int m, BinaryNode *root, int k, int c) {
    if (k < 0) {
        return;
    }
    if (c == 0) {
        printare_matrice(f, gen, n, m);
    } else if (c == 1) {
        hamilton(f, gen, n, m);
    }
    Data **copy;
    geninit(&copy, n, m);
    gencpy(copy, gen, n, m);
    StackData listleft = {root->val.nr + 1, gen_urmatoare(copy, n, m, 1)};
    StackData listright = {root->val.nr + 1, gen_urmatoare(gen, n, m, 0)};
    initTree(&root->left, listleft);
    initTree(&root->right, listright);
    k--;
    printGenTree(f, copy, n, m, root->left, k, c);
    printGenTree(f, gen, n, m, root->right, k, c);
    eliberare_generatie(&gen, n, m);
    eliberare_generatie(&copy, n, m);
}