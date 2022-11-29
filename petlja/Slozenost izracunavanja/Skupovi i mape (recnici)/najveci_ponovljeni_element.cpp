#include <iostream>
#include <set>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> brojevi;

    // uslovom zadatka je odredjeno da ce uneti brojevi biti strogo veci od 0
    int maxPonovljeni = 0;
    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;

        if (brojevi.find(br) != brojevi.end())
        {
            maxPonovljeni = max(maxPonovljeni, br);
        }
        
        brojevi.insert(br);
    }
    
    if (maxPonovljeni == 0)
    {
        cout << "nema" << endl;
    }
    else
    {
        cout << maxPonovljeni << endl;
    }

    return 0;
}