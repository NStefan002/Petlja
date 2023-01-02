#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int maxDuzinaProredjenogPodniza(vector<int> &niz, int d);

int main() 
{
    int n, d;
    cin >> n >> d;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    cout << maxDuzinaProredjenogPodniza(niz, d) << endl;

    return 0;
}

int maxDuzinaProredjenogPodniza(vector<int> &niz, int d)
{
    int maxDuzina = 1;
    int n = niz.size();
    /* U pomocnom nizu cuvamo duzine najduzih podnizova koji se zavrsavaju na i-toj
    poziciji. Za svaki element proveravamo da li mozemo da ga "uparimo" sa nekim od 
    njegovih prethodnika. Ako je to moguce, to znaci da je duzina trenutnog podniza
    (sa zavrsetkom na indeksu i) za jedan veca od duzine najduzeg podniza koji se zavrsava
    na i indeksu j (odnosno na indeksu elementa sa kojim smo "uparili tekuci element"). */
    vector<int> duzinaNajduzegPodniza(n, 1);

    for (int i = 1; i < n; i++)
    {
        // trazimo duzinu najduzeg podniza koji se zavrsava na indeksu i i usput azuriramo maksimum
        for (int j = i - 1; j >= 0; j--)
        {
            if (abs(niz[i] - niz[j]) >= d)
            {
                duzinaNajduzegPodniza[i] = max(duzinaNajduzegPodniza[i], duzinaNajduzegPodniza[j] + 1);
            }           
        }
        maxDuzina = max(maxDuzina, duzinaNajduzegPodniza[i]);
    }
    
    return maxDuzina;
}