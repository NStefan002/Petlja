#include <iostream>

using namespace std;

/* Zadatak moze da se uradi na slican nacin koriscenjem vektora,
ali posto u ovom konkretnom primeru nema potrebe da se cuvaju informacije
o svakoj pojedinacnoj utakmici, trazenje serija mozemo uraditi za vreme ucitavanja. */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int p, k, n;
    cin >> p >> k >> n;

    int tekucaSerija = 0;
    bool imaoSerijuSjajnihPartija = false;
    for (int i = 0; i < n; i++)
    {
        int poeni;
        cin >> poeni;
        if (poeni >= p)
        {
            tekucaSerija++;
            if (tekucaSerija == k)
            {
                imaoSerijuSjajnihPartija = true;
            }
        }
        else
        {
            tekucaSerija = 0;
        }
    }
    
    cout << (imaoSerijuSjajnihPartija? "da" : "ne") << endl;

    return 0;
}