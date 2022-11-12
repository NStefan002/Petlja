#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    /* Pravimo pomocni niz od n+1 elemenata. Na indeksima od 0 do n-1 pamtimo
    koliko ima clanaka kojima je broj citata jednak indeksu pomocnog niza. Na 
    indeksu n pamtimo koliko ima clanaka sa brojem citata koji je veci ili jednak
    od ukupnog broja clanaka (n) */
    vector<int> citati(n + 1, 0);
    int brCitata;
    for (int i = 0; i < n; i++)
    {
        cin >> brCitata;
        citati[(brCitata >= n)? n : brCitata]++;
    }
    
    int rez = -1;
    /* brih clanaka sa vise od k citata je suma[j = k do j = n](j), gde 
    je n poslednji indeks u pomocnom nizu */
    int zbirBrojaCitata = 0;
    for (int hIndeks = n; hIndeks >= 0; hIndeks--)
    {
        zbirBrojaCitata += citati[hIndeks];
        if (zbirBrojaCitata >= hIndeks)
        {
            rez = hIndeks;
            break;
        }
    }
    
    cout << rez << endl;

    return 0;
}