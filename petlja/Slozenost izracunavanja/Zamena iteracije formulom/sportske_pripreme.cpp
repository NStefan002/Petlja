#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned n, a, d;
    cin >> n;

    /* 
    a + (a + d) + (a + 2d) + ... + (a + (n - 1)*d) = 
    n*a + (0 + 1 + 2 + ... + n-1) =
    n*a + n*(n - 1)/2 * d = 
    n * (a + d * (n - 1)/2) 
    */

    while (cin >> a >> d)
    {
        double rez = n * (a + d * (double)(n - 1)/2);
        rez /= 1000;    // m -> km

        cout << fixed << setprecision(2) << showpoint << rez << '\n';
    }


    return 0;
}