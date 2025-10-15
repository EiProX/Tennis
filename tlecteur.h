#ifndef TLECTEUR_H
#define TLECTEUR_H
#include "trs232.h"
using namespace std;


class tLecteur
{
    private:
        tRs232 PortSerie;
        void LireTrame(char* Trame);

    public:
        void LireNumero(char* Num);

};

#endif // TLECTEUR_H
