#include <stdio.h>
#include <string.h>
#include "conjugaison.h"

char *terminaison_present_simple[] = {"e", "es", "e", "ons", "ez", "ent"};
char *terminaison_passe_simple[] = {"ai", "as", "a", "ames", "ates", "erent"};
char *terminaison_imparfait[] = {"ais", "ais", "ait", "ions", "iez", "aient"};
char *terminaison_futur_simple[] = {"erai", "eras", "era", "erons", "erez", "eront"};

char *avoir_passe_compose[] = {"ai","as","a","avons","avez","ont"};
char *avoir_passe_anterieur[] = {"eus","eus","eut","eumes","eutes","eurent"};
char *avoir_plus_que_parfait[] = {"avais","avais","avait","avions","aviez","avaient"};
char *avoir_futur_anterieur[] = {"aurai","auras","aura","aurons","aurez","auront"};

int est_premier_groupe(char *verbe, int taille) {
    return (verbe[taille - 1] == 'r' && verbe[taille - 2] == 'e');
}

void conjuguer_premier_groupe(FILE *flot, char *verbe) {
    const char *pronom[6] = {
        "Je", "Tu", "Il/Elle", "Nous", "Vous", "Ils/Elles"
    };

    fprintf(flot, "Ce verbe est du premier groupe.\n");

    char *ptr = verbe;
    int   taille = (int)strlen(verbe);

    if (verbe[0] == 's' && verbe[1] == 'e' && verbe[2] == ' ') {
        pronom[0] = "Je me";
        pronom[1] = "Tu te";
        pronom[2] = "Il/Elle se";
        pronom[3] = "Nous nous";
        pronom[4] = "Vous vous";
        pronom[5] = "Ils/Elles se";
        ptr    += 3;
        taille  = (int)strlen(ptr);
    }
    else if (verbe[0] == 'a' || verbe[0] == 'e' || verbe[0] == 'o' ||verbe[0] == 'u' || verbe[0] == 'i' || verbe[0] == 'y' || verbe[0] == 'h') {
        pronom[0] = "J'";
    }

    ptr[taille - 2] = '\0';

    fprintf(flot, "\n PRESENT \n");

    for (int i = 0; i < 6; i++) {
        taille = (int)strlen(ptr);

        if (i == 3 && ptr[taille - 1] == 'g') {
            fprintf(flot, "%s%s%se%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_present_simple[i]);
        }
        else if (i == 3 && ptr[taille - 1] == 'c') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sç%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_present_simple[i]);
            ptr[taille - 1] = 'c';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 'y') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%si%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_present_simple[i]);
            ptr[taille - 1] = 'y';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 'l' && ptr[taille - 2] == 'e') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sll%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_present_simple[i]);
            ptr[taille - 1] = 'l';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 't' && ptr[taille - 2] == 'e') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%stt%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_present_simple[i]);
            ptr[taille - 1] = 't';
        }
        else {
            fprintf(flot, "%s%s%s%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_present_simple[i]);
        } 
    }

    fprintf(flot, "\n PASSE SIMPLE \n");

    for (int i = 0; i < 6; i++) {
        taille = (int)strlen(ptr);

        if (i == 3 && ptr[taille - 1] == 'g') {
            fprintf(flot, "%s%s%se%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_passe_simple[i]);
        }
        else if ( ptr[taille - 1] == 'g' && terminaison_passe_simple[i][0] =='a' ) {
            fprintf(flot, "%s%s%se%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_passe_simple[i]);
        }
        else if (i == 3 && ptr[taille - 1] == 'c') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sç%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_passe_simple[i]);
            ptr[taille - 1] = 'c';
        }
        else if  ( ptr[taille - 1] == 'c' && terminaison_passe_simple[i][0]=='a' )  {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sç%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_passe_simple[i]);
            ptr[taille - 1] = 'c';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 'y') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%si%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_passe_simple[i]);
            ptr[taille - 1] = 'y';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 'l' && ptr[taille - 2] == 'e') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sll%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_passe_simple[i]);
            ptr[taille - 1] = 'l';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 't' && ptr[taille - 2] == 'e') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%stt%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_passe_simple[i]);
            ptr[taille - 1] = 't';
        }
        else {
            fprintf(flot, "%s%s%s%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_passe_simple[i]);
        }
    }

    fprintf(flot, "\n IMPARFAIT \n");

    for (int i = 0; i < 6; i++) {
        taille = (int)strlen(ptr);

        if (i == 3 && ptr[taille - 1] == 'g') {
            fprintf(flot, "%s%s%se%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_imparfait[i]);
        }
        else if ( ptr[taille - 1] == 'g' && terminaison_imparfait[i][0] =='a' ) {
            fprintf(flot, "%s%s%se%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_imparfait[i]);
        }
        else if  ( ptr[taille - 1] == 'c' && terminaison_imparfait[i][0]=='a' )  {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sç%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_imparfait[i]);
            ptr[taille - 1] = 'c';
        }
        else if  ( ptr[taille - 1] == 'c' && i == 3 )  {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sç%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_imparfait[i]);
            ptr[taille - 1] = 'c';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 'y') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%si%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_imparfait[i]);
            ptr[taille - 1] = 'y';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 'l' && ptr[taille - 2] == 'e') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sll%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_imparfait[i]);
            ptr[taille - 1] = 'l';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 't' && ptr[taille - 2] == 'e') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%stt%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_imparfait[i]);
            ptr[taille - 1] = 't';
        }
        else {
            fprintf(flot, "%s%s%s%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_imparfait[i]);
        }
    }

    fprintf(flot, "\n FUTUR SIMPLE \n");

    for (int i = 0; i < 6; i++) {
        taille = (int)strlen(ptr);

        if (i == 3 && ptr[taille - 1] == 'g' && terminaison_futur_simple[i][0] !='e' ) {
            fprintf(flot, "%s%s%se%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_futur_simple[i]);
        }
        else if (i == 3 && ptr[taille - 1] == 'c') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sç%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_futur_simple[i]);
            ptr[taille - 1] = 'c';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 'y') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%si%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_futur_simple[i]);
            ptr[taille - 1] = 'y';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 'l' && ptr[taille - 2] == 'e') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%sll%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_futur_simple[i]);
            ptr[taille - 1] = 'l';
        }
        else if ((i == 0 || i == 1 || i == 2 || i == 5) &&
                 ptr[taille - 1] == 't' && ptr[taille - 2] == 'e') {
            ptr[taille - 1] = '\0';
            fprintf(flot, "%s%s%stt%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_futur_simple[i]);
            ptr[taille - 1] = 't';
        }
        else {
            fprintf(flot, "%s%s%s%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_futur_simple[i]);
        }
    }

    if (avoir_futur_anterieur[0][0]=='a' || avoir_passe_anterieur[0][0]=='a' || 
        avoir_passe_compose[0][0]=='a' || avoir_plus_que_parfait[0][0]== 'a' ) {
            pronom[0]="J'";
        }

    fprintf(flot, "\n PASSE COMPOSE \n");

    for( int i=0 ; i<6 ; i++ ) {
        fprintf(flot, "%s%s%s %sé\n", pronom[i], sep(pronom[i]), avoir_passe_compose[i], ptr);
    }

    fprintf(flot, "\n PASSE ANTERIEUR\n");

    for( int i=0 ; i<6 ; i++ ) {
        fprintf(flot, "%s%s%s %sé\n", pronom[i], sep(pronom[i]), avoir_passe_anterieur[i], ptr);
    }

    fprintf(flot, "\n PLUS-QUE-PARFAIT \n");

    for( int i=0 ; i<6 ; i++ ) {
        fprintf(flot, "%s%s%s %sé\n", pronom[i], sep(pronom[i]), avoir_plus_que_parfait[i], ptr);
    }

    fprintf(flot, "\n FUTUR ANTERIEUR \n");

    for( int i=0 ; i<6 ; i++ ) {
        fprintf(flot, "%s%s%s %sé\n", pronom[i], sep(pronom[i]), avoir_futur_anterieur[i], ptr);
    }

}