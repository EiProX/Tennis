#ifndef GPIORpi2
#define GPIORpi2

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <fstream>

class Rpi2_EXP500_gpio
{
public :
    Rpi2_EXP500_gpio(const char* pNum);
    ~Rpi2_EXP500_gpio() ;
    void Ecrire(int Valeur);
    int Lire();
private :
    char* NumBroche;
    int IdKernel ;
    void Preparer_gpio_Ligne();
    void Definir_Direction(char* Direction);
};

#endif
