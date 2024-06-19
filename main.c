#include <stdio.h>
#include <stdlib.h>
#include "bus.h"
#include "reservation.h"
#include "payement.h"

int main() {
    int choix;

    initialiserBus();

    while (1) {
        clearScreen();
        printf("\n\n\n\n\n\n");
        centerText("+----------------------------------------------------------+");
        centerText("|      Systeme de Reservation de Bus par Mobile Money      |");
        centerText("+----------------------------------------------------------+");
        printf("\n");
        centerText("|                1. Reserver un siege                      |");
        centerText("|                2. Effectuer un paiement                  |");
        centerText("|                3. Generer un billet                      |");
        centerText("|                4. Rechercher un passager                 |");
        centerText("|                5. Quitter                                |");
        centerText("+----------------------------------------------------------+");
        printf("\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                reserverSiege();
                break;
            case 2:
                paiement();
                break;
            case 3:
                genererBillet();
                break;
            case 4:
                rechercherPassager();
                break;
            case 5:
                printf("Merci d'avoir utilise le systeme de reservation de bus. Au revoir !\n");
                exit(0);
                break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }

        printf("Appuyez sur une touche pour continuer...\n");
        fflush(stdin);
        getch();
    }

    return 0;
}
