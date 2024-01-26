#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRO_Tache 100

typedef struct {
    int jour;
    int mois;
    int annee;
} date_eche;

typedef struct {
    char nom[PRO_Tache];
    char description[PRO_Tache];
    date_eche date;
    char priorite[PRO_Tache];
} taches;

void ajouter(taches tache[], int tache_nombre) {
    printf("Ajouter une tache :\n");

    printf("Tapez le nom : ");
    scanf("%s", tache[tache_nombre].nom);

    printf("Tapez la description : ");
    scanf(" %[^\n]", tache[tache_nombre].description);

    printf("Tapez la date d'echeance :\n");
    printf("Tapez le jour : ");
    scanf("%d", &(tache[tache_nombre].date.jour));

    printf("Tapez le mois : ");
    scanf("%d", &(tache[tache_nombre].date.mois));

    printf("Tapez l'annee : ");
    scanf("%d", &(tache[tache_nombre].date.annee));

    printf("Tapez la priorite : ");
    scanf("%s", tache[tache_nombre].priorite);

    printf("Ajout avec succès !\n");
}

void afficher(taches tache[], int tache_nombre) {
    printf("Afficher les taches :\n");

    int i;
for (i = 0; i < tache_nombre; i++) {
    printf("%d. Nom : %s, Description : %s, Date : %d/%d/%d, Priorite : %s\n",
           i + 1, tache[i].nom, tache[i].description,
           tache[i].date.jour, tache[i].date.mois, tache[i].date.annee,
           tache[i].priorite);
}
}


void modifier(taches tache[], int tache_nombre) {
    printf("Liste des taches :\n");

   int i;
for (i = 0; i < tache_nombre; i++) {
        printf("%d. Nom : %s, Description : %s, Date : %d/%d/%d, Priorite : %s\n",
               i + 1, tache[i].nom, tache[i].description,
               tache[i].date.jour, tache[i].date.mois, tache[i].date.annee,
               tache[i].priorite);
    }

    int choixIndice;
    printf("Tapez le numero de l'indice de la tache a modifier : ");
    scanf("%d", &choixIndice);

    if (choixIndice >= 1 && choixIndice <= tache_nombre) {
        int index = choixIndice - 1;

        printf("Champs disponibles pour modification :\n");
        printf("1. Nom\n");
        printf("2. Description\n");
        printf("3. Date d'echeance\n");
        printf("4. Priorite\n");

        int choixChamp;
        printf("Tapez le numero du champ a modifier : ");
        scanf("%d", &choixChamp);

        switch (choixChamp) {
            case 1:
                printf("Tapez le nouveau nom : ");
                scanf("%s", tache[index].nom);
                break;
            case 2:
                printf("Tapez la nouvelle description : ");
                scanf(" %[^\n]", tache[index].description);
                break;
            case 3:
                printf("Tapez la nouvelle date d'echeance :\n");
                printf("Tapez le jour : ");
                scanf("%d", &(tache[index].date.jour));
                printf("Tapez le mois : ");
                scanf("%d", &(tache[index].date.mois));
                printf("Tapez l'annee : ");
                scanf("%d", &(tache[index].date.annee));
                break;
            case 4:
                printf("Tapez la nouvelle priorite : ");
                scanf("%s", tache[index].priorite);
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre correspondant au champ.\n");
                return;
        }

        printf("Modification avec succes !\n");
    } else {
        printf("Indice invalide.\n");
    }
}

void menu() {
    int choix = 1;
    taches tache[PRO_Tache];
    int tache_nombre = 0;

    while (choix != 4) {
        printf("1--------------Afficher les taches----------------\n");
        printf("2--------------Ajouter une tache-------------------\n");
        printf("3--------------Moddifier une tache-----------------\n");
        printf("4--------------Fermer-------------------------------\n");

        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficher(tache, tache_nombre);
                break;

            case 2:
                ajouter(tache, tache_nombre);
                (tache_nombre)++;
                break;

            case 3:
                modifier(tache, tache_nombre);
                break;
            case 4:
                printf("Fermeture demandée. Au revoir !\n");
                return;

            default:
                printf("Option non valide.\n");
        }
    }
}

int main() {
    menu();

    return 0;
}

