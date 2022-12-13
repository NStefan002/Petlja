#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Vremenska slozenost: linearna (preciznije: O(n) + O(d - m), gde je n broj segmenata 
podmornice, d trazena dubina, a m najmanja visina segmenta)
   Prostorna slozenost: O(n) */

int main()
{
    int n, p;
    cin >> n >> p;

    vector<int> visine(n);
    for (int i = 0; i < n; i++)
    {
        cin >> visine[i];
    }
    
    /* Sortiramo niz visina segmenata rastuce. Time omogucavamo da svaki
    put kada povecamo dubinu, mozemo inkrementalno da izracunamo pritisak. */
    sort(begin(visine), end(visine));

    /* Dubinu inicijalizujemo na visinu najmanjeg segmenta podmornice (ukoliko
    je dubina manja od visine najmanjeg stepena, pritisak ce biti nula).
    U svakoj iteraciji uvecavamo dubinu, azuriramo broj potopljenih segmenata (ukoliko
    je visina segmenta manja od dubine to znaci da je segment potopljen) i uvecavamo
    pritisak za broj potopljenih segmenata (ukoliko se dubina poveca za 1, pritisak
    ce se povecati za broj potopljenih segmenata). Postupak ponavljamo dok ne dobijemo
    pritisak koji je veci jednak maksimalnom pritisku koji podmornica moze da podnese.
    Ukoliko smo dobili pritisak strogo veci od maksimalnog, to znaci da je prethodna
    dubina bila bas ona odgovarajuca. */
    int pritisak = 0;
    int dubina = visine[0];

    int brPotopljenih = 0;
    while (pritisak < p)
    {
        dubina++;
        while (brPotopljenih < n && dubina > visine[brPotopljenih])
        {
            brPotopljenih++;
        }
        
        pritisak += brPotopljenih;
    }
    
    cout << ((pritisak > p)? dubina - 1 : dubina) << endl;

    return 0;
}