#include <stdio.h>
#include <string.h>
#include "conjugaison.h"

/* Renvoie 1 si le verbe figure deja dans le fichier de resultats. */
int conjugaison_existe(const char *verbe) {
    FILE *flot = fopen(FICHIER_RESULTATS, "r");
    if (!flot) return 0;

    char ligne[512];
    while (fgets(ligne, sizeof(ligne), flot)) {
        ligne[strcspn(ligne, "\r\n")] = '\0';
        if (strcmp(ligne, verbe) == 0) {
            fclose(flot);
            return 1;
        }
    }

    fclose(flot);
    return 0;
}
