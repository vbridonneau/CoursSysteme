#include <stdlib.h> // pour malloc, realloc, free
#include "estPremier.h" // pour estPremier

int *crible(int *taille, int N) {
    int *tab = malloc(N * sizeof(int));
    *taille = 0;
    for (int i = 2; i < N; i++) {
        if (estPremier(i)) {
            tab[*taille] = i;
            (*taille) ++;
        }
    }
    tab = realloc(tab, (*taille) * sizeof(int)); // on réduit la taille du tableau
    return tab;
}