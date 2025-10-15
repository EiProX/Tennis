#ifndef THISTORIQUE_H
#define THISTORIQUE_H
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

class THistorique
{
private:
    char* NomFichier;

public:
    THistorique(char* apNomFichier);
    ~THistorique();
    int Ajouter (char *NumMembre);
    void AfficherFichierHistorique();
};

#endif // THISTORIQUE_H
