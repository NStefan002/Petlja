#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> barKodovi(n);
    for (int i = 0; i < n; i++)
    {
        cin >> barKodovi[i];
    }
    
    int brPostojecih = 0;
    int upit;
    while (cin >> upit)
    {
        // funkcija binary_search vraca true ako pronadje element, u suprotnom false
        if (binary_search(begin(barKodovi), end(barKodovi), upit))
        {
            brPostojecih++;
        }
    }

    cout << brPostojecih << endl;

    return 0;
}