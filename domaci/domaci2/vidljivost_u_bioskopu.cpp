#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

/* Vremenska slozenost: O(nlogk) 
   Prostorna slozenost: O(n + k)*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    /* Posebno ucitavamo visinu prve osobe jer znamo
    da ce ona sigurno videti platno. */
    vector<int> visine(n);
    cin >> visine[0];
    cout << "0 ";
    multiset<int> kRedovaIspred;
    kRedovaIspred.insert(visine[0]);
    
    /* U svakoj iteraciji ucitavamo visinu nove osobe i uklanjamo
    visinu osobe koja je k redova ispred trenutne (ukoliko takva osoba postoji).
    Osobu uklanjamo preko iteratora koji vrati metoda find() [ukoliko metodi erase()
    prosledimo vrednost kljuca ona ce ukloniti sve elemente sa tim kljucem (sto ne
    zelimo), a ukoliko joj prosledimo iterator ona ce ukloniti samo taj jedan element].
    Slozenost ovakvog postupka je O(logk) za pronalazenje elementa sa datom vrednosti i
    konstantna za uklanjanje elementa na koji pokazuje iterator, sto je ukupno O(logk).
    Trenutnu visinu uporedjujemo sa poslednjim elementom multiskupa jer je multiskup 
    uredjen neopadajuce (samim tim se na poslednjem mestu nalazi najveci element) i 
    ukoliko je trenutna visina manja to znaci da ta osoba ne moze da vidi platno. Nakon 
    izvrsenih provera tekucu visinu dodajemo u multiskup. Koristimo multiskup, a ne skup 
    bas zbog mogucnosti da postoje dve osobe sa istom visinom i ako uklonimo jednu takvu 
    visinu, uklonice se i sve ostale sto moze dovesti do pogresnog resenja. */

    for (int i = 1; i < n; i++)
    {
        cin >> visine[i];
        if (kRedovaIspred.size() > k)
        {
            // da bi uklonili samo jedan element
            kRedovaIspred.erase(kRedovaIspred.find(visine[i - k - 1]));
        }
        
        if (visine[i] <= *kRedovaIspred.rbegin())
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }

        kRedovaIspred.insert(visine[i]);
    }
    
    cout << endl;

    return 0;
}