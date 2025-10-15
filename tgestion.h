#ifndef TGESTION_H
#define TGESTION_H

#include "rpi2_exp500_gpio.h"
#include "tcomptesmembres.h"
#include "thistorique.h"
#include "tlecteur.h"
#include "tmateriel.h"
#include "trs232.h"

using namespace std;

class tGestion
{
private:
    tMateriel*        m_materiel;
    tComptesMembres*  m_comptes;
    THistorique*      m_historique;
    tLecteur*         m_lecteur;
    tRs232*           m_rs232;

    void Tempo(int secondes = 1);

public:
    tGestion(const char* fichierComptes, const char* fichierHistorique);
    ~tGestion();
    void run();
};

#endif // TGESTION_H
