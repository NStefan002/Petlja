#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> kolicina(n);
    for (int i = 0; i < n; i++)
    {
        cin >> kolicina[i];
    }
    
    int t;
    cin >> t;

    // posmatramo zbir kolicina iz intervala [l, d)
    int l = 0, d = 0, zbir = 0;
    int maxKajmak = 0;

    while (d < n)
    {
        zbir += kolicina[d++];
        
        while (zbir >= t)
        {
            zbir -= kolicina[l++];
        }

        maxKajmak = max(maxKajmak, zbir);
    }

    cout << maxKajmak << endl;

    return 0;
}