#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<string> skupReci(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> skupReci[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        // sortiramo karaktere svakog stringa pojedinacno
        sort(begin(skupReci[i]), end(skupReci[i]));
    }
    

    // sortiramo ceo skup reci
    sort(begin(skupReci), end(skupReci));

    int trVelicinaPodskupa = 1;
    int maxVelicinaPodskupa = 1;

    for (int i = 1; i < n; i++)
    {
        if (skupReci[i] == skupReci[i - 1])
        {
            trVelicinaPodskupa++;
        }
        else
        {
            maxVelicinaPodskupa = max(maxVelicinaPodskupa, trVelicinaPodskupa);
            trVelicinaPodskupa = 1;
        }
    }
    
    cout << maxVelicinaPodskupa << endl;

    return 0;
}