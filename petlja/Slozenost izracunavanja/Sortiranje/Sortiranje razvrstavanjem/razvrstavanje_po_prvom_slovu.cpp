#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

struct Djak
{
    string ime;
    string prezime;
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<Djak> djaci;

    string ime, prezime;
    while (cin >> ime >> prezime)
    {
        djaci.push_back({ime, prezime});
    }

    map<string, int> brDjakaPoInicijalima;  // broj djaka sa istim inicijalima
    for (auto& d : djaci)
    {
        string inicijali = "";
        inicijali.insert(begin(inicijali), d.ime[0]);
        inicijali.insert(end(inicijali), d.prezime[0]);
        brDjakaPoInicijalima[inicijali]++;
    } 
    
    map<string, int> indeksiDjaka;
    int brPrethodnih = 0;  
    for (auto& i : brDjakaPoInicijalima)
    {
        indeksiDjaka[i.first] = brPrethodnih;
        brPrethodnih += i.second;
    }
    
    vector<Djak> sortiraniDjaci(djaci.size());
    for (auto& d : djaci)
    {
        string inicijali = "";
        inicijali.insert(begin(inicijali), d.ime[0]);
        inicijali.insert(end(inicijali), d.prezime[0]);
        sortiraniDjaci[indeksiDjaka[inicijali]++] = d;
    }
    
    for (auto& sd : sortiraniDjaci)
    {
        cout << sd.ime << ' ' << sd.prezime << '\n';
    }
    
    return 0;
}