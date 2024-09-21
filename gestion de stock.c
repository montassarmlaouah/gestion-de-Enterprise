#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYES 100
#define MAX_VENTES 100

// Structures pour gérer les informations de l'entreprise
typedef struct {
    char nom[100];
    char adresse[200];
    char secteurActivite[100];
} Entreprise;

typedef struct {
    char nom[100];
    int age;
} Employe;

typedef struct {
    float montant;
} Vente;

// Variables globales
Entreprise entreprise;
Employe employes[MAX_EMPLOYES];
int nombreEmployes = 0;
Vente ventes[MAX_VENTES];
int nombreVentes = 0;
float stock = 0.0;
float charges = 0.0;
float budget = 0.0;

void Gestionentreprise() {
    printf("Entrez le nom de l'entreprise : ");
    scanf("%s", entreprise.nom);
    printf("Entrez l'adresse de l'entreprise : ");
    scanf("%s", entreprise.adresse);
    printf("Entrez le secteur d'activité : ");
    scanf("%s", entreprise.secteurActivite);

    printf("Entreprise créée : %s, Adresse : %s, Secteur : %s\n", entreprise.nom, entreprise.adresse, entreprise.secteurActivite);
}


void changenombreemploi() {
    printf("Entrez le nombre d'employés : ");
    scanf("%d", &nombreEmployes);
    printf("Nombre d'employés mis à jour : %d\n", nombreEmployes);
}


void displayStock() {
    printf("Le stock actuel est de %.2f unités.\n", stock);
}

void Ajoutunouvcharge() {
    float nouvelleCharge;
    printf("Entrez le montant de la nouvelle charge : ");
    scanf("%f", &nouvelleCharge);
    charges += nouvelleCharge;
    printf("Nouvelle charge de %.2f ajoutée. Total des charges : %.2f\n", nouvelleCharge, charges);
}


void Affichierbenfice() {
    float totalVentes = 0.0;
    for (int i = 0; i < nombreVentes; i++) {
        totalVentes += ventes[i].montant;
    }
    float benefice = totalVentes - charges;
    printf("Le bénéfice actuel est de %.2f\n", benefice);
}

void Affichiercharge() {
    printf("Les charges actuelles sont de %.2f\n", charges);
}


void Affichiermoinsventreachats() {
    float achats = stock * 10;
    printf("Moins de vente : %.2f\n", charges);
    printf("Moins d'achat : %.2f\n", achats);
}

void Affichierqauantiteproduitesachates() {
    printf("Quantité achetée : %.2f unités\n", stock);
}

void Affichierstitionenterpise() {
    printf("Situation de l'entreprise : bonne.\n");
}

void embaucherEmploye() {
    if (nombreEmployes < MAX_EMPLOYES) {
        printf("Entrez le nom de l'employé : ");
        scanf("%s", employes[nombreEmployes].nom);
        printf("Entrez l'âge de l'employé : ");
        scanf("%d", &employes[nombreEmployes].age);
        nombreEmployes++;
        printf("Employé %s ajouté.\n", employes[nombreEmployes-1].nom);
    } else {
        printf("Capacité maximale d'employés atteinte.\n");
    }
}


void afficherEmployes() {
    printf("Liste des employés :\n");
    for (int i = 0; i < nombreEmployes; i++) {
        printf("%d. %s, Âge : %d\n", i + 1, employes[i].nom, employes[i].age);
    }
}


void enregistrerVente() {
    if (nombreVentes < MAX_VENTES) {
        printf("Entrez le montant de la vente : ");
        scanf("%f", &ventes[nombreVentes].montant);
        nombreVentes++;
        printf("Vente enregistrée.\n");
    } else {
        printf("Capacité maximale de ventes atteinte.\n");
    }
}

void afficherVentes() {
    printf("Liste des ventes :\n");
    for (int i = 0; i < nombreVentes; i++) {
        printf("Vente %d : %.2f euros\n", i + 1, ventes[i].montant);
    }
}

void afficherBudget() {
    printf("Le budget actuel est de %.2f euros\n", budget);
}

int main() {
    int choice;

    do {
        printf("\nGestion d'entreprise\n");
        printf("1. Ajouter une nouvelle entreprise et ses informations\n");
        printf("2. Saisir ou changer le nombre d'emplois\n");
        printf("3. Afficher le stock\n");
        printf("4. Ajouter une nouvelle charge\n");
        printf("5. Afficher le bénéfice\n");
        printf("6. Afficher les charges\n");
        printf("7. Afficher les moins de vente et des achats\n");
        printf("8. Afficher la quantité produite ou achetée selon la nature des activités\n");
        printf("9. Afficher la situation de l'entreprise\n");
        printf("10. Embaucher un employé\n");
        printf("11. Afficher la liste des employés\n");
        printf("12. Enregistrer une vente\n");
        printf("13. Afficher les ventes\n");
        printf("14. Afficher le budget\n");
        printf("15. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Gestionentreprise();
                break;
            case 2:
                changenombreemploi();
                break;
            case 3:
                displayStock();
                break;
            case 4:
                Ajoutunouvcharge();
                break;
            case 5:
                Affichierbenfice();
                break;
            case 6:
                Affichiercharge();
                break;
            case 7:
                Affichiermoinsventreachats();
                break;
            case 8:
                Affichierqauantiteproduitesachates();
                break;
            case 9:
                Affichierstitionenterpise();
                break;
            case 10:
                embaucherEmploye();
                break;
            case 11:
                afficherEmployes();
                break;
            case 12:
                enregistrerVente();
                break;
            case 13:
                afficherVentes();
                break;
            case 14:
                afficherBudget();
                break;
            case 15:
                printf("Quitter le programme.\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice != 15);

    return 0;
}
