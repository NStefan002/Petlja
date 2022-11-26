#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int brSegmenata(vector<int>& a);

int main()
{
    int n;
    cin >> n;

    vector<int> niz(n);

    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }
    
    cout << brSegmenata(niz) << endl;

    return 0;
}

int brSegmenata(vector<int>& a)
{
    /* Vremenska slozenost ove funkcije je O(nlogm) [m - broj elemenata u mapi]
    ili priblizno O(n) (ovo je gruba ocena koju mozemo napraviti jer je vreme 
    pristupa elementu mape u najgorem slucaju logaritamsko a broj elemenata mape
    je uvek manji od n). */
    
    // pamtimo koji su brojevi u trenutnom segmentu vec vidjeni
    unordered_map<int, bool> vecVidjen;

    // validni brojevi su iz segmenta [l, b) 
    int l = 0, d = 1;
    vecVidjen[a[0]] = true;

    int brSegmenata = 0;
    while (d < a.size())
    {
        /* Ukoliko je broj sa indeksa d iz niza a vec vidjen u 
        tekucem segmentu, onda pomeramo l sve dok ne naidjemo na 
        broj koji e "pravio problem" */
        while (vecVidjen[a[d]])
        {
            vecVidjen[a[l++]] = false;
        }

        /* Broj segmenata uvecavamo za velicinu trenutnog segmenta */
        brSegmenata += d - l;

        /* Obelezimo element kojim smo prosirili prethodni segment
        kao vidjen. */
        vecVidjen[a[d++]] = true;
    }

    return brSegmenata;
}