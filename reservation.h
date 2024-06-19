#ifndef RESERVATION_H
#define RESERVATION_H

typedef struct {
    char nom[MAX_LONGUEUR_NOM];
    int numeroSiege;
} Billet;

void reserverSiege();
void genererBillet();

#endif // RESERVATION_H
