#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct elementNiza
{
    int vrednost;
    int pozicijaUOrigNizu;

    // da bi funkcija sort znala kako da uporedi dva elementa
    bool operator<(elementNiza e)
    {
        return vrednost < e.vrednost;  
    }
};

int main()
{
    int n;
    cin >> n;

    vector<elementNiza> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i].vrednost;
        niz[i].pozicijaUOrigNizu = i;
    }
    
    /* Sortiramo niz i za svaki element racunamo njegov rang i upisujemo ga
    na originalnu poziciju (pre sortiranja). */
    sort(begin(niz), end(niz));    

    vector<int> rezNiz(n);
    // racunanje ranga i upisivanje u rezultujuci niz
    rezNiz[niz[0].pozicijaUOrigNizu] = 0; // najmanji element u sortiranom nizu ima rang 0
    for (int i = 1; i < n; i++)
    {
        /* Ako se u sortiranom nizu nalazi vise istih vrednosti jedna za drugom, njihov rang je isti 
        (posto se za rang broje samo elementi koji su strogo manji od tekuceg). */
        if (niz[i].vrednost == niz[i - 1].vrednost)
        {
            rezNiz[niz[i].pozicijaUOrigNizu] = rezNiz[niz[i - 1].pozicijaUOrigNizu];   
        }
        else
        {
            rezNiz[niz[i].pozicijaUOrigNizu] = i;
        }
    }
    
    for (int x : rezNiz)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}