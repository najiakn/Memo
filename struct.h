

#define PRO_Tache 100
// D�finir la structure date_eche
typedef struct {
    int jour;
    int mois;
    int annee;
} date_eche;

// D�finir la structure taches
typedef struct {
    char nom[PRO_Tache];
    char description[PRO_Tache];
    date_eche date;
    char priorite[PRO_Tache];
} taches;



