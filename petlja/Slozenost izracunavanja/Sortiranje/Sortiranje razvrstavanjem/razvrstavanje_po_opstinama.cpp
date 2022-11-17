#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;


struct Takmicar
{
    string opstina;
    string sifra;
};

/* Vremenska slozenost zakomentarisanog koda je O(nlogn) ako grubo
procenimo da je poredjenje dva stringa konstantne slozenosti.
   Vremenska slozenost koda ispod zakomentarisanog dela je O(nlogm) [m je broj opstina, 
a n broj tamkicara], sto je priblizno O(n). U realnoj situaciji je n znatno vece
od m, pa mozemo da kazemo da je vreme pristupa elementu recnika (logm) konstantno, uz
to uzmimo grubu procenu da je poredjenje dva stringa konstante slozenosti (jer se vecina
tih poredjenja zavrsava posle prvog karaktera, odnosno najgori slucajevi su jako retki), 
pa iz toga dobijamo da je ukupna slozenost priblizno O(n) sto je malo bolje od zakomentarisanog
dela koda (ali vrlo su slicni). */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<Takmicar> takmicari;
    string s;
    while (getline(cin, s))
    {
        if (s == "")    // ako je uneta prazna linija
        {
            break;
        }
        
        int pocetakSifre = s.find('\t'); // sifra pocinje nakon taba
        string opstina = s.substr(0, pocetakSifre);
        string sifra = s.substr(pocetakSifre + 1);
        
        takmicari.push_back({opstina, sifra});
    }

    /* stable_sort(begin(takmicari), end(takmicari),
    [] (const Takmicar& t1, const Takmicar& t2)
    {
        if (t1.opstina < t2.opstina)
        {
            return true;
        }
        else
        {
            return false;
        }
    });


    cout << takmicari[0].opstina << ": " << takmicari[0].sifra;
    for (int i = 1; i < takmicari.size(); i++)
    {
        if (takmicari[i].opstina == takmicari[i - 1].opstina)
        {
            cout << ", " << takmicari[i].sifra;
        }
        else
        {
            cout << '\n' << takmicari[i].opstina << ": " << takmicari[i].sifra;
        }
    }

    cout << endl; */   

    // ili:
    map<string, int> brTakmicaraPoOpstini;
    for (auto& t : takmicari)
    {
        brTakmicaraPoOpstini[t.opstina]++;
    }

    /* izracunavamo poziciju u sortiranom nizu na kojoj
    pocinju takmicari sa date opstine */
    map<string, int> pozicije;
    int prethodnoTakmicara = 0;

    for (auto& i : brTakmicaraPoOpstini)
    {
        pozicije[i.first] = prethodnoTakmicara; // i.first pristupa imenu opstine u recniku
        prethodnoTakmicara += i.second; // i.second pristupa broju takmicara iz date opstine
    }
    
    vector<Takmicar> sortiraniTakmicari(takmicari.size());
    /* sortiramo upisivanjem u pomocni niz */
    for (auto& t : takmicari)
    {
        sortiraniTakmicari[pozicije[t.opstina]++] = t;  // uvecavamo pozicije da bi
        // sledeci takmicar iz te opstine bio postavljen na svoje mesto u sortiranom nizu
    }
    
    cout << sortiraniTakmicari[0].opstina << ": " << sortiraniTakmicari[0].sifra;
    for (int i = 1; i < sortiraniTakmicari.size(); i++)
    {
        if (sortiraniTakmicari[i].opstina == sortiraniTakmicari[i - 1].opstina)
        {
            cout << ", " << sortiraniTakmicari[i].sifra;
        }
        else
        {
            cout << '\n' << sortiraniTakmicari[i].opstina << ": " << sortiraniTakmicari[i].sifra;
        }
    }
    cout << endl;
    
    return 0;
}