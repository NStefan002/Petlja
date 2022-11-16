#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    uint64_t mod = 1ull << 32; // 2^32
    
    int n;
    uint64_t c0, c1;
    cin >> n >> c0 >> c1;

    vector<uint64_t> a(n);
    cin >> a[0];
    a[0] %= mod;
    
    
    for (int i = 1; i < n; i++)
    {
        a[i] = ((a[i - 1] * c0) % mod + c1) % mod;
    }
    
    sort(begin(a), end(a));

    if (n % 2 == 1)
    {
        cout << fixed << setprecision(2) << showpoint << (long double)a[(n - 1) / 2];
    }
    else
    {
        cout << fixed << setprecision(2) << showpoint << (long double)(a[n / 2 - 1] + a[n / 2]) / 2 << endl;
    }    

    return 0;
}