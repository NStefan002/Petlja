#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int hIndeks(vector<int>& brCitata, int n);

int main()
{
    int n;
    cin >> n;

    vector<int> brCitata(n);

    for (int i = 0; i < n; i++)
    {
        cin >> brCitata[i];
    }
    
    sort(begin(brCitata), end(brCitata));
    
    cout << hIndeks(brCitata, n) << endl;

    return 0;
}

int hIndeks(vector<int>& brCitata, int n)
{
    int i = n - 1, h = n;
    
    while (i >= 0)
    {
        if (n - i - 1 >= h)
        {
            return h;
        }

        if (brCitata[i] >= h)
        {
            i--;
        }
        else
        {
            h--;
        }
    }

    // provera poslednjeg prolaza
    if (n - i - 1 >= h)
    {
        return h;
    }
}