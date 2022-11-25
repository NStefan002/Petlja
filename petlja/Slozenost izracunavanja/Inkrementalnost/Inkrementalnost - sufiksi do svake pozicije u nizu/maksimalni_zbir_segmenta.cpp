#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int i = 0;
    int maxZbir = 0;

    /* Dovoljan je jedan prolazak kroz sve ucitane brojeve, pa nema potrebe cuvati
    ih u nizu. Trenutni zbir je zbir elemenata iz segmenta [i, j]. Ukoliko je trenutni
    zbir manji od nule, nema potrebe proveravati da li postoji maksimalan u segmentu koji 
    se dobija pomeranjem j u desno (jer izbacivanjem prefiksne sume koja je negativna dobijamo
    veci zbir). U tom slucaju i pomeramo na poziciju iza j i pocinjemo sa ispitivanjem novog
    segmenta. */

    while (i < n)
    {
        int trZbir = 0;
        int j = i;
        while (j < n)
        {
            int broj;
            cin >> broj;
            trZbir += broj;
            if (trZbir < 0)
            {
                break;
            }

            maxZbir = max(maxZbir, trZbir);
            j++;
        }
        
        i = j + 1;
    }
    
    cout << maxZbir << endl;

    return 0;
}