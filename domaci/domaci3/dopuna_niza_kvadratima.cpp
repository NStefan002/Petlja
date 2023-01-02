#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

bool generisi(vector<int> &niz, int i, int m);
int sledeciKandidat(vector<int> &niz, int i, int m);
bool potpuniKvadrat(int x);
bool pravilnoPopunjen(vector<int> &v);
void ispisi(vector<int> &v);

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    if (generisi(niz, 1, m))
    {
        ispisi(niz);
    }
    else 
    {
        cout << "-1" << endl;
    }

    return 0;
}

bool generisi(vector<int> &niz, int i, int m)
{
    /* Funkcija generise samo leksikografski najmanje resenje, ne sva.

    Ukoliko je polje popunjeno, preskacemo ga i pokusavamo da popunimo
    naredno polje. U petlji isprobavamo sve moguce brojeve manje ili jednake od m koji
    ispunjavaju uslov dat u tekstu zadatka. Ako polje nije moguce ispravno 
    popuniti, funkcija vraca false.
     
    Kada stignemo do poslednjeg elementa, proveravamo da li je niz ispravno popunjen 
    i vracamo informaciju o tome (tu proveru vrsimo jer smo u rekurzivnim pozivima preskakali
    sva popunjena polja, a moze da se desi da su npr. na pocetku sva bila popunjena i to tako
    da uslov zadatka nije ispunjen). */
    
    // izlaz iz rekurzije
    if (i == niz.size() - 1)
    {
        return pravilnoPopunjen(niz);
    }
    
    // preskacemo popunjeno polje
    if (niz[i] != 0)
    {
        return generisi(niz, i + 1, m);
    }

    while (true)
    {
        niz[i] = sledeciKandidat(niz, i, m);
        if (niz[i] == 0)
        {
            return false;
        }

        /* Ako sledeci rekurzivni poziv vrati false, trazimo sledeci moguci broj i pokusavamo 
        da ga upisemo na tekucu poziciju. Ukoliko nije moguce upisati nijedan broj na tekucu
        poziciju, trenutni rekurzivni poziv vraca false (kao signal prethodnom da izmeni svoj
        izbor broja, ukoliko je to moguce). */
        if (generisi(niz, i + 1, m))
        {
            break;
        }
    }
    // uspeli smo da popunimo polje, vracamo true
    return true;
}

bool potpuniKvadrat(int x)
{
    /* Alternativa je da se unapred izracunaju kvadrati svih
    brojeva od 1 do m i sacuvaju npr. u skup. */
    int koren = (int)sqrt(x);
    return koren * koren == x;
}

bool pravilnoPopunjen(vector<int> &v)
{
    for (int i = 1; i < v.size() - 1; i++)
    {
        if (!potpuniKvadrat(v[i] + v[i - 1]))
        {
            return false;
        }
    }
    return true;
}

int sledeciKandidat(vector<int> &niz, int i, int m)
{
    /* Funkcija na osnovu datih uslova odredjuje prvi sledeci broj
    koji se moze upisati na i-to polje u nizu. */
    for (int k = niz[i] + 1; k <= m; k++)
    {
        // ne moramo da proveravamo da li je iza i-tog elementa nula (tj. prazno polje), jer je to polje sigurno vec popunjeno
        if (potpuniKvadrat(k + niz[i - 1]) && (niz[i + 1] == 0 || potpuniKvadrat(k + niz[i + 1]))) 
        {
            return k;
        }
    }
    return 0;
}

void ispisi(vector<int> &v)
{
    for (int x : v) 
    {
        cout << x << ' ';
    }
    cout << endl;
}