#include <iostream>


using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int l, d;
    if (k == n || n == 0 || n % k == 0)
    {
        l = d = n;
    }
    else if (k < n)
    {
        l = n - (n % k);
        d = n + (k - (n % k));
    }
    else // if (k > n)
    {
        l = -k;
        d = k;
    }

    cout << l << '\n' << d << '\n';

    return 0;
}