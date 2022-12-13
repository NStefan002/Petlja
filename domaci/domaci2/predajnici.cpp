#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/* Vremenska slozenost: O(nlogn) 
   Prostorna slozenost: O(n)*/

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> tacke(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tacke[i];
    }
    
    sort(begin(tacke), end(tacke));

    /* Kroz niz prolazimo sa dva pokazivaca koji predstavljaju pozicije 
    predajnika. Posto trazeno rastojanje treba da bude manje ili jednako d,
    imamo sledeca tri slucaja:
        - ako je trenutno rastojanje strogo manje od d, onda azuriramo maksimalno 
        rastojanje i pomeramo desni predajnik za jednu poziciju u desno (povecavamo 
        rastojanje da bismo je u narednoj iteraciji ponovo ispitali)
        - ako je trenutno rastojanje strogo vece od d, pomeramo levi predajnik
        za jednu poziciju u desno (da bismo smanjili rastojanje) i ne azuriramo 
        maksimalno rastojanje jer vrednost trenutnog rastojanja nije validna
        - ako je trenutno rastojanje jednako d, nema potrebe da dalje proveravamo
        jer je to sigurno i najvece moguce rastojanje, azuriramo maksimalno rastojanje
        i izlazimo iz petlje  */
    int levi = 0, desni = 1;
    int maxRastojanje = 0;
    
    while (desni < n)
    {
        int tekRastojanje = tacke[desni] - tacke[levi];
        if (tekRastojanje < d)
        {
            maxRastojanje = max(maxRastojanje, tekRastojanje);
            desni++;
        }
        else if (tekRastojanje > d)
        {
            levi++;
        }
        else // if(tekRastojanje == d)
        {
            maxRastojanje = d;
            break;
        }
    }

    cout << maxRastojanje << endl;

    return 0;
}