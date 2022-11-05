#include <iostream>


using namespace std;

int main()
{
    unsigned long long mod = (unsigned long long) 1e9;
    unsigned long long n, i;
    cin >> n >> i;

    unsigned long long vrsta, kolona;

    /* 
    kolona = (i + 0*n) + (i + 1*n) + ... + (i + (n - 1)*n)
          = n*i + suma[k = 0 do k = n - 1] (kn)
          [suma izracunata preko formule za zbir prvih n elemenata
          aritmetickog niza, gde je prvi element a_1 = 0, a korak d = n]
          = n*i + n/2 * (2 * 0 + (n - 1) * n)
          = n*i + n/2 * (n - 1) * n
          = n*i + n^2/2 * (n - 1)
          = n (i + n * (n - 1)/2)

    vrsta = (i*n + 0) + (i*n + 1) + ... + (i*n + (n - 1))
          = n * i*n + (0 + 1 + ... + (n - 1))
          = i * n^2 + n * (n - 1)/2 
    */
    
    vrsta = (i * ((n * n) % mod)) % mod + (n * (n - 1) / 2) % mod;
    vrsta %= mod; 

    kolona = n * (i + (n * (n - 1) / 2) % mod) % mod;
    kolona %= mod;
    
    cout << vrsta << '\n' << kolona << endl;
    return 0;
}