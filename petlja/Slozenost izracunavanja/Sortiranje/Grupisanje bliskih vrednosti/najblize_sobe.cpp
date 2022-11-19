#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> sobe(n);

    for (int i = 0; i < n; i++)
    {
        cin >> sobe[i];
    }
    
    sort(begin(sobe), end(sobe));
    
    int minRastojanje = sobe[n - 1] - sobe[n - 2];
    int soba1 = sobe[n - 2], soba2 = sobe[n - 1];

    // prolazimo sobe s kraja jer se trazi da sobe budu sto dalje od recepcije
    for (int i = n - 2; i > 0; i--)
    {
        if (minRastojanje > sobe[i] - sobe[i - 1])
        {
            minRastojanje = sobe[i] - sobe[i - 1];
            soba1 = sobe[i - 1];
            soba2 = sobe[i];
        }
    }
    
    cout << soba1 << ' ' << soba2 << endl;

    return 0;
}