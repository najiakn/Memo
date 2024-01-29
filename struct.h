

#define PRO_Tache 100
// Définir la structure date_eche
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
    char priorite[PRO_Tache];
} taches;



