#include <iostream>
#include <map>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    map<string, int> korisnici;
    // cuvamo koliko korisnika ima sa odredjenim stanjem na racunu
    map<int, int> upiti;
    upiti[0] = k;   // na pocetku svih k korisnika ima 0 na racunu
    string operacija;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> operacija >> x;

        if (operacija == "upit")
        {
            cout << upiti[x] << '\n';
        }
        else
        {
            korisnici[operacija] += x;
            // umanjujemo brojac koji stoji uz prethodno stanje na racunu
            upiti[korisnici[operacija] - x]--;
            // uvecavamo brojac koji stoji uz trenutno stanje na racunu
            upiti[korisnici[operacija]]++;   
        }
    }
    

    return 0;
}