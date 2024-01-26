#include <stdio.h>
#include <stdlib.h>

#define PRO_Tache 100

typedef struct {
    int jour;
    int mois;
    int annee;
} date_eche;

typedef struct {
    int code;
    char nom[20];
    char description[200];
    date_eche date;
    char priorite[100];
} taches;

taches ajouter() {

    taches tache1;

    printf("Remplissez la tache :\n");
    printf("Tapez le code : ");
    scanf("%d", &(tache1.code));

    printf("Tapez le nom : ");
    scanf("%s", tache1.nom);

    printf("Tapez la description : ");
    scanf("%s", tache1.description);

    printf("Tapez la date d'echeance :\n");
    printf("Tapez le jour : ");
    scanf("%d", &(tache1.date.jour));

    printf("Tapez le mois : ");
    scanf("%d", &(tache1.date.mois));

    printf("Tapez l'annee : ");
    scanf("%d", &(tache1.date.annee));

    printf("Tapez la priorite : ");
    scanf("%s", tache1.priorite);

    printf("Ajout avec succès !\n");
 
    return tache1;
}

void afficher(taches tache) {
    printf("Code : %d, Nom : %s, Description : %s, Date : %d/%d/%d, Priorite : %s\n",
           tache.code, tache.nom, tache.description,
           tache.date.jour, tache.date.mois, tache.date.annee,
           tache.priorite);
}

void menu() {
    int choix = 1;
    taches tache1;

    while (choix >= 1 && choix <= 4) {
        printf("1--------------Afficher les taches----------------\n");
        printf("2--------------Ajouter une tache-------------------\n");
        printf("3--------------Supprimer une tache-----------------\n");
        printf("4--------------Fermer-------------------------------\n");

        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Voici les taches :\n");
                afficher(tache1);
                break;

            case 2:
                printf("Ajouter une tache :\n");
                tache1 = ajouter();
                break;

            case 3:
                printf("Supprimer une tache :\n");
              
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
