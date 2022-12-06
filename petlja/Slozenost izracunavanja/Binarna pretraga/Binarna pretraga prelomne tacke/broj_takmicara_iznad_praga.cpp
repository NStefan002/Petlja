#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int brPlasiranih(vector<int>& poeni, int prag);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> poeni(n);
    for (int i = 0; i < n; i++)
    {
        cin >> poeni[i];
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int pitanje;
        cin >> pitanje;
        cout << brPlasiranih(poeni, pitanje) << '\n';
    }

    return 0;
}

int brPlasiranih(vector<int>& poeni, int prag)
{
    int l = 0, d = poeni.size() - 1;

    while (l <= d)
    {
        int s = l + (d - l) / 2;

        if (poeni[s] >= prag)
        {
            l = s + 1;
        }
        else
        {
            d = s - 1;
        }
    }

    return l;
}