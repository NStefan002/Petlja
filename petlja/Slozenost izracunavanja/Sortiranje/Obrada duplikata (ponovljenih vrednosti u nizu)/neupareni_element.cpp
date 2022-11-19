#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> brojevi(n);

    for (int i = 0; i < n; i++)
    {
        cin >> brojevi[i];
    }
    
    sort(begin(brojevi), end(brojevi));
    
    /* svi brojevi ce biti u paru osim jednog
    takodje mozemo tvrditi da ce se taj jedan broj
    nalaziti na parnom indeksu 
    (jer bi sortirani niz bio oblika aabbxcc, a ne bi
    mogao da bude oblika aabbcxc) */
    for (int i = 0; i < n; i += 2) 
    {
        if (brojevi[i] != brojevi[i + 1])
        {
            cout << brojevi[i] << endl;
            break;
        }
    }

    return 0;
}