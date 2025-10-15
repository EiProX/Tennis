#include <iostream>
#include "rpi2_exp500_gpio.h"
using namespace std;

class tMateriel {
private:
    Rpi2_EXP500_gpio* m_led;
    Rpi2_EXP500_gpio* m_porte;
    Rpi2_EXP500_gpio* m_lumiere;

public:

    tMateriel(const char* led = "L0", const char* porte = "L1", const char* lumiere = "L2");
    ~tMateriel();

    void AllumerLed();
    void EteindreLed();

    void DebloquerPorte();

    void AllumerLumiere();
    void EteindreLumiere();
};
