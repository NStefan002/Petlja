#include <iostream>
#include <iomanip>

using namespace std;

/* U zadatku je greska, prva dva test primera zaokruzuje na 15 decimala,
   kod je ok. */

int main()
{
    int n;
    cin >> n;
    
    double fakt = 1;
    double znak = -1;
    double verovatnoca = 1;

    for (int i = 1; i <= n; i++)
    {
        fakt *= i;
        verovatnoca += znak / fakt;
        znak *= -1;
    }
    
    cout << fixed << setprecision(14) << showpoint << verovatnoca << endl;

    return 0;
}