#include <iostream>
#include <set>


using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    set<int> a;
    int brParova = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        // trazimo parnjak trenutnog broja
        // u nizu elemenata koji su ucitani pre njega
        if (a.find(s - x) != a.end())
        {
            brParova++;
        }
        a.insert(x);
    }

    cout << brParova << endl;
    
    return 0;
}