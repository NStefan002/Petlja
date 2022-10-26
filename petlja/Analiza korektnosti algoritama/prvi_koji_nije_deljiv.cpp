#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

int broj_deljivih(vector<long long>& v, long long delilac);

int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(0);
    // stopira izlaz dok ne dodje do kraja ulaza

    int n;
    cin >> n;
    vector<long long> v(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    long long delilac;
    while (cin >> delilac)
    {
        cout << broj_deljivih(v, delilac) << '\n';
    }

    return 0;
}

int broj_deljivih(vector<long long>& v, long long delilac)
{
    int l, d;
    l = 0;
    d = v.size()-1;

    while (l <= d)
    {
        int s = l + (d - l)/2;

        if (v[s] % delilac != 0)
        {
            d = s - 1; 
        }
        else
        {
            l = s + 1;
        }
    }

    return l;
}