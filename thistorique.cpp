#include "thistorique.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <ctime>

THistorique::THistorique(char* apNomFichier)
{
    NomFichier = new char[strlen(apNomFichier) + 1];
    strcpy(NomFichier, apNomFichier);
}

THistorique::~THistorique()
{
    delete[] NomFichier;
}

int THistorique::Ajouter(char *NumMembre){
    struct tm *MaDate;
    time_t temps;
    time(&temps);
    MaDate = localtime( &temps );

    ofstream Fichier(NomFichier, ios::app);
    if(Fichier.good()){
        Fichier << MaDate->tm_mday << "/" << MaDate->tm_mon << "/" << MaDate->tm_year+1900
                << " " << MaDate->tm_hour << ":" << MaDate->tm_min << ":" << MaDate->tm_sec
                << " " << NumMembre << endl;
    } else {
        cerr << "ERREUR impossible d'ecrire dans le fichier" << endl;
        exit(1);
    }
    Fichier.close();
    return 0;
}

void THistorique::AfficherFichierHistorique(){
    ifstream Fichier(NomFichier);
    cout << "----- Contenu de " << NomFichier << " -----" << endl;
    string ligne;
    while(getline(Fichier, ligne)) {
        cout << ligne << endl;
    }
    Fichier.close();
}
