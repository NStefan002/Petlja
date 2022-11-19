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

    vector<int64_t> udaljenostKuca(n);
    for (int i = 0; i < n; i++)
    {
        cin >> udaljenostKuca[i];
    }
    
    sort(begin(udaljenostKuca), end(udaljenostKuca));

    /* [Zakomentarisani deo koda ce dati isto resenje kao i pravi kod]
       Algoritam koji pronalazi minimalno ukupno rastojanje je efikasniji
       od brute force algoritma (linearne je slozenosti, za razliku od BF koji
       bi verovatno bio kvadratne). Koristi inkrementalnost da ne bi svaki put
       morao da racuna rastojanje iz pocetka. Medjutim i ovo moze da se izbegne
       ako zakljucimo da ce rastojanje biti minimalno kada broj kuca na levoj
       i na desnoj strani od dalekovoda bude jednak (odnosno u slucaju da je broj
       kuca paran, broj kuca levo i desno treba da se razlikuje za 1).

       
    int64_t pozicijaDalekovoda = udaljenostKuca[0];
    int64_t rastojanje = 0;
    
    for (int i = 0; i < n; i++)
    {
        rastojanje += abs(udaljenostKuca[i] - pozicijaDalekovoda);
    }
    pozicijaDalekovoda++;
    
    int64_t minRastojanje = rastojanje;
    int brKucaLevo = 1, brKucaDesno = n - 1; 

    int i = 1;
    while (i < n)
    {
        if (udaljenostKuca[i] == pozicijaDalekovoda - 1)
        {
            brKucaLevo++;
            brKucaDesno--;
            i++;
        }
        rastojanje += brKucaLevo - brKucaDesno; 
        minRastojanje = min(minRastojanje, rastojanje);

        pozicijaDalekovoda++;
    }
     */
    int64_t pozicijaDalekovoda = udaljenostKuca[(n - 1) / 2];
    
    int64_t minRazdaljina = 0;
    for (int i = 0; i < n; i++)
    {
        minRazdaljina += abs(udaljenostKuca[i] - pozicijaDalekovoda);
    }
    
    cout << minRazdaljina;

    return 0;
}