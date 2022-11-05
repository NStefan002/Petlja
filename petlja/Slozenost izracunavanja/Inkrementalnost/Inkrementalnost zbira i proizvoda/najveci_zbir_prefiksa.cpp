#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int stanje = 0;
    int maxStanje = 0;

    for (int i = 0; i < n; i++)
    {
        int transakcija;
        cin >> transakcija;

        stanje += transakcija;
        maxStanje = max(maxStanje, stanje);
    }
    
    cout << maxStanje << endl;

    return 0;
}