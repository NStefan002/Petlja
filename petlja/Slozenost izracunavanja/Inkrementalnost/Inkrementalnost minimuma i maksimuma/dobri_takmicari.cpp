#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> takmicari(n);

    for (int i = 0; i < n; i++)
    {
        cin >> takmicari[i].first >> takmicari[i].second;
    }
    
    /*
    Ne prolazi za vece ulaze, slozenost je kvadratna iako je bolji od algoritma grube sile.
    int brDobrih = 0;
    for (int i = 0; i < n; i++)
    {
        bool jesteDobar = true;
        for (int j = 0; j < n; j++)
        {
            if (takmicari[i].first < takmicari[j].first && takmicari[i].second < takmicari[j].second)
            {
                jesteDobar = false;
                break;
            }            
        }
        if (jesteDobar)
        {
            brDobrih++;
        }
    } 
    */


    // Bolje resenje se dobija sortiranjem [slozenost O(nlogn)], a zatim primenjivanjem inkrementalnosti maximuma
    sort(begin(takmicari), end(takmicari), // O(nlogn)
        [](auto& e1, auto& e2)
        {
            return (e1.first > e2.first) || (e1.first == e2.first && e1.second < e2.second);
        });

    /* Niz sortiramo nerastuce po rezultatima iz programiranja (first u parovima rezultata),
    a u slucaju da su rezultati iz programiranja dva takmicara jednaki, sortiramo takmicare neopadajuce
    po rezultatima iz matematike (second u parovima rezultata). Ovim dobijamo sledece:
        - za svakog takmicara je dovoljno da proverimo da li njegov rezultat iz matematike veci od
        trenutnog maksimuma (njega inkrementalno racunamo dok prolazimo kroz niz takmicara) 
        - nije potrebno proveravati u kakvom su odnosu rezultati iz programiranja trenutnog takmicara
        sa rezultatima ostalih takmicara, jer znamo da su svi takmicari koji prethode trenutnom takmicaru
        osvojili vise ili podjednak broj bodova (zato sto je niz sortiran neopadajuce po rezultatima iz programiranja)
    */
    
    int brDobrih = 0;
    int tekuciMaxProg = 0;
    for (int i = 0; i < n; i++)
    {
        tekuciMaxProg = max(tekuciMaxProg, takmicari[i].second);
        if (takmicari[i].second >= tekuciMaxProg)
        {
            brDobrih++;
        }
    }
    
    cout << brDobrih << endl;

    return 0;
}