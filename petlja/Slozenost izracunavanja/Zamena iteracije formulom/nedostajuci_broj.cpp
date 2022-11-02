#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned n;
    cin >> n;
    unsigned broj;

    vector<bool> brojevi(n);

    for (unsigned i = 0; i < n; i++)
    {
        cin >> broj;
        brojevi[broj] = true;
    }
    
    /* for (unsigned i = 0; i < n; i++)
    {
        if (!brojevi[i])
        {
            cout << i << '\n';
            break;
        }
    } */
    auto itRez = find(begin(brojevi), end(brojevi), false);
    // ne mora da se proverava da li je f-ja find pronasla false ili ne 
    // posto je uslovom zadatka odredjeno da ce sigurno biti tacno jedan nedostajuci element
    cout << itRez - begin(brojevi) << '\n';
    // ucitavanje brojeva je u slozenosti O(n) i find je takodje linearne slozenosti,
    // pa je slozenost celokupnog resenja O(n)

    /* 
        Alternativno resenje (takodje slozenosti O(n)):
            1) prilikom ucitavanja formirati sumu svih ucitanih brojeva (slozenost O(n))
            2) od zbira prvih n elemenata aritmetickog niza oduzeti pomenutu sumu,
            i ta razlika predstavlja konacno resenje (moraju se koristiti tipovi
            veci od unsigned jer se pojavljuje x^2 sto moze dovesti do prekoracenja) 
     */

    return 0;
}