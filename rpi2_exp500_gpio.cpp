#include "rpi2_exp500_gpio.h"

using namespace std;

Rpi2_EXP500_gpio::Rpi2_EXP500_gpio(const char* pNum)
{
    int NbCases = strlen(pNum)+1;
    NumBroche = new char[NbCases];
    strcpy(NumBroche,pNum);
    printf("Valeur de NumBroche : %s\n",NumBroche);
    if(pNum[0] == 'L')
    {
        int Numero=atoi(NumBroche + 1) ;       //+1 pour enlever le L
        switch(Numero)
        {
        case 0 :
            IdKernel = 538;          //GPIO du Rpi correspondant
            break;
        case 1 :
            IdKernel = 524;          //GPIO du Rpi correspondant
            break;
        case 2 :
            IdKernel = 528;          //GPIO du Rpi correspondant
            break;
        case 3 :
            IdKernel = 532;          //GPIO du Rpi correspondant
            break;

        default :
            exit (1) ;
            break;
        }
    }
    if(pNum[0] == 'K')
    {
        int Numero=atoi(NumBroche + 1) ;       //+1 pour enlever le K
        switch(Numero)
        {
        case 0 :
            IdKernel = 517;          //GPIO du Rpi correspondant
            break;
        case 1 :
            IdKernel = 518;          //GPIO du Rpi correspondant
            break;

        default :
            exit (1) ;
            break;
        }
    }

    printf ("IdKernel=%d\n", IdKernel) ;

}

Rpi2_EXP500_gpio::~Rpi2_EXP500_gpio()
{
    FILE * pFic ;
    char gpio_value[35];

    sprintf(gpio_value, "/sys/class/gpio/gpio%s", NumBroche);

    if ((pFic=fopen(gpio_value,"r"))!=NULL)
    {
        fclose (pFic) ;
        if ((pFic = fopen("/sys/class/gpio/unexport","w")) == NULL)
        {
            printf("Cannot open unexport file : %s\n",NumBroche);
            exit(1);
        }
        rewind(pFic);
        fprintf(pFic,"%d",IdKernel);
        fclose(pFic);
    }
}


void Rpi2_EXP500_gpio::Ecrire(int Valeur)
{

    FILE *Fich;
    char gpio_value[35];

    Preparer_gpio_Ligne();
    Definir_Direction((char*) "out");

    // ECRIRE LA VALEUR
    sprintf(gpio_value, "/sys/class/gpio/gpio%d/value", IdKernel);
    if ((Fich = fopen(gpio_value, "rb+")) == NULL)
    {
        printf("Cannot open value file.\n");
        exit(1);
    }
    rewind(Fich);
    fprintf(Fich,"%d", Valeur);
    fclose(Fich);

    /*
    Preparer_gpio_Ligne();
    Definir_Direction((char*) "out");
    char gpio_value[35];
    sprintf(gpio_value, "/sys/class/gpio/gpio%d/value", IdKernel);
    ofstream Fich(gpio_value);
    if (Fich.is_open() == false)
    {
        cout << "Cannot open value file." << endl;
    }
    Fich << Valeur;
    Fich.close();
*/
}

int Rpi2_EXP500_gpio:: Lire()
{

    FILE *Fich;
    char gpio_value[35];
    char ValeurLue;

    Preparer_gpio_Ligne();
    Definir_Direction((char*) "in");
    usleep(200000);

    // RECUPERER Valeur
    sprintf(gpio_value, "/sys/class/gpio/gpio%d/value", IdKernel);
    if ((Fich = fopen(gpio_value, "rb")) == NULL)
    {
        printf("Cannot open value file.\n");
        exit(1);
    }
    fread(&ValeurLue, sizeof(char), 1, Fich);
    fclose(Fich);
    return ValeurLue-0x30; // pour oter code ascii
    /*
    char gpio_value[35];
    char ValeurLue;

    Preparer_gpio_Ligne();
    Definir_Direction((char*) "in");
    // RECUPERER Valeur
    sprintf(gpio_value, "/sys/class/gpio/gpio%d/value", IdKernel);
    ifstream Fich(gpio_value, ios::in);
    if (Fich.is_open() == false)
    {
        cout << "Cannot open value file." << endl;
    }
    else
    {
        Fich >> ValeurLue;
        Fich.close();
    }
    return ValeurLue-0x30; // pour oter code ascii
    */
}


void Rpi2_EXP500_gpio::Preparer_gpio_Ligne()
{

    FILE *Fich;
    // Préparer la broche utilisée
    if ((Fich = fopen("/sys/class/gpio/export","w")) == NULL)
    {
        printf("Cannot open export file : %s\n",NumBroche);
        exit(1);
    }
    rewind(Fich);
    fprintf(Fich,"%d",IdKernel);
    fclose(Fich);

    /*
    ofstream Fich("/sys/class/gpio/export", ios::out);
    if (Fich.is_open() == false)
    {
        cout << "Cannot open export file." << endl;
    }
    else
    {
        Fich <<IdKernel;
        Fich.close();
    }
    */
}

void Rpi2_EXP500_gpio::Definir_Direction(char* Direction) // IN ou OUT
{

    FILE * Fich;
    char gpio_direction[35];
    sprintf(gpio_direction, "/sys/class/gpio/gpio%d/direction", IdKernel);
    //printf("%s", gpio_direction);
    if ((Fich = fopen(gpio_direction, "rb+")) == NULL)
    {
        printf("Cannot open direction file.\n");
        exit(1);
    }
    rewind(Fich);
    fprintf(Fich, "%s", Direction);
    fclose(Fich);
    /*
    char gpio_direction[35];
    sprintf(gpio_direction, "/sys/class/gpio/gpio%d/direction", IdKernel);
    ofstream Fich(gpio_direction, ios::out);
    if (Fich.is_open() == false)
    {
        cout << "Cannot open direction file." << endl;
    }
    else
    {
        Fich << Direction;
        Fich.close();
    }
    */
}
