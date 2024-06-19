#include <stdio.h>
#include <string.h>
#include "bus.h"
#include "reservation.h"

void reserverSiege() {
    if (bus.totalPassagers >= MAX_SIEGES) {
        printf("Pas de sieges disponibles !\n");
        return;
    }

    char nom[MAX_LONGUEUR_NOM];
    char postNom[MAX_LONGUEUR_NOM];
    char contact[MAX_LONGUEUR_NOM];
    int numeroSiege;
    int choixDestination;

    printf("Entrez votre nom : ");
    scanf("%s", nom);
    printf("Entrez votre post-nom : ");
    scanf("%s", postNom);
    printf("Entrez votre contact : ");
    scanf("%s", contact);
    afficherSiegesDisponibles();
    printf("Entrez le numero de siege : ");
    scanf("%d", &numeroSiege);

    if (numeroSiege < 1 || numeroSiege > MAX_SIEGES) {
        printf("Numero de siege invalide !\n");
        return;
    }

    for (int i = 0; i < bus.totalPassagers; i++) {
        if (bus.passagers[i].numeroSiege == numeroSiege) {
            printf("Siege deja reserve !\n");
            return;
        }
    }

    printf("Choisissez votre destination :\n");
    for (int i = 0; i < MAX_DESTINATIONS; i++) {
        printf("%d. %s - %d USD\n", i + 1, destinations[i], prixDestinations[i]);
    }
    printf("Entrez votre choix : ");
    scanf("%d", &choixDestination);

    if (choixDestination < 1 || choixDestination > MAX_DESTINATIONS) {
        printf("Choix de destination invalide !\n");
        return;
    }

    strcpy(bus.passagers[bus.totalPassagers].nom, nom);
    strcpy(bus.passagers[bus.totalPassagers].postNom, postNom);
    strcpy(bus.passagers[bus.totalPassagers].contact, contact);
    strcpy(bus.passagers[bus.totalPassagers].destination, destinations[choixDestination - 1]);
    bus.passagers[bus.totalPassagers].numeroSiege = numeroSiege;
    bus.passagers[bus.totalPassagers].prix = prixDestinations[choixDestination - 1];
    bus.totalPassagers++;

    printf("Siege reserve avec succes pour la destination %s !\n", destinations[choixDestination - 1]);
}

void genererBillet() {
    if (bus.totalPassagers == 0) {
        printf("Aucune reservation pour generer un billet !\n");
        return;
    }

    Billet billet;
    strcpy(billet.nom, bus.passagers[bus.totalPassagers - 1].nom);
    billet.numeroSiege = bus.passagers[bus.totalPassagers - 1].numeroSiege;

    printf("Billet genere avec succes !\n");
    printf("Nom du passager : %s\n", billet.nom);
    printf("Numero de siege : %d\n", billet.numeroSiege);
}
