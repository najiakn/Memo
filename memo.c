#include <stdio.h>
#include<stdlib.h>

#define pro_tache 100;



typedef struct{
	int jour;
	int mois ;
	int anne;
}date_eche;


typedef struct{
	int code;
	char nom[20];
	char description[200];
	date_eche date;
	char  priorite[100]; 
	
}taches;
void ajouter(){
	
	 taches tache1;

	printf("remplirez la tache \n");
	printf("tapez le code \n");
	scanf("%d",&tache1.code);
	
	
		printf("tapez le nom \n");
	scanf("%s",tache1.nom);
	
	
	
		printf("tapez la description \n");
	scanf("%s",tache1.description);
	
	
	printf("tapez la date de eche \n");
		printf("tapez le jour \n");
       scanf("%d",&tache1.date.jour);
	
	
	
	printf("tapez le mois \n");
	scanf("%d",&tache1.date.mois);
		
		
		printf("tapez l'annee \n");
		scanf("%d",&tache1.date.anne);
		
	
	
	
		printf("tapez priorite\n");
	scanf("%s",tache1.priorite);
	
	
	printf("ajouter avec succe!!\n");
}
afficher(){
		 taches tache1;
	 date_eche date1;
	 	printf("code : %d , nom : %s   , description : %s    , date : %d %d %d  , priorite : %s \n",tache1.code,tache1.nom,tache1.description,tache1.date.jour,tache1.date.mois,tache1.date.anne,tache1.priorite);

}


void menu(){
  
      int choix = 1;
    while (choix >= 1 && choix <= 4) {
	 printf("1--------------Afficher les tache---------------- \n");
        printf("2--------------Ajouter une tache-------------------\n");
        printf("3--------------Supprimer une tache-----------------\n");
        printf("4--------------Fermer-------------------------------\n");
        
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("voila les taches\n");
               	afficher();
                break;

            case 2:
                printf("ajouter une tache\n");
                	ajouter();
                break;

            case 3:
                printf("supprimer une tache\n");
                
                break;

            case 4:
                printf("Fermeture demandée. Au revoir!\n");
                return;

            default:
                printf("Option non valide \n");
        }
    
}}

int main(){
	
	 taches tache1;
	 date_eche date1;


	menu();
	
} 
