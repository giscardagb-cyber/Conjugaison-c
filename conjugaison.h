#ifndef CONJUGAISON_H
#define CONJUGAISON_H

#include <stdio.h>
#include <string.h>

/* Fichier dans lequel les conjugaisons sont enregistrees
   (nom sans accent pour eviter les problemes d'encodage). */
#define FICHIER_RESULTATS "resultats.txt"

/* Renvoie "" apres une elision ("J'") et " " sinon. */
static inline const char *sep(const char *pronom) {
    size_t n = strlen(pronom);
    return (n > 0 && pronom[n - 1] == '\'') ? "" : " ";
}

int conjugaison_existe(const char *verbe);

int est_premier_groupe(char *verbe, int taille);
void conjuguer_premier_groupe(FILE *flot, char *verbe);

int est_second_groupe(char *verbe, int taille);
void conjuguer_second_groupe(FILE *flot, char *verbe);

#endif
