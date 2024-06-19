#include <stdio.h>
#include "bus.h"
#include "payement.h"

int demanderMontant(int montant) {
    int montantInsere;

    while (1) {
        printf("Veuillez inserer un montant de %d USD : ", montant);
        scanf("%d", &montantInsere);

        if (montantInsere >= montant) {
            printf("Montant suffisant.\n");
            return 1;
        } else {
            printf("Montant insuffisant ! Veuillez reessayer.\n");
        }
    }
}

void paiement() {
    if (bus.totalPassagers == 0) {
        printf("Aucune reservation pour effectuer un paiement !\n");
        return;
    }

    Passager dernierPassager = bus.passagers[bus.totalPassagers - 1];
    int montant = dernierPassager.prix;

    if (!demanderMontant(montant)) {
        return; // Abandonner si le paiement échoue
    }

    char operateurs[MAX_OPERATEURS_MOBILE][MAX_LONGUEUR_NOM] = {"Operateur1", "Operateur2", "Operateur3"};
    int choixOperateur;

    printf("Choisissez un operateur de mobile money :\n");
    for (int i = 0; i < MAX_OPERATEURS_MOBILE; i++) {
        printf("%d. %s\n", i + 1, operateurs[i]);
    }
    printf("Entrez votre choix : ");
    scanf("%d", &choixOperateur);

    if (choixOperateur < 1 || choixOperateur > MAX_OPERATEURS_MOBILE) {
        printf("Choix invalide !\n");
        return;
    }

    // Placeholder for mobile money payment integration
    printf("Paiement de %d USD en cours avec %s ...\n", montant, operateurs[choixOperateur - 1]);
    // Simulate payment process
    printf("Paiement reussi de %d USD avec %s !\n", montant, operateurs[choixOperateur - 1]);
}

