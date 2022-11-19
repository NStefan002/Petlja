#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> glasovi(n);

    for (int i = 0; i < n; i++)
    {
        cin >> glasovi[i];
    }
    
    sort(begin(glasovi), end(glasovi));    

    int maxPonavljanja = 0, trPonavljanja = 1;

    for (int i = 1; i < n; i++)
    {
        if (glasovi[i] == glasovi[i - 1])
        {
            trPonavljanja++;
        }
        else
        {
            maxPonavljanja = max(maxPonavljanja, trPonavljanja);
            trPonavljanja = 1;
        }
    }

    // provera zadnje sekvence ponavljanja
    maxPonavljanja = max(maxPonavljanja, trPonavljanja); 
    
    cout << maxPonavljanja << endl;

    return 0;
}