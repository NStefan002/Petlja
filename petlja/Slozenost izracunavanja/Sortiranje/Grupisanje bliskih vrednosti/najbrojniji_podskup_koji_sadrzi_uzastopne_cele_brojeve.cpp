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

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(begin(a), end(a));
    
    int poslednjiIndeksBezDuplikata = unique(begin(a), end(a)) - begin(a);
    int maxPocetak = 0, maxKraj = 1, maxDuzina = 1;
    // rezultat ce biti elementi niza iz [maxPocetak, maxKraj)

    int l = 0, d = 1;
    // posmatramo i pomeramo segment [l, d]
    while (d < poslednjiIndeksBezDuplikata)
    {
        if (a[d] != a[d - 1] + 1)
        {
            l = d;
        }

        if (maxDuzina < d - l + 1)
        {
            maxDuzina = d - l + 1;
            maxPocetak = l;
            maxKraj = d + 1;
        }

        d++;
    }
    
    for (int i = maxPocetak; i < maxKraj; i++)
    {
        cout << a[i] << '\n';
    }
    
    return 0;
}