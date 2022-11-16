#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(begin(a), end(a));

    vector<int> rez(n);

    int i = 0, j = 0; // i prolazi kroz a, a j kroz rez
    while (i < n)
    {
        rez[j] = a[i];
        if (i < n - 1)
        {
            rez[n - 1 - j] = a[++i];
        }

        i++;
        j++;
        /* i se u svakoj iteraciji uvecava za 2, osim u poslednjoj
        i to u slucaju da je n neparno */
    }

    for (int i = 0; i < n; i++)
    {
        cout << rez[i] << '\n';
    }

    return 0;
}