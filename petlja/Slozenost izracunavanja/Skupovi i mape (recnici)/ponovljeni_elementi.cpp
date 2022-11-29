#include <iostream>
#include <set>


using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> skupVidjenih;
    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;

        /* Ukoliko je broj vec vidjen, uklanjamo ga iz skupa,
        a inace ga dodajemo u skup. Ovim postupkom ce nam na kraju
        skup imati samo jedan element koji predstavlja nase resenje. */
        if (skupVidjenih.find(br) != skupVidjenih.end())
        {
            skupVidjenih.erase(br);
        }
        else
        {
            skupVidjenih.insert(br);
        }
    }
    
    cout << *begin(skupVidjenih) << endl;

    return 0;
}