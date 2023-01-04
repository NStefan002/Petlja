#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> lokacije(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lokacije[i];
    }
    
    int d;
    cin >> d;

    sort(begin(lokacije), end(lokacije));

    // prvi pomeramo duz x ose, pa po potrebi pomeramo drugog za njim
    int pozicijaPrvog = 0, pozicijaDrugog = 0;
    int maxRazdaljina = 0;

    while (pozicijaPrvog < n)
    {   
        int razdaljina = lokacije[pozicijaPrvog] - lokacije[pozicijaDrugog];
        if (razdaljina > d)
        {
            pozicijaDrugog++;   // pomerimo drugog ka prvom
        }
        else
        {
            maxRazdaljina = max(maxRazdaljina, razdaljina);
            pozicijaPrvog++;
        }
    }   

    cout << maxRazdaljina << endl;

    return 0;
}