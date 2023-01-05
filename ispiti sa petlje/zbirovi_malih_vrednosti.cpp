#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int64_t pozPrvogVeceg(vector<int64_t> &niz, int64_t upit);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t n;
    cin >> n;

    vector<int64_t> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }
    
    sort(begin(niz), end(niz));
    
    vector<int64_t> sume(n);  
    sume[0] = niz[0];
    for (int64_t i = 1; i < n; i++)
    {
        sume[i] = niz[i] + sume[i - 1];
    }
    
    int64_t q;
    cin >> q;

    for (int64_t i = 0; i < q; i++)
    {
        int64_t upit;
        cin >> upit;

        int64_t poz = pozPrvogVeceg(niz, upit);
        if (poz == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << sume[poz - 1] << '\n';
        }
    }

    return 0;
}

int64_t pozPrvogVeceg(vector<int64_t> &niz, int64_t upit)
{
    /* Ukoliko nijedan element nije strogo veci od upita, funkcija
    ce vratiti poziciju iza poslednje. */
    int64_t l = 0, d = niz.size() - 1;

    while (l <= d)
    {
        int64_t s = l + (d - l)/2;
        if (niz[s] > upit)
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