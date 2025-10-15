#include "tlecteur.h"

void tLecteur::LireTrame(char *Trame){
    PortSerie.Recevoir('\r', Trame, SANS_FINAL);
}

void tLecteur::LireNumero(char* Num)
{
    char Trame[100];
    LireTrame(Trame);
    strcpy(Num, Trame);
}
