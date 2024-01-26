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

    for (int i = 0; i < tache_nombre; i++) {
        printf(" Nom : %s, Description : %s, Date : %d/%d/%d, Priorite : %s\n",
               tache[i].nom, tache[i].description,
               tache[i].date.jour, tache[i].date.mois, tache[i].date.annee,
               tache[i].priorite);
    }
}


void supprimer(taches tache[], int *tache_nombre) {
    char nom[PRO_Tache];
    printf("Tapez le nom de la tache a supprimer : ");
    scanf("%s", nom);

    int index = -1;
    for (int i = 0; i < *tache_nombre; i++) {
        if (strcmp(tache[i].nom, nom) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Décaler les éléments suivants pour remplir l'emplacement supprimé
        for (int i = index; i < *tache_nombre - 1; i++) {
            tache[i] = tache[i + 1];
        }

        (*tache_nombre)--;
        printf("Suppression avec succes !\n");
    } else {
        printf("Tache non trouvee avec le nom %s\n", nom);
    }
}

void menu() {
    int choix = 1;
    taches tache[PRO_Tache];
    int tache_nombre = 0;

    while (choix != 5) {
        printf("1--------------Afficher les taches----------------\n");
        printf("2--------------Ajouter une tache-------------------\n");
        printf("3--------------Moddifier une tache-----------------\n");
        printf("4--------------Supprimer une tache-----------------\n");
        printf("5--------------Fermer-------------------------------\n");

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
                
                break;

            case 4:
                supprimer(tache, &tache_nombre);
                break;

            case 5:
                printf("Fermeture demandée. Au revoir !\n");
                break;

            default:
                printf("Option non valide.\n");
        }
    }
}

int main() {
    menu();

    return 0;
}
