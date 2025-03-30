#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    FILE *fin, *fout;
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    char s[100];
    fscanf(fin, "%s", s);
    fprintf(fout, "%s", s);
}