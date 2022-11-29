#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }
    
    unsigned t;
    cin >> t;

    sort(begin(niz), end(niz));

    int brParova = 0;
    for (int i = 0; i < n; i++)
    {
        if (binary_search(begin(niz), end(niz), niz[i] ^ t))
        {
            brParova++;
        }
    }
    
    // brParova/2 jer je par (i, j) isto sto i par (j, i)
    cout << brParova/2 << endl;
    
    return 0;
}