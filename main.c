#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "conjugaison.h"

int main(void) {
    char verbe[256];
    char original[256];

    printf("Entrez un verbe : ");
    if (fgets(verbe, sizeof(verbe), stdin) == NULL) return 1;
    verbe[strcspn(verbe, "\r\n")] = '\0';

    /* On travaille en minuscules ("Aller" == "aller"). */
    for (int i = 0; verbe[i] != '\0'; i++)
        verbe[i] = (char)tolower((unsigned char)verbe[i]);

    /* Le radical doit contenir au moins une lettre (ex. "se laver" -> "laver"). */
    const char *base = (strncmp(verbe, "se ", 3) == 0) ? verbe + 3 : verbe;
    if (strlen(base) < 3) {
        printf("Verbe invalide : il faut au moins un radical et une terminaison.\n");
        return 1;
    }

    if (strcmp(verbe, "aller") == 0) {
        printf("Le verbe aller n'est ni du 1er ni du 2eme groupe.\n");
        return 0;
    }

    if (conjugaison_existe(verbe)) {
        printf("La conjugaison de \"%s\" est deja presente dans %s.\n", verbe, FICHIER_RESULTATS);
        return 0;
    }

    int taille = (int)strlen(verbe);
    int groupe;

    if (est_premier_groupe(verbe, taille))      groupe = 1;
    else if (est_second_groupe(verbe, taille))  groupe = 2;
    else {
        printf("Le verbe \"%s\" n'est pas du 1er ni du 2eme groupe (ou est irregulier).\n", verbe);
        return 0;
    }

    FILE *flot = fopen(FICHIER_RESULTATS, "a");
    if (flot == NULL) {
        perror("Impossible d'ouvrir " FICHIER_RESULTATS);
        return 1;
    }

    /* Les fonctions de conjugaison modifient le verbe : on garde une copie. */
    strcpy(original, verbe);
    fprintf(flot, "%s\n", verbe);
    if (groupe == 1) conjuguer_premier_groupe(flot, verbe);
    else             conjuguer_second_groupe(flot, verbe);
    fclose(flot);

    printf("Conjugaison de \"%s\" (%s groupe) enregistree dans %s.\n", original, groupe == 1 ? "1er" : "2eme", FICHIER_RESULTATS);
    return 0;
}
