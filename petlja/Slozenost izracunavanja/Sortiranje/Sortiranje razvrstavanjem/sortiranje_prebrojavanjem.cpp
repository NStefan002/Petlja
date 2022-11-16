#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    vector<int> brojaci(m, 0); /* niz koji na i-toj poziciji
    cuva broj pojavljivanja broja i */

    for (auto i : a)
    {
        brojaci[i]++;
    }
    
    
    // "sortiramo" niz a direktnim upisivanjem elemenata i ispisujemo ga
    for (int i = 0, j = 0; i < m; i++)
    {
        while (brojaci[i] > 0)
        {
            a[j] = i;
            cout << a[j] << '\n';
            j++;
            brojaci[i]--;
        }
    }
    

    return 0;
}