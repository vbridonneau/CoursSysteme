#include "crible.h"

#define N 10 // taille du tableau

#include <stdio.h> // pour printf
#include <stdlib.h> // pour free
#include <stdbool.h> // pour les booléens

bool test() {
    int taille;
    int *tab = crible(&taille, N);
    if (taille != 4) {
        return false;
    }
    int tab2[4] = {2, 3, 5, 7};
    for (int i = 0; i < taille; i++) {
        if (tab[i] != tab2[i]) {
            free(tab);
            return false;
        }
    }
    free(tab);
    return true;
}

int main() {
    int taille;
    int *tab = crible(&taille, N);

    test() ? printf("Test réussi\n") : printf("Test échoué\n");
    
    free(tab);
    return 0;
}