#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bus.h"

Bus bus;
const char* destinations[MAX_DESTINATIONS] = {"Likasi", "Lubumbashi", "Kolwezi", "Fungurume", "Tanzani", "Kasumbalesa", "Dilolo"};
const int prixDestinations[MAX_DESTINATIONS] = {10, 5, 15, 13, 25, 14, 20};

void initialiserBus() {
    bus.totalPassagers = 0;
    for (int i = 0; i < MAX_PASSAGERS; i++) {
        bus.passagers[i].numeroSiege = 0;
    }
}

void afficherSiegesDisponibles() {
    printf("Sieges disponibles : ");
    for (int i = 1; i <= MAX_SIEGES; i++) {
        int reserve = 0;
        for (int j = 0; j < bus.totalPassagers; j++) {
            if (bus.passagers[j].numeroSiege == i) {
                reserve = 1;
                break;
            }
        }
        if (!reserve) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void centerText(const char* text) {
    int len = strlen(text);
    int pos = (80 - len) / 2;
    for (int i = 0; i < pos; i++) {
        printf(" ");
    }
    printf("%s\n", text);
}

void rechercherPassager() {
    char nomRecherche[MAX_LONGUEUR_NOM];
    printf("Entrez le nom, post-nom, contact ou destination du passager a rechercher : ");
    scanf("%s", nomRecherche);

    for (int i = 0; i < bus.totalPassagers; i++) {
        if (strcmp(bus.passagers[i].nom, nomRecherche) == 0 ||
            strcmp(bus.passagers[i].postNom, nomRecherche) == 0 ||
            strcmp(bus.passagers[i].contact, nomRecherche) == 0 ||
            strcmp(bus.passagers[i].destination, nomRecherche) == 0) {
            printf("Passager trouve !\n");
            printf("Nom : %s, Post-nom : %s, Contact : %s, Destination : %s, Numero de siege : %d, Prix : %d USD\n",
                bus.passagers[i].nom, bus.passagers[i].postNom, bus.passagers[i].contact, bus.passagers[i].destination, bus.passagers[i].numeroSiege, bus.passagers[i].prix);
            return;
        }
    }

    printf("Passager non trouve !\n");
}

