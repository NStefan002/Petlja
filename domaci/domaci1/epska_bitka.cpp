#include <iostream>


using namespace std;

/* Vremenska slozenost: O(n)
   Prostorna slozenost: O(1) */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int64_t r, d, x;

    cin >> n >> r >> d;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        x = abs(x); // jer je resenje isto za x = a i x = -a   

        /* Da bi izracunali koliko ce minuta takmicar preziveti potrebno
        je da izracunamo koliko skracivanja za duzinu d ce biti potrebno da
        se poluprecnik smanji za razliku izmedju svoje originalne duzine i
        x ose takmicara. */

        int64_t brMinuta = (x > r)? 0 : (r - x) / d + 1;
        cout << brMinuta << '\n';
    }

    return 0;
}