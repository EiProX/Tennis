#include "tgestion.h"
#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

tGestion::tGestion(const char* fichierComptes, const char* fichierHistorique)
{
    cout << "Initialisation du système..." << endl;

    m_materiel   = new tMateriel("L0", "L1", "L2");
    m_comptes    = new tComptesMembres((char*)fichierComptes);
    m_historique = new THistorique((char*)fichierHistorique);
    m_lecteur    = new tLecteur();
    m_rs232      = new tRs232();

    cout << "Composants initialisés." << endl;
}

tGestion::~tGestion()
{
    delete m_materiel;
    delete m_comptes;
    delete m_historique;
    delete m_lecteur;
    delete m_rs232;
}



void tGestion::Tempo(int secondes)
{
    sleep(secondes);
}

void tGestion::run()
{
    cout << "Système prêt. En attente de carte..." << endl;

    while (true)
    {
        char numero[50] = {0};
        int codeSecret = 0;
        int verif =0;
        sMembre lu{};

        int indexALire = 0;
        cout << "Lecture de l’enregistrement d’index " << indexALire << "..." << endl;
        if (m_comptes->lire_membre(indexALire, &lu))
         {
            cout << "Lecture réussie :" << endl;
            cout << "  Numéro : " << lu.numero << endl;
            cout << "  Code   : " << lu.code << endl;
            cout << "  Nom    : " << lu.nom << endl;
        }
        else
        {
            cout << "Erreur : impossible de lire l’enregistrement " << indexALire << endl;
        }
        cout << endl;
        // Lecture carte
        m_lecteur->LireNumero(numero);
        cout << "Carte détectée : " << numero << endl;

        // Lecture code secret
        cout << "Entrez le code : ";
        cin >> codeSecret;
        cout << codeSecret << " : Code rentré"<<endl;


        verif = m_comptes->verifier(numero, codeSecret);
        cout <<"Verifier = "<< verif<<endl;
        // Vérification
        if (verif == 1)
        {
            cout << "Accès autorisé." << endl;
            m_materiel->DebloquerPorte();
            m_materiel->AllumerLumiere();
            Tempo(1);
            m_materiel->EteindreLumiere();
            m_historique->Ajouter(numero);
        }
        else
        {
            cout << "Accès refusé." << endl;
            m_materiel->AllumerLed();
            Tempo(1);
            m_materiel->EteindreLed();
        }

        cout << "En attente d’un nouveau passage..." << endl;
        Tempo(2);
    }
}
