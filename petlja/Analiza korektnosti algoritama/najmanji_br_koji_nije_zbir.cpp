#include <iostream>
#include <vector>

using namespace std;

int najmanji_br_koji_nije_zbir(vector<int>& v);

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    cout << najmanji_br_koji_nije_zbir(v) << '\n';

    return 0;
}

int najmanji_br_koji_nije_zbir(vector<int>& v)
{
    int zbir = v[0];
    if (v[0] > 1)
    {
        return 1;
    }
    
    for (int i = 1; i < v.size(); i++)
    {
        if (zbir + 1 < v[i])
        {
            return zbir + 1;
        }
        
        zbir += v[i];
    }

    return zbir + 1; 
}