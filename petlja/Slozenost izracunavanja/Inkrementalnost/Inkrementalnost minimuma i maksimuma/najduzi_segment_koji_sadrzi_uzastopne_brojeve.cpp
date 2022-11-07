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
    
    int maxDuzina = 0;
    
    for (int i = 0; i < n; i++)
    {
            int minElem = niz[i];
            int maxElem = niz[i];
       for (int duzSegmenta = 2; duzSegmenta < n - i; duzSegmenta++)
       {
            minElem = min(minElem, niz[i + duzSegmenta - 1]);
            maxElem = max(maxElem, niz[i + duzSegmenta - 1]);
            if (maxElem - minElem == duzSegmenta - 1)
            {
                maxDuzina = max(maxDuzina, duzSegmenta);
            }
       }
    }
    
    
    cout << maxDuzina << endl;

    return 0;
}