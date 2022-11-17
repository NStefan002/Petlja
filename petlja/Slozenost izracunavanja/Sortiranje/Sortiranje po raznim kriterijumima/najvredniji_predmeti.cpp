/* Deluje da postoji neka greska u test primerima */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;


struct Predmet
{
    string sifra;
    double cena;

    // da bi f-ja sort znala kako da sortira nas niz
    bool operator<(Predmet p)
    {
        if (cena < p.cena)
        {
            return true;
        }
        else
        {
            return false;
        }
        /* Tekst zadatka garantuje da cene nece biti iste */
    } 
};


int main()
{
    double budzet;
    int brPredmeta;
    cin >> budzet >> brPredmeta;

    vector<Predmet> predmeti(brPredmeta);

    for (int i = 0; i < brPredmeta; i++)
    {
        cin >> predmeti[i].sifra >> predmeti[i].cena;
    }

    sort(begin(predmeti), end(predmeti));
    
    for (int i = brPredmeta - 1; i >= 0; i--)
    {
        if (budzet >= predmeti[i].cena)
        {
            budzet -= predmeti[i].cena;
            cout << fixed << setprecision(2) << showpoint << predmeti[i].sifra << ' ' << predmeti[i].cena << '\n';
        }
    }
    
    if (budzet > 0)
    {
        cout << fixed << setprecision(2) << showpoint << budzet << endl;
    }

    return 0;
}