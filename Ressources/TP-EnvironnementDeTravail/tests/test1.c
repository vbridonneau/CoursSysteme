#include "crible.h"

#define N 100 // taille du tableau

#include <stdio.h> // pour printf
#include <stdlib.h> // pour free
#include <stdbool.h> // pour les booléens

bool test() {
    int taille;
    int *tab = crible(&taille, N);
    if (taille != 25) {
        return false;
    }
    int tab2[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
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