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

    int elemNiza;
    // suma svih elemenata iz intervala [0, t], gde je t indeks trenutnog intervala
    vector<int> postfiknseSume(n);

    cin >> postfiknseSume[0];
    for (int i = 1; i < n; i++)
    {
        cin >> elemNiza;
        postfiknseSume[i] = postfiknseSume[i - 1] + elemNiza;
    }

    // maksimum niza postfiksnih suma u intervalu [i, n)
    vector<int> maxNakonIndeksa(n);
    maxNakonIndeksa[n - 1] = postfiknseSume[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxNakonIndeksa[i] = max(maxNakonIndeksa[i + 1], postfiknseSume[i]);
    }
    
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int upit;
        cin >> upit;

        if (upit == 0)
        {
            cout << maxNakonIndeksa[upit] << '\n';
        }
        else 
        {
            cout << maxNakonIndeksa[upit] - postfiknseSume[upit - 1] << '\n';
        }
    }

    return 0;
}