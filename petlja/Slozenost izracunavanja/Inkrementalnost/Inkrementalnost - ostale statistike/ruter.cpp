#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n;
    cin >> n;

    vector<uint64_t> zgrade(n);

    for (uint64_t i = 0; i < n; i++)
    {
        cin >> zgrade[i];
    }

    uint64_t levaSuma = 0, desnaSuma = 0;
    uint64_t rastojanje = 0;

    // inicijalizacija prethodne 3 promenljive
    for (uint64_t i = 0; i < n; i++)
    {
        desnaSuma += zgrade[i];
        rastojanje += i * zgrade[i];
    }

    
    uint64_t minRastojanje = rastojanje;
    for (uint64_t i = 1; i < n; i++)
    {
        levaSuma += zgrade[i - 1];
        desnaSuma -= zgrade[i - 1];
        rastojanje += levaSuma - desnaSuma;

        minRastojanje = min(minRastojanje, rastojanje);
    }
    
    cout << minRastojanje << endl;
    
    return 0;
}

/* 
    Z_i - Z_(i-1) = a_0 + a_1 + ... + a_(i-1) - a_i - a_(i+1) - ... - a_(n-1)
                    ________________________levo_i
                                                _____________________________desno_i      

    levo_1 = a_0, desno_1 = a_1 + a_2 + ... + a_(n-1)
    levo_2 = a_0 + a_1, desno_2 = a_2 + ... + a_(n-1)

    levo_i = levo_(i-1) + a_(i-1)
    desno_i = desno_(i-1) - a_(i-1)

    Z_i = Z_(i-1) + levo_i - desno_i
*/