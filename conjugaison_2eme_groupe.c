#include <stdio.h>
#include <string.h>
#include "conjugaison.h"

char *terminaison_2_present_simple[] = {"is", "is", "it", "issons", "issez", "issent"};
char *terminaison_2_passe_simple[] = {"is", "is", "it", "imes", "ites", "irent"};
char *terminaison_2_imparfait[] = {"issais", "issais", "issait", "issions", "issiez", "issaient"};
char *terminaison_2_futur_simple[] = {"irai", "iras", "ira", "irons", "irez", "iront"};

char *avoir_2_passe_compose[] = {"ai","as","a","avons","avez","ont"};
char *avoir_2_passe_anterieur[] = {"eus","eus","eut","eumes","eutes","eurent"};
char *avoir_2_plus_que_parfait[] = {"avais","avais","avait","avions","aviez","avaient"};
char *avoir_2_futur_anterieur[] = {"aurai","auras","aura","aurons","aurez","auront"};

int est_second_groupe(char *verbe, int taille) {
    return (verbe[taille - 1] == 'r' && verbe[taille - 2] == 'i');
}

void conjuguer_second_groupe(FILE *flot, char *verbe) {
    const char *pronom[6] = {
        "Je", "Tu", "Il/Elle", "Nous", "Vous", "Ils/Elles"
    };

    fprintf(flot, "Ce verbe est du second groupe.\n");

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

    fprintf(flot,"\n PRESENT \n");

    for ( int i=0 ; i<6 ; i++ ) {
        fprintf(flot,"%s%s%s%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_2_present_simple[i]);
    }

    fprintf(flot,"\n PASSE SIMPLE \n");

    for ( int i=0 ; i<6 ; i++ ) {
        fprintf(flot,"%s%s%s%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_2_passe_simple[i]);
    }

    fprintf(flot,"\n IMPARFAIT \n");

    for ( int i=0 ; i<6 ; i++ ) {
        fprintf(flot,"%s%s%s%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_2_imparfait[i]);
    }

    fprintf(flot,"\n FUTUR SIMPLE \n");

    for ( int i=0 ; i<6 ; i++ ) {
        fprintf(flot,"%s%s%s%s\n", pronom[i], sep(pronom[i]), ptr, terminaison_2_futur_simple[i]);
    }

     if (avoir_2_futur_anterieur[0][0]=='a' || avoir_2_passe_anterieur[0][0]=='a' || 
        avoir_2_passe_compose[0][0]=='a' || avoir_2_plus_que_parfait[0][0]== 'a' ) {
            pronom[0]="J'";
        }

    fprintf(flot, "\n PASSE COMPOSE \n");

    for( int i=0 ; i<6 ; i++ ) {
        fprintf(flot, "%s%s%s %si\n", pronom[i], sep(pronom[i]), avoir_2_passe_compose[i], ptr);
    }

    fprintf(flot, "\n PASSE ANTERIEUR\n");

    for( int i=0 ; i<6 ; i++ ) {
        fprintf(flot, "%s%s%s %si\n", pronom[i], sep(pronom[i]), avoir_2_passe_anterieur[i], ptr);
    }

    fprintf(flot, "\n PLUS-QUE-PARFAIT \n");

    for( int i=0 ; i<6 ; i++ ) {
        fprintf(flot, "%s%s%s %si\n", pronom[i], sep(pronom[i]), avoir_2_plus_que_parfait[i], ptr);
    }

    fprintf(flot, "\n FUTUR ANTERIEUR \n");

    for( int i=0 ; i<6 ; i++ ) {
        fprintf(flot, "%s%s%s %si\n", pronom[i], sep(pronom[i]), avoir_2_futur_anterieur[i], ptr);
    }

}
