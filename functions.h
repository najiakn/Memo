//function ajouter
#include <stdio.h>
#include <stdlib.h>

#define PRO_Tache 100

typedef struct {
    int jour;
    int mois;
    int annee;
} date_eche;

// Définir la structure taches
typedef struct {
    char nom[PRO_Tache];
    char description[PRO_Tache];
    date_eche date;
    int priorite;
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
    scanf("%d", &tache[tache_nombre].priorite);

    printf("Ajout avec succès !\n");
}


//function Afficher

void afficher(taches tache[], int tache_nombre) {
    printf("Afficher les taches :\n");

    int i;
for (i = 0; i < tache_nombre; i++) {
    printf("%d. Nom : %s, Description : %s, Date : %d/%d/%d, Priorite : %d\n",
           i + 1, tache[i].nom, tache[i].description,
           tache[i].date.jour, tache[i].date.mois, tache[i].date.annee,
           tache[i].priorite);
}
}


//function Modifier
void modifier(taches tache[], int tache_nombre) {
    printf("Liste des taches :\n");

   int i;
for (i = 0; i < tache_nombre; i++) {
        printf("%d. Nom : %s, Description : %s, Date : %d/%d/%d, Priorite : %d\n",
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
                scanf("%d", &tache[index].priorite);
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

//function Supprimer

void supprimer(taches tache[], int *tache_nombre) {
    if (*tache_nombre == 0) {
        printf("Aucune tache disponible pour la suppression.\n");
        return;
    }

    printf("Liste des taches :\n");

    int i;
    for (i = 0; i < *tache_nombre; i++) {
        printf("%d. Nom : %s, Description : %s, Date : %d/%d/%d, Priorite : %d\n",
               i + 1, tache[i].nom, tache[i].description,
               tache[i].date.jour, tache[i].date.mois, tache[i].date.annee,
               tache[i].priorite);
    }

    int choixIndice;
    printf("Tapez le numero de l'indice de la tache a supprimer : ");
    scanf("%d", &choixIndice);

    if (choixIndice >= 1 && choixIndice <= *tache_nombre) {
        int index = choixIndice - 1;

        // Shift elements to fill the gap
        for (i = index; i < *tache_nombre - 1; i++) {
            tache[i] = tache[i + 1];
        }

        (*tache_nombre)--;
        printf("Suppression avec succes !\n");
    } else {
        printf("Indice invalide.\n");
    }
}



//trier
void trier(taches tache[],int tache_nombre ,int ordre){
	int i ;
	for( i =0;i<tache_nombre -1;i++){
		int j ;
		for(j =0;j<tache_nombre -1 -i;j++){
 int result;
 if(ordre==1){
 	result=(tache[j].date.annee > tache[j + 1].date.annee) ||
                                      (tache[j].date.annee == tache[j + 1].date.annee &&
                                       tache[j].date.mois > tache[j + 1].date.mois) ||
                                      (tache[j].date.annee == tache[j + 1].date.annee &&
                                       tache[j].date.mois == tache[j + 1].date.mois &&
                                       tache[j].date.jour > tache[j + 1].date.jour);
 }
 			else {
                result= (tache[j].date.annee < tache[j + 1].date.annee) ||
                                      (tache[j].date.annee == tache[j + 1].date.annee &&
                                       tache[j].date.mois < tache[j + 1].date.mois) ||
                                      (tache[j].date.annee == tache[j + 1].date.annee &&
                                       tache[j].date.mois == tache[j + 1].date.mois &&
                                       tache[j].date.jour < tache[j + 1].date.jour);
            }
            if (result) {

                taches temp = tache[j];
                tache[j] = tache[j + 1];
                tache[j + 1] = temp;
            }

		}
	}
	
}
//
void filter(taches tache[], int tache_nombre) {
    int prio;
    int i ;
    printf("Entrez la priorite a filtrer  : ");
    scanf("%d", &prio);

    printf("Taches avec la priorite %d :\n", prio);
    int trouve = 0;
    for (i = 0; i < tache_nombre; i++) {
        if (tache[i].priorite == prio) {
            afficher(tache +i,1); // Affiche seulement la tache avec la priorite filtree
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("==================================\n");
        printf(" Aucune tache avec la priorite %d.\n", prio);
        printf("==================================\n");
    }
}




//function pour menu
void menu() {
    int choix = 1;
    taches tache[PRO_Tache];
    int tache_nombre = 0;

    while (choix != 7) {
        printf("1--------------Afficher les taches----------------\n");
        printf("2--------------Ajouter une tache-------------------\n");
        printf("3--------------Moddifier une tache-----------------\n");
         printf("4--------------Supprimer une tache-----------------\n");
        printf("5--------------trier les taches-------------------------------\n");
          printf("6--------------filter les taches-------------------------------\n");
    printf("7--------------Fermer-------------------------------\n");
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
              supprimer(tache, &tache_nombre);
               break;
            case 5:
              printf("1 trier par date croissante \n");
              
              printf("2 trier par date decroissante \n");
              printf("entrer votre choix \n");
              int choix_ordre;
              scanf("%d",&choix_ordre);
              trier(tache,tache_nombre,choix_ordre);
              
               break;
               
               case 6:
                filter(tache,tache_nombre);
                break;
            case 7:
                printf("Fermeture demandée. Au revoir !\n");
                break;

            default:
                printf("Option non valide.\n");
        }
    }
}

