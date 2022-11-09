#include <iostream>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned n, a, d;
    cin >> n;

    /* 
    ukupna metraza za n dana treninga:
    a + (a + d) + (a + 2d) + ... + (a + (n - 1)*d) = 
    n*a + (0 + 1 + 2 + ... + n-1) =
    n*a + n*(n - 1)/2 * d = 
    n * (a + d * (n - 1)/2) 

    ukupna metraza za n-1 dan treninga:
    (n - 1) * (a + d * (n - 2)/2)

    metraza za poslednji dan treninga:
        ukupna metraza - metraza bez poslednjeg dana = 
        d * (n - 1) + a
    */

    while (cin >> a >> d)
    {
        unsigned rez = d * (n - 1) + a;

        cout << rez << '\n';
    }


    return 0;
}