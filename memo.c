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

    printf("Ajout avec succ�s !\n");
 
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
                printf("Fermeture demand�e. Au revoir !\n");
                return;

            default:
                printf("Option non valide.\n");
        }
    }
}

int main() {
    menu();

    return 0;#include <stdio.h>
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
    scanf("%s", tache[tache_nombre].description);

    printf("Tapez la date d'echeance :\n");
    printf("Tapez le jour : ");
    scanf("%d", &(tache[tache_nombre].date.jour));

    printf("Tapez le mois : ");
    scanf("%d", &(tache[tache_nombre].date.mois));

    printf("Tapez l'annee : ");
    scanf("%d", &(tache[tache_nombre].date.annee));

    printf("Tapez la priorite : ");
    scanf("%s", tache[tache_nombre].priorite);

    printf("Ajout avec succ�s !\n");

   
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
void modifier(taches tache[], int tache_nombre) {
    char nom[PRO_Tache];
    printf("Tapez le nom de la tache a modifier : ");
    scanf("%s", nom);

    int index = -1;
    for (int i = 0; i < tache_nombre; i++) {
        if (strcmp(tache[i].nom, nom) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Tapez la nouvelle description : ");
        scanf("%s", tache[index].description);

        printf("Tapez la nouvelle date d'echeance :\n");
        printf("Tapez le jour : ");
        scanf("%d", &(tache[index].date.jour));

        printf("Tapez le mois : ");
        scanf("%d", &(tache[index].date.mois));

        printf("Tapez l'annee : ");
        scanf("%d", &(tache[index].date.annee));

        printf("Tapez la nouvelle priorite : ");
        scanf("%s", tache[index].priorite);

        printf("Modification avec succes !\n");
    } else {
        printf("Tache non trouvee avec le nom %s\n", nom);
    }
}

void menu() {
    int choix = 1;
    taches tache[PRO_Tache];
    int tache_nombre = 0;

    while (choix !=4    ) {
        printf("1--------------Afficher les taches----------------\n");
        printf("2--------------Ajouter une tache-------------------\n");
        printf("3--------------Supprimer une tache-----------------\n");
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
                printf("Fermeture demand�e. Au revoir !\n");
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
