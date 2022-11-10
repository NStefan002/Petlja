#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int tekucaSerija = 0;
    int maxSerija = 0;
    for (int i = 0; i < n; i++)
    {
        int p_p; // pobeda/poraz
        cin >> p_p;
        if (p_p == 1)
        {
            tekucaSerija++;
        }
        else
        {
            maxSerija = max(maxSerija, tekucaSerija);
            tekucaSerija = 0;
        }
    }
    // ispitivanje duzine poslednje serije
    maxSerija = max(maxSerija, tekucaSerija);
    
    cout << maxSerija << endl;

    return 0;
}