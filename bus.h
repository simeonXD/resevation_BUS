#ifndef BUS_H
#define BUS_H

#define MAX_SIEGES 40
#define MAX_PASSAGERS 100
#define MAX_LONGUEUR_NOM 50
#define MAX_OPERATEURS_MOBILE 3
#define MAX_DESTINATIONS 7

typedef struct {
    int numeroSiege;
    char nom[MAX_LONGUEUR_NOM];
    char postNom[MAX_LONGUEUR_NOM];
    char contact[MAX_LONGUEUR_NOM];
    char destination[MAX_LONGUEUR_NOM];
    int prix;
} Passager;

typedef struct {
    Passager passagers[MAX_PASSAGERS];
    int totalPassagers;
} Bus;

extern Bus bus;
extern const char* destinations[MAX_DESTINATIONS];
extern const int prixDestinations[MAX_DESTINATIONS];

void initialiserBus();
void afficherSiegesDisponibles();
void clearScreen();
void centerText(const char* text);
void rechercherPassager();

#endif // BUS_H

