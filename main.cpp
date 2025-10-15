#include "tgestion.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "=== Test tGestion (run sequence) ===" << endl;
    tGestion gestion("comptes.txt", "historique.txt");
    gestion.run();
    cout << "=== Fin ===" << endl;
    return 0;
}
