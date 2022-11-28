#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    vector<int> niz(n);

    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }
    
    // sortiramo niz da bismo mogli da koristimo binarnu pretragu
    sort(begin(niz), end(niz));

    int brParova = 0;
    for (int i = 0; i < n; i++)
    {
        // za broj k trazimo njegov parnjak s-k
        if (binary_search(begin(niz), end(niz), s - niz[i]))
        {
            brParova++;
        }
    }
    
    // brParova/2 jer su parovi (i, j) i (j, i) isti
    cout << brParova/2 << endl;

    return 0;
}