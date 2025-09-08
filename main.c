#include <string.h>
#include <stdio.h>

//step 1

#define max_contact 100
#define max_nom 50
#define max_tel 20
#define max_email 50


typedef struct {
    char nom[max_nom];
    char tel[max_tel];
    char email[max_email];
} Contact;

Contact contacts[max_contact];
int compte = 0;

//step 2
void afficheMenu() {

    printf("1. Ajouter un contact\n");
    printf("2. Afficher la liste de contacts\n");
    printf("3. Rechercher un contact\n");
    printf("4. Modifier un contact\n");
    printf("5. Supprimer un contact\n");
    printf("6. Quitter le programme \n");
    printf("Veuillez entrer un choix : ");
}

//step 3
void ajouter() {
    if (compte < max_contact) {
        printf("Entre un nom : ");
        scanf("%s", contacts[compte].nom);
        do {
    printf("Entrer un nombre de tel: ");
    scanf("%s", contacts[compte].tel);
} while ((contacts[compte].tel[0] != '0') || (contacts[compte].tel[1] != '5') &&
          (contacts[compte].tel[1] != '6') &&
          (contacts[compte].tel[1] != '7') ||
         (strlen(contacts[compte].tel) != 10));
	  printf("Entre adress de email: ");
        scanf("%s", contacts[compte].email);

        compte++;
        printf("Le contact ajoute avec succes.\n");
}


	else {

        printf("La liste de contacts est pleine.\n");
    }
}

// step 4
void afficheliste() {
    if (compte == 0) {
        printf("pas contacts dans la liste.\n");
        return;
    }
    printf("Liste des contacts :\n");

    for (int i = 0; i < compte; i++) {
        printf("Nom: %s\n", contacts[i].nom);
        printf("Tel: %s\n", contacts[i].tel);
        printf("Email: %s\n", contacts[i].email);

    }
}

//step 5

void recherche() {
    char nomrech[max_nom];
    printf("Veuillez entrer le nom pour rechercher: ");
    scanf("%s", nomrech);

    int found = 0;
    for (int i = 0; i < compte; i++) {
        if (strcmp(contacts[i].nom, nomrech) == 0) {
            printf("Contact trouve!\n");
            printf("Nom: %s\n", contacts[i].nom);
            printf("Tel: %s\n", contacts[i].tel);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Le contact n'a pas ete trouve.\n");
    }
}

// step 6
void modifier() {
    char nomod[max_nom];
    printf("Veuillez entrer le nom de contact pour modifier : ");
    scanf("%s", nomod);

    int found = 0;
    for (int i = 0; i < compte; i++) {
        if (strcmp(contacts[i].nom, nomod) == 0) {
            printf("Contact trouve! Entrez les nouveau informations.\n");
            printf("Nouveau nombre de tel: ");
            scanf("%s", contacts[i].tel);
            printf("Nouveau adresse email: ");
            scanf("%s", contacts[i].email);

            printf("Le contact modifie avec succes.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Le contact ne est pas trouve.\n");
    }
}

//step 7

    void supprime() {
    char nomsup[max_nom];
    printf("Veuillez entrer le nom de contact pour supprimer: ");
    scanf("%s", nomsup);

    int found = 0;
    for (int i = 0; i < compte; i++) {
        if (strcmp(nomsup, contacts[i].nom) == 0) {

            for (int j = i; j < compte - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            compte--;
            found = 1;
            printf("Le contact supprime avec succes.\n");
            break;
        }
    }

    if (found == 0) {
        printf("Le contact ne pas trouve.\n");
    }
}


//step 8
int main() {
    int choix;
    do {
        afficheMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                afficheliste();
                break;
            case 3:
                recherche();
                break;
            case 4:
                modifier();
                break;
            case 5:
                supprime();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Veuillez entrer un choix valide.\n");
        }
    } while (choix != 6);

    return 0;
}
