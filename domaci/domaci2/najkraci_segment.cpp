#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

/* Vremenska slozenost: O(nlogn) 
   Prostorna slozenost: O(n)*/
   
int main()
{
    int n, z;
    cin >> n >> z;

    int minDuzinaSegmenta = n;
    int pocetakNajkracegSegmenta = 0;

    /* Pravimo mapu koja za kljuceve ima vrednosti prefiksnih suma za i-tu poziciju.
    Vrednost koja stoji uz kljuc mape je pozicija u unetom nizu kojoj suma koja se nalazi
    u kljucu prethodi. Odmah znamo da cemo imati jednu prefiksnu sumu kojoj je vrednost 0
    (ona prethodi prvom elementu niza). */

    // vrednost : krajnja pozicija
    map<int, int> prefiksneSume;
    prefiksneSume[0] = 0;
    
    /* Unosimo elemente niza (nema potrebe da ga cuvamo u memoriji) i inkrementalno racunamo
    sumu unetih elemenata. U svakoj iteraciji proveravamo da li medju do sada unetim prefiksnim sumama
    postoji "parnjak" trenutne sume (tj. da li je razlika trenutne sume i "parnjaka" jednaka vrednosti z).
    Ukoliko postoji azuriramo minimalnu duzinu segmenta i pocetak najraceg segmenta. Duzina trenutnog segmenta
    je broj elemenata izmedju pozicije kojoj prethodi "parnjak" suma i i. */
    
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;

        suma += br;

        auto it = prefiksneSume.find(suma - z);
        if (it != prefiksneSume.end())
        {
            if (minDuzinaSegmenta > i - it->second + 1)
            {
                minDuzinaSegmenta = i - it->second + 1;
                pocetakNajkracegSegmenta = it->second;
            }
        }

        prefiksneSume[suma] = i + 1;
    }

    cout << pocetakNajkracegSegmenta << ' ' << pocetakNajkracegSegmenta + minDuzinaSegmenta - 1 << endl;

    return 0;
}