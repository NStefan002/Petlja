#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> niz(n);

    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }
    
    sort(begin(niz), end(niz));

    int i;
    for (i = n - 1; i > 0; i--)
    {
        if (niz[i] == niz[i - 1])
        {
            /* prvi duplikat koji pronadjemo
            (gledajuci sa kraja sortiranog niza) je 
            ujedno i najveci duplikat (zbog cinjenice
            da je niz sortiran neopadajuce) */
            cout << niz[i] << endl;
            break;
        }
    }
    
    if (i == 0)
    {
        cout << "nema" << endl;
    }
    
    return 0;
}