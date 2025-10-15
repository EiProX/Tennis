#include "tmateriel.h"

tMateriel::tMateriel(const char* led, const char* porte, const char* lumiere)
{
    m_led = new Rpi2_EXP500_gpio(led);
    m_porte = new Rpi2_EXP500_gpio(porte);
    m_lumiere =new Rpi2_EXP500_gpio(lumiere);

}

tMateriel::~tMateriel()
{
    delete m_led;
    delete m_porte;
    delete m_lumiere;
}


void tMateriel::AllumerLed()
{
    m_led->Ecrire(1);
}

void tMateriel::EteindreLed()
{
    m_led->Ecrire(0);
}

void tMateriel::DebloquerPorte(){
    m_porte->Ecrire(1);
    sleep(5);
    m_porte->Ecrire(0);
}

void tMateriel::AllumerLumiere(){
    m_lumiere->Ecrire(1);
}

void tMateriel::EteindreLumiere(){
    m_lumiere->Ecrire(0);
}
