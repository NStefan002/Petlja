#include <iostream>

// na petlji je pogresan 6. test primer tkd. ako su ostali dobri sve je u redu.

using namespace std;

int main()
{
    int n;
    cin >> n;
    unsigned long long fakt = 1;  // 0!

    for (int i = 1; i <= n; i++)
    {
        fakt *= i;
        cout << fakt << '\n';
    }

    return 0;
}