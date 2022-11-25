#include <iostream>


using namespace std;

/* Nema potrebe cuvati elemente u niz/vektor pa je 
prostorna slozenost O(1). Vremenska slozenost je O(n). */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int prethodniElement;
    cin >> prethodniElement;

    int ukupanBrRastucih = 0;
    // broj rastucih segmenata sa trenutne pozicije
    int brRastucih = 0;

    for (int i = 1; i < n; i++)
    {
        int trenutniElement;
        cin >> trenutniElement;

        if (trenutniElement > prethodniElement)
        {
            /* tekuci element produzava rastuci segmente koji se zavrsio na
            prethodnoj poziciji i dodaje jos jedan nov dvoclan rastuci segment */
            brRastucih++;
            ukupanBrRastucih += brRastucih;
        }
        else
        {
            brRastucih = 0;
        }
        
        prethodniElement = trenutniElement;
    }
    
    cout << ukupanBrRastucih << endl;

    return 0;
}